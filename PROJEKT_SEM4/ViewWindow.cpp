#include "ViewWindow.h"

ViewWindow::ViewWindow(const int width, const int height, const char* title) 
    : window(sf::VideoMode(width, height), title), _width(width), _height(height), 
    mouseButtonIsDown(false), 
    rightVertexArray(sf::Lines), 
    leftVertexArray(sf::Lines), 
    zoom(6), eyeDistance(0.1), 
    eyeTarget(6), 
    rotationDentisy(100), 
    rotationResistance(0.99), 
    translationMatrix(IdentityMatrix()), 
    rotationMatrix(IdentityMatrix()), 
    mainMatrix(IdentityMatrix())
{ 
    window.setActive(); 
    int x = sf::VideoMode::getDesktopMode().width;
    int y = sf::VideoMode::getDesktopMode().height;
    window.setPosition(sf::Vector2i(x- width, 0));
};

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

double sign(double x)
{
    if (x < 0.)
        return -1.;
    return 1.;
}

bool ViewWindow::mouseMoveEvent(sf::Event& event)
{
    if (event.type == sf::Event::MouseMoved)
    {
        if (mouseButtonIsDown)
        {
            rotationSpeedX += (event.mouseMove.x - mousePositionX) * 0.01;
            rotationSpeedY += (event.mouseMove.y - mousePositionY) * 0.01;

            rotationSpeedX = sign(rotationSpeedX) * std::min(5., abs(rotationSpeedX));
            rotationSpeedY = sign(rotationSpeedY) * std::min(5., abs(rotationSpeedY));
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
    rotationSpeedX = rotationSpeedY = 0.;
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
    for (const auto& s : newData)
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

void ViewWindow::setEyeFocus(double focus)
{
    eyeTarget = focus;
    Render();
}

void ViewWindow::setEyeDistance(double distance)
{
    eyeDistance = distance;
    Render();
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

    sf::RenderStates state = sf::RenderStates::Default;
    state.transform.scale(double(width) / window.getSize().x, double(height) / window.getSize().y);
    RenderTo(renderTexture, state);
    sf::Image image = renderTexture.getTexture().copyToImage();
    image.flipVertically();
    image.saveToFile(fileName);
}

void ViewWindow::RenderTo(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.clear(sf::Color::Black);
    auto size = target.getSize();
    double k = (double)size.x/size.y;
    
    target.setView(sf::View(sf::FloatRect(-zoom/2*k * *(state.transform.getMatrix()+0), -zoom/2 * *(state.transform.getMatrix() + 5), zoom*k *  *(state.transform.getMatrix() + 0), zoom * *(state.transform.getMatrix() + 5))));
    
    state.blendMode = sf::BlendMode(sf::BlendMode::Factor::One, sf::BlendMode::Factor::One, sf::BlendMode::Equation::Add);
    
    target.draw(leftVertexArray, state);
    target.draw(rightVertexArray, state);
}
