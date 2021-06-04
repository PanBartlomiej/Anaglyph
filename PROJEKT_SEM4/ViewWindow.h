#pragma once

#include <iostream>
//TODO: remove

#include <SFML/Graphics.hpp>
#include "MatrixParallelMultiplier.h"
#include "wec.h"
#include "structures.h"
#include "SphereMaker.h"
#include "SectionMaker.h"
#include <cmath>

class ViewWindow
{
    public:
        ViewWindow(const int width = 800, const int height = 650, const char* title = "View window");
        
        ~ViewWindow();
        
        bool processMessages();
        
        void heartBeat();
        
        bool closeEvent(sf::Event& event);
        bool mouseDownEvent(sf::Event& event);
        bool mouseUpEvent(sf::Event& event);
        bool mouseMoveEvent(sf::Event& event);
        bool mouseScrollEvent(sf::Event& event);
        
        void setData(const std::vector<Section>& newData);

        void setEyeFocus(double focus);

        void setEyeDistance(double distance);

        void Update(const Matrix4& wxTranslation, const Matrix4& wxRotation);
        
        void SaveToFile(const std::string& fileName, const unsigned int width = 1280, const unsigned int height = 1080, const bool windowProportion = true) const;

        void setColors(int r1, int g1, int b1, int r2, int g2, int b2);

        void UpdateEyeMatrixes();

        
        double zoom;
        double eyeDistance, eyeTarget;
        double rotationDentisy, rotationResistance;
        
        void Render(); //wykonać po każdej zmianie zmiennych!

        sf::Vector2u getSize() const;
    private:
        sf::RenderWindow window;
        sf::VertexArray rightVertexArray;
        sf::VertexArray leftVertexArray;
        int _width, _height;
        bool mouseButtonIsDown;
        int mousePositionX, mousePositionY;
        ParallerMultiplier multipliers;
        
        Point center;
        Matrix4 translationMatrix, rotationMatrix, mainMatrix;
        double rotationSpeedX, rotationSpeedY;
        
        
        void RenderTo(sf::RenderTarget& target, const bool windowProportion = false) const;
        void HandleEvents();
        void paint();
        
};

