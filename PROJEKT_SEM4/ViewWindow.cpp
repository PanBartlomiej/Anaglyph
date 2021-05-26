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
        heartBeat();
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
        mouseDownEvent(event);
        mouseUpEvent(event);
        mouseMoveEvent(event);
        mouseScrollEvent(event);
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

bool ViewWindow::mouseDownEvent(sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        mouseButtonIsDown = true;
        return true;
    }
    return false;
}

bool ViewWindow::mouseUpEvent(sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonReleased)
    {
        mouseButtonIsDown = false;
        return true;
    }
    return false;
}

bool ViewWindow::mouseMoveEvent(sf::Event& event)
{
    if (event.type == sf::Event::MouseMoved)
    {
        if (mouseButtonIsDown)
        {
            rotationSpeedX = event.mouseMove.x-mousePositionX;
            rotationSpeedY = event.mouseMove.y-mousePositionY;
        }
        
        mousePositionX = event.mouseMove.x;
        mousePositionY = event.mouseMove.y;
        return true;
    }
    return false;
}

bool ViewWindow::mouseScrollEvent(sf::Event& event)
{
    if (event.type == sf::Event::MouseWheelScrolled)
    {
        zoom *= pow(0.9, event.mouseWheelScroll.delta);
        return true;
    }
    return false;
}

void ViewWindow::UpdateEyeMatrixes()
{
    double a = 1.570796326794897-atan2(eyeTarget, eyeDistance/2);
    multipliers.leftMatrix = CreateMoveMatrix(eyeDistance/2, 0, 0) * CreateRotationMatrix(a, 1) * mainMatrix;
    multipliers.rightMatrix = CreateMoveMatrix(-eyeDistance/2, 0, 0) * CreateRotationMatrix(-a, 1) * mainMatrix;
}

void ViewWindow::paint()
{
    RenderTo(window);    
    window.display();
}

void ViewWindow::Render()
{
    UpdateEyeMatrixes();
    multipliers.calculate();
}

void ViewWindow::Update(const Matrix4& wxTranslation, const Matrix4& wxRotation) 
{
    translationMatrix = wxTranslation;
    rotationMatrix = wxRotation;
    Render();
}

void ViewWindow::setData(const std::vector<Section>& newData)
{
    multipliers.vertexArrayLeft = &leftVertexArray;
    multipliers.vertexArrayRight = &rightVertexArray;
    multipliers.sections = &newData;
    
    UpdateEyeMatrixes();
    multipliers.asyncCalculate();
    
    Point min, max;
    for (auto s : newData)
    {
        max.x = std::max(std::max(s.begin.x, s.end.x), center.x);
        max.y = std::max(std::max(s.begin.y, s.end.y), center.y);
        max.z = std::max(std::max(s.begin.z, s.end.z), center.z);
        min.x = std::min(std::min(s.begin.x, s.end.x), center.x);
        min.y = std::min(std::min(s.begin.y, s.end.y), center.y);
        min.z = std::min(std::min(s.begin.z, s.end.z), center.z);
    }
    center = (min+max)*0.5;
    
    multipliers.wait();
}

void ViewWindow::heartBeat()
{
    rotationMatrix = CreateRotationMatrix(-rotationSpeedX/rotationDentisy, 1) * CreateRotationMatrix(rotationSpeedY/rotationDentisy, 0) * rotationMatrix;
    mainMatrix = translationMatrix * CreateMoveMatrix(center.x, center.y, center.z) * rotationMatrix * CreateMoveMatrix(-center.x, -center.y, -center.z);
 
    rotationSpeedX *= rotationResistance;
    rotationSpeedY *= rotationResistance;
    
    if (fabs(rotationSpeedX) < 0.01)
        rotationSpeedX = 0;
    if (fabs(rotationSpeedY) < 0.01)
        rotationSpeedY = 0;
    
    if (rotationSpeedX != 0 && rotationSpeedY != 0)    
        Render();
}

void ViewWindow::SaveToFile(const std::string& fileName, const unsigned int width, const unsigned int height) const
{
    sf::RenderTexture renderTexture;
    renderTexture.create(width, height);
    RenderTo(renderTexture);
    sf::Image image = renderTexture.getTexture().copyToImage();
    image.flipVertically();
    image.saveToFile(fileName);
}

void ViewWindow::RenderTo(sf::RenderTarget& target) const
{
    target.clear(sf::Color::Black);
    auto size = target.getSize();
    double k = (double)size.x/size.y;
    
    target.setView(sf::View(sf::FloatRect(-zoom/2*k, -zoom/2, zoom*k, zoom)));
    
    auto state = sf::RenderStates::Default;
    state.blendMode = sf::BlendMode(sf::BlendMode::Factor::One, sf::BlendMode::Factor::One, sf::BlendMode::Equation::Add);
    
    target.draw(leftVertexArray, state);
    target.draw(rightVertexArray, state);
}
