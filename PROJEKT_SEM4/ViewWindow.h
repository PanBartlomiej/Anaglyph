#pragma once

#include <SFML/Graphics.hpp>
#include "MatrixParallelMultiplier.h"
#include "wec.h"
#include "structures.h"
#include "SphereMaker.h"

class ViewWindow
{
    public:
        ViewWindow(const int width = 800, const int height = 650, const char* title = "View window") : window(sf::VideoMode(width, height), title), _width(width), _height(height), mouseButtonIsDown(false), rightVertexArray(sf::Lines), leftVertexArray(sf::Lines){};
        
        ~ViewWindow();
        
        bool processMessages();
        
        bool closeEvent(sf::Event& event);
        
        
        //
        //display figures on window
        //
        void paint();
        
        //
        //set data for future figure building
        //
        void setData(const std::vector<Section>& newData);

        //
        //create figures
        //
        void Update(const Matrix4& wxTranslation, const Matrix4& wxRotation) {};

        //
        //HandleEvents
        //
        void HandleEvents();
        
        //
        //Save current frame to file jpg
        //
        void SaveToFile() const {};

            
        
    private:
        sf::RenderWindow window;
        sf::VertexArray rightVertexArray;
        sf::VertexArray leftVertexArray;
        int _width, _height;
        bool mouseButtonIsDown;
        ParallerMultiplier multipliers;
        
        void RenderTo(sf::RenderTarget& target);
        
};

