#include "ViewWindow.h"


ViewWindow::~ViewWindow()
{
    window.close();
}

bool ViewWindow::processMessages()
{
    if (window.isOpen())
    {
        HandleEvents();
        
        paint();
        return true;
    }
    else return false;
}
        
void ViewWindow::HandleEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        closeEvent(event);
        //obsługa reszty komunikatów
    }
}

//przykładowy komunikat
bool ViewWindow::closeEvent(sf::Event& event)
{
    if (event.type == sf::Event::Closed)
    {
        window.close();
        return true;
    }
    return false;
}

void ViewWindow::paint()
{
    window.clear(sf::Color::Black);
    //rysowanie
    window.display();
}
