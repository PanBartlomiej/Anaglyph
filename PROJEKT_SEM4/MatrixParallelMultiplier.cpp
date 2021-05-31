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
            sf::sleep(sf::milliseconds(1)); //opóźnienie w stanie jałowym
    }
}

ParallerMultiplier::ParallerMultiplier(const unsigned int threadCount) : leftColor(sf::Color::Red), rightColor(sf::Color::Blue), _threadCount(threadCount), calcID(0), _terminating(false), cameraDepth(1.732050807568877), leftMatrix(IdentityMatrix()), rightMatrix(IdentityMatrix())
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
    if (sections)
    {
        Vector4 c;
        const Section& s = sections->at(index);
        if (vertexArrayLeft)
        {
            c = leftMatrix * Vector4(s.begin.x, s.begin.y, s.begin.z);
            c.data[2] = fabs(c.data[2]+cameraDepth)+1e-9;
            (*vertexArrayLeft)[(index << 1)] = sf::Vertex(sf::Vector2f(cameraDepth*c.data[0]/c.data[2], cameraDepth*c.data[1]/c.data[2]), leftColor);
            c = leftMatrix * Vector4(s.end.x, s.end.y, s.end.z);
            c.data[2] = fabs(c.data[2]+cameraDepth)+1e-9;
            (*vertexArrayLeft)[(index << 1)+1] = sf::Vertex(sf::Vector2f(cameraDepth*c.data[0]/c.data[2], cameraDepth*c.data[1]/c.data[2]), leftColor);
        }
        if (vertexArrayRight)
        {
            c = rightMatrix * Vector4(s.begin.x, s.begin.y, s.begin.z);
            c.data[2] = fabs(c.data[2]+cameraDepth)+1e-9;
            (*vertexArrayRight)[(index << 1)] = sf::Vertex(sf::Vector2f(cameraDepth*c.data[0]/c.data[2], cameraDepth*c.data[1]/c.data[2]), rightColor);
            c = rightMatrix * Vector4(s.end.x, s.end.y, s.end.z);
            c.data[2] = fabs(c.data[2]+cameraDepth)+1e-9;
            (*vertexArrayRight)[(index << 1)+1] = sf::Vertex(sf::Vector2f(cameraDepth*c.data[0]/c.data[2], cameraDepth*c.data[1]/c.data[2]), rightColor);
        }
    }
}

bool ParallerMultiplier::Done() const
{
    for (unsigned int i = 0;i<_threadCount;i++)
        if (!doneStatus[i])
            return false;
    return true;
}

void ParallerMultiplier::asyncCalculate()
{
    vertexArrayLeft->resize(2*sections->size());
    vertexArrayRight->resize(2*sections->size());
    for (unsigned int i = 0;i<_threadCount;i++)
        doneStatus[i] = false;
    calcID++;
    wait();
}

void ParallerMultiplier::calculate()
{
    asyncCalculate();
    wait();
}

void ParallerMultiplier::setColors(const sf::Color& c1, const sf::Color& c2)
{
    leftColor = c1;
    rightColor = c2;
}