// FlappyBird.cpp : Defines the entry point for the console application.
/*
MAIN PROGRAM
This game is for the creation of Flappy Bird game
*/

#include "stdafx.h"
#include "Game.h"
#include "Pipe.h"
#include "Bird.h"
#include <SFML/Graphics.hpp>

int main()
{
	Game game;
	game.run();
	return 0;
}