#pragma once

#include <SFML/Graphics.hpp>


class RenderWindow
{
    public:
        RenderWindow(const int width = 800, const int height = 650, const char* title = "Render window") : window(sf::VideoMode(width, height), title), _width(width), _height(height), mouseButtonIsDown(false) {};
        
        ~RenderWindow();
        
        bool processMessages();
        
        void processEvents();
        
        bool closeEvent(sf::Event& event);
        void paint();
        
    private:
        sf::RenderWindow window;
        int _width, _height;
        bool mouseButtonIsDown;
    
};
