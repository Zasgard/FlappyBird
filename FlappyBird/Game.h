#pragma once
#include <SFML/Graphics.hpp>
#include "Bird.h"
#include "Pipe.h"

class Game{
public:
	Game();
	void run();
private:
	sf::Text text;
	sf::Font font;
	int score = 0;
	void processEvents();
	void update();
	void render();
	int t1 = 50, t2 = 50;
	sf::RenderWindow mWindow;
	Bird player;
	Pipe pillarA;
	Pipe *pillarTrackA;
	Pipe pillarB;
	Pipe *pillarTrackB;
	Pipe pillarC;
	Pipe *pillarTrackC;
	bool bPillarStart = false;
	bool cPillarStart = false;
};