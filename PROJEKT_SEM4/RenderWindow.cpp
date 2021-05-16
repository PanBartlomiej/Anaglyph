#include "RenderWindow.h"


RenderWindow::~RenderWindow()
{
    window.close();
}

bool RenderWindow::processMessages()
{
    if (window.isOpen())
    {
        processEvents();
        
        paint();
        return true;
    }
    else return false;
}
        
void RenderWindow::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        closeEvent(event);
        //obsługa reszty komunikatów
    }
}

//przykładowy komunikat
bool RenderWindow::closeEvent(sf::Event& event)
{
    if (event.type == sf::Event::Closed)
    {
        window.close();
        return true;
    }
    return false;
}

void RenderWindow::paint()
{
    window.clear(sf::Color::Black);
    //rysowanie
    window.display();
}
