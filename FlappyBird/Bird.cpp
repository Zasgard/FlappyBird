#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Bird.h"

Bird::Bird() :Player(sf::Vector2f(birdSize,birdSize)) {
	Player.setSize(sf::Vector2f(birdSize, birdSize));
	Player.setPosition(sf::Vector2f(xPos, yPos));
	Player.setFillColor(sf::Color::Red);
	flight = 0;
	keyTrack = 0;
}

void Bird::update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if (keyTrack == 0) {
			flight += flap;
			keyTrack=1;
			if (flight > flightLimit) {
				flight = flightLimit;
			}
		}
	}
	else {
		keyTrack = 0;
	}
	yPos -= flight;
	flight -= gravity;
	if (yPos >= 450-birdSize) {
		yPos = 450-birdSize;
		flight = 0;
	}
}

sf::RectangleShape & Bird::render() {
	Player.setPosition(sf::Vector2f(xPos, yPos));
	return Player;
}

std::string Bird::getScore() {
	text = std::to_string(score);
	return text;
}

void Bird::reset() {
	xPos = 50, yPos = 400;
	flight = 0;
	keyTrack = 0;
	score = 0;
}

void Bird::scoreTrack(Pipe *pillar) {
	if (xPos == pillar->xPos + pillar->xPillarSize) {
		score++;
	}
}

bool Bird::lost(Pipe *pillar) {
	if ((xPos + birdSize > pillar->xPos && xPos < pillar->xPos + pillar->xPillarSize && 
		(yPos<pillar->yOpenPos || yPos + birdSize>pillar->yOpenPos + pillar->openPillarSize)) ||
		yPos + birdSize >=pillar->yPillarSize) {
		return true;
	}
	else {
		return false;
	}
}