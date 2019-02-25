/*
Pipe Class
Generates the class for Pipe generation


*/

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Pipe.h"

Pipe::Pipe():Pillar(sf::Vector2f(xPillarSize, yPillarSize)), openPillar(sf::Vector2f(xPillarSize, openPillarSize)) {
	xPos = 600;
	yPos = 0;
	yOpenPos = rand() % (450 - openPillarSize);
	Pillar.setSize(sf::Vector2f(xPillarSize, yPillarSize));
	openPillar.setSize(sf::Vector2f(xPillarSize, openPillarSize));
	Pillar.setFillColor(sf::Color::Magenta);
	openPillar.setFillColor(sf::Color::Black);
	Pillar.setPosition(sf::Vector2f(xPos, yPos));
	openPillar.setPosition(sf::Vector2f(xPos, yOpenPos));
}

void Pipe::_reset() {
	yOpenPos = rand() % (450 - openPillarSize);
	openPillar.setPosition(sf::Vector2f(xPos, yOpenPos));
	xPos = 600;
}

void Pipe::update() {
	xPos -= speed;
	if (xPos < -xPillarSize) {
		_reset();
	}
	Pillar.setPosition(sf::Vector2f(xPos, yPos));
	openPillar.setPosition(sf::Vector2f(xPos, yOpenPos));
}

void Pipe::render(sf::RenderWindow &window) {
	update();
	window.draw(Pillar);
	window.draw(openPillar);
}

void Pipe::reset() {
	xPos = 600;
	yPos = 0;
	yOpenPos = 100;
}