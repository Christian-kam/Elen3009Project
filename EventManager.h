#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <SFML/Graphics.hpp>
#include "PlayerShip.h"
using renderWindow = sf::RenderWindow;
using Event = sf::Event;
using Keyboard = sf::Keyboard;
//using Keyboard = sf::Keyboard::Key;

class EventManager : sf::NonCopyable
{
public:
	//void handleUserInput(Keyboard::Key key, bool isPressed);
	
	//EventManager(Event event);
	void processEvent(const Event& event);
	float getXPosition() const;
	float getYPosition() const;
	bool getUp() const;
	bool getDown() const;
	bool getLeft() const;
	bool getRight() const;
	float getSpeed() const;
private:
	void handleUserInput(Keyboard::Key key, bool isPressed);
	PlayerShip _player;
	Position _playerPosition;
	//void processEvent();
	bool _moveUp = false;
	bool _moveDown = false;
	bool _moveLeft = false;
	bool _moveRight = false;
};

#endif