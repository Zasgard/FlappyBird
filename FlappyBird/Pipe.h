#pragma once
#include <SFML/Graphics.hpp>
class Pipe {
private:
	sf::RectangleShape Pillar;
	sf::RectangleShape openPillar;
	int speed = 4;
	void _reset();
public:
	int openPillarSize = 120;
	int xPos, yPos, yOpenPos;
	int xPillarSize=50, yPillarSize=450;
	Pipe();
	void update();
	void render(sf::RenderWindow &Window);
	void reset();
};