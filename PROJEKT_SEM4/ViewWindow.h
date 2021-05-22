#pragma once

#include <SFML/Graphics.hpp>
#include "MatrixParallelMultiplier.h"
#include "wec.h"
#include "structures.h"
#include "SphereMaker.h"

class ViewWindow
{
    public:
        ViewWindow(const int width = 800, const int height = 650, const char* title = "View window") : window(sf::VideoMode(width, height), title), _width(width), _height(height), mouseButtonIsDown(false), rightVertexArray(sf::Lines), leftVertexArray(sf::Lines), zoom(6), eyeDistance(0.1), eyeTarget(5), rotationDentisy(100), rotationResistance(0.99), rotationMatrix(IdentityMatrix()), mainMatrix(IdentityMatrix()) {};
        
        ~ViewWindow();
        
        bool processMessages();
        
        void heartBeat();
        
        bool closeEvent(sf::Event& event);
        bool mouseDownEvent(sf::Event& event);
        bool mouseUpEvent(sf::Event& event);
        bool mouseMoveEvent(sf::Event& event);
        bool mouseScrollEvent(sf::Event& event);
        
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
        
        
        void UpdateEyeMatrixes();
        
        double zoom;
        double eyeDistance, eyeTarget;
        
        double rotationDentisy, rotationResistance;
    private:
        sf::RenderWindow window;
        sf::VertexArray rightVertexArray;
        sf::VertexArray leftVertexArray;
        int _width, _height;
        bool mouseButtonIsDown;
        int mousePositionX, mousePositionY;
        ParallerMultiplier multipliers;
        
        Point center;
        Matrix4 rotationMatrix, mainMatrix;
        double rotationSpeedX, rotationSpeedY;
        
        
        void RenderTo(sf::RenderTarget& target);
        
};

