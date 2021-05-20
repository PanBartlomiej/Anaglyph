#pragma once

#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "structures.h"
#include "wec.h"


class ParallerMultiplier;

class SingleMultiplier
{
    public:
        SingleMultiplier(const unsigned int id,  ParallerMultiplier& manager) : _id(id), _manager(manager), doneID(0) {}
        void operator()();
    private:
        unsigned int _id;
        ParallerMultiplier& _manager;
        unsigned int doneID;
};

class ParallerMultiplier
{
    public:
        ParallerMultiplier(const unsigned int threadCount = 8);
        ~ParallerMultiplier();        
        void MultiplePoint(unsigned int index);
        bool Done() const;
        void calculate();
        
        inline unsigned int getCalcID() const
        {
            return calcID;
        }
        
        inline bool Terminating() const 
        {
            return _terminating;
        }
        
        inline unsigned int getPointCount() const
        {
            return 8;
        }
        
        inline unsigned int getThreadCount() const
        {
            return _threadCount;
        }
        
        inline void wait() const
        {
            while (!Done())
                sf::sleep(sf::milliseconds(1));
        }
        
        
        inline bool& DoneStatus(const unsigned int id)
        {
            return doneStatus[id];
        }
        
        Matrix4 leftMatrix;
        Matrix4 rightMatrix;
        sf::VertexArray* vertexArrayLeft;
        sf::VertexArray* vertexArrayRight;
        std::vector<Section>* sections;
        double cameraDepth;
    private:
        const unsigned int _threadCount;
        bool* doneStatus;
        std::vector<sf::Thread*> _threads;
        unsigned int calcID;
        bool _terminating;
    
        
};
