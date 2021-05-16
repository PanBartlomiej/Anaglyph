#include "ViewWindow.h"


ViewWindow::ViewWindow() :
	window(nullptr),
	arr(),
	data(nullptr),
	localTranslation(0.f, 0.f, 0.f),
	localRotation(0.f, 0.f, 0.f)
{

}


void ViewWindow::CreateWindow(int x, int y, const std::wstring nazwa)
{
	if (!window)
		window = new sf::RenderWindow(sf::VideoMode(x, y), nazwa, sf::Style::Resize);
}


bool ViewWindow::IsWindowOpened() const
{
	return window;
}

void ViewWindow::setData(const std::vector<Section> v)
{
	data = &v;
}

void Update(const Matrix4& wxTranslation, const Matrix4& wxRotation)
{

}


void ViewWindow::HandleEvents()
{

}

void ViewWindow::Display()
{

}

void ViewWindow::SaveToFile() const
{

}

ViewWindow::~ViewWindow()
{
	if (window)
		delete window;
}