#include "MatrixParallelMultiplier.h"

void SingleMultiplier::operator()()
{
    while (! _manager.Terminating())
    {
        if (doneID != _manager.getCalcID())
        {
            _manager.DoneStatus(_id) = false;
            for (unsigned int i=_id;i<_manager.getPointCount();i+=_manager.getThreadCount())
                _manager.MultiplePoint(i);
            doneID = _manager.getCalcID();
            _manager.DoneStatus(_id) = true;
        }
        else
            sf::sleep(sf::milliseconds(3)); //opóźnienie w stanie jałowym
    }
}

ParallerMultiplier::ParallerMultiplier(const unsigned int threadCount) : _threadCount(threadCount), calcID(0), _terminating(false), cameraDepth(100)
{
    doneStatus = new bool[threadCount];
    for (unsigned int i=0;i<threadCount;i++)
    {
        sf::Thread* tmp = new sf::Thread(SingleMultiplier(i, *this));
        tmp->launch();
        _threads.push_back(tmp);
    }
}

ParallerMultiplier::~ParallerMultiplier()
{
    _terminating = true;
    for (auto t : _threads)
    {
        t->wait();
        delete t;
    }
    delete [] doneStatus;
}

void ParallerMultiplier::MultiplePoint(unsigned int index)
{
    if (vertexArrayLeft && vertexArrayRight && sections)
    {
        Section& s = sections->at(index);

        Vector4 c = leftMatrix * Vector4(s.begin.x, s.begin.y, std::max(1e-9, s.begin.z));
        (*vertexArrayLeft)[index] = sf::Vertex(sf::Vector2f(cameraDepth*c.data[0]/c.data[2], cameraDepth*c.data[1]/c.data[2]));
        
        c = leftMatrix * Vector4(s.end.x, s.end.y, std::max(1e-9, s.end.z));
        (*vertexArrayRight)[index] = sf::Vertex(sf::Vector2f(cameraDepth*c.data[0]/c.data[2], cameraDepth*c.data[1]/c.data[2]));
    }
}

bool ParallerMultiplier::Done() const
{
    for (unsigned int i = 0;i<_threadCount;i++)
        if (!doneStatus[i])
            return false;
    return true;
}

void ParallerMultiplier::calculate()
{
    vertexArrayLeft->resize(2*sections->size());
    vertexArrayRight->resize(2*sections->size());
    for (unsigned int i = 0;i<_threadCount;i++)
        doneStatus[i] = false;
    calcID++;
    wait();
}