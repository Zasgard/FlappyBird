/*
For Game window screen
*/
#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Bird.h"
#include "Pipe.h"
#include <iostream>


Game::Game(): mWindow(sf::VideoMode(600, 450), "Flappy Bird"){
	mWindow.setFramerateLimit(30);
	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	pillarTrackA = &pillarA;
	pillarTrackB = &pillarB;
	pillarTrackC = &pillarC;
}

void Game::run(){
	while (mWindow.isOpen()){
		processEvents();
		update();
		render();
	}
}

void Game::processEvents(){
	sf::Event event;
	while (mWindow.pollEvent(event)){
		if (event.type == sf::Event::Closed)
			mWindow.close();
	}
}

void Game::render(){
	mWindow.clear();
	switch (score) {
	case 0:
		mWindow.draw(text);
		break;
	case 1:
		pillarA.render(mWindow);
		if (bPillarStart) {
			pillarB.render(mWindow);
		}
		if (cPillarStart) {
			pillarC.render(mWindow);
		}
		mWindow.draw(player.render());
		mWindow.draw(text);
		break;
	case 2:
		mWindow.draw(text);
		break;
	default:
		std::cout << "ERROR IN MENU CHANGES" << std::endl;
	}
	mWindow.display();
}

void Game::update(){
	switch (score) {
	case 0:
		text.setString("Press Space to Start");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			score = 1;
		}
		break;
	case 1:
		player.update();
		text.setPosition(400, 50);
		text.setString("Score: " + player.getScore());
		player.scoreTrack(pillarTrackA);
		pillarTrackA = &pillarA;
		player.scoreTrack(pillarTrackB);
		pillarTrackB = &pillarB;
		player.scoreTrack(pillarTrackC);
		pillarTrackC = &pillarC;
		if (pillarTrackA->xPos < 200) {
			cPillarStart = true;
		}
		else if (pillarTrackA->xPos < 400) {
			bPillarStart = true;
		}
		if (player.lost(pillarTrackA) || player.lost(pillarTrackB) || player.lost(pillarTrackC)) {
			score = 2;
		}
		break;
	case 2:
		text.setPosition(0, 50);
		text.setString("You Lost.\nScore: " + player.getScore() +"\nPress Space to Restart");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			score = 1;
			player.reset();
			pillarA.reset();
			pillarB.reset();
			pillarC.reset();
			bPillarStart = false;
			cPillarStart = false;
		}
		break;
	default:
		std::cout << "ERROR IN MENU CHANGES" << std::endl;
	}
}