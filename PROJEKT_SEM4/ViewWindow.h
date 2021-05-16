#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "structures.h"
#include "wec.h"


class ViewWindow
{
protected:
	sf::RenderWindow* window;
	sf::VertexArray arr;
	const std::vector<Section>* data;

	sf::Vector3f localTranslation;
	sf::Vector3f localRotation;

public:
	//
	//Empty contructor
	//
	ViewWindow();

	//
	//If window isn't opened, create new window
	//
	void CreateWindow(int x, int y, const std::wstring nazwa = L"Okno podgl¹dowe");

	//
	//Check if window is opened
	//
	bool IsWindowOpened() const;

	//
	//set data for future figure building
	//
	void setData(const std::vector<Section>);


	//
	//create figures
	//
	void Update(const Matrix4& wxTranslation, const Matrix4& wxRotation);

	//
	//HandleEvents
	//
	void HandleEvents();

	//
	//display figures on window
	//
	void Display();

	//
	//Save current frame to file jpg
	//
	void SaveToFile() const;

	~ViewWindow();
};

