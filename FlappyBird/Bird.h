#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Pipe.h"

class Bird {
private:
	sf::RectangleShape Player;
	int birdSize = 30;
	int xPos = 50, yPos = 400;
	int gravity = 1, flap=15;
	int flightLimit = 20;
	int flight;
	int keyTrack;
	int score = 0;
	std::string text;
	sf::Image Img;
	sf::Color pixel;
public:
	Bird();
	void update();
	sf::RectangleShape &render();
	std::string getScore();
	void reset();
	void scoreTrack(Pipe *pillar);
	bool lost(Pipe *pillar);
};