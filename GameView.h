#include "EventManager.h"
#include <string>
#include <iostream>
#include <cstdlib>

#ifndef GAMEVIEW_H
#define GAMEVIEW_H

const unsigned _windowWidth = 800;
const unsigned _windowHeight = 600;
using videoMode = sf::VideoMode;
using renderWindow = sf::RenderWindow;
using title = std::string;
using Texture  = sf::Texture;
using Sprite = sf::Sprite;
using Clock = sf::Clock;

enum spriteDirection {Down, Left, Right, Up};

class GameView : sf::NonCopyable
{	
public:
	GameView();
	void run();
private:
	Texture _playerTexture;
	Sprite _playerID;
	title _name;
	renderWindow _screen;
	void renderScreen();
	void updateScreen(const EventManager& eventManager);
	bool _moveUp;
	bool _moveDown;
	bool _moveLeft;
	bool _moveRight;
	EventManager _eventManager;
};

#endif