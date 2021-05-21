#include "ViewWindow.h"

#include <iostream>
//TODO: remove

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
    //rysowanie
    RenderTo(window);
    
    window.display();
}

void ViewWindow::setData(const std::vector<Section>& newData)
{
    multipliers.vertexArrayLeft = &leftVertexArray;
    multipliers.vertexArrayRight = &rightVertexArray;
    multipliers.sections = &newData;
    //TODO: matrix
    multipliers.calculate();
}

void ViewWindow::RenderTo(sf::RenderTarget& target)
{
    window.clear(sf::Color::Black);
    target.setView(sf::View(sf::FloatRect(-4, -3, 8, 6)));
    target.draw(leftVertexArray);
    target.draw(rightVertexArray);
}
