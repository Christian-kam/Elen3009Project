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
private:
	void handleUserInput(Keyboard::Key key, bool isPressed);
	PlayerShip _player;
	Position _playerPosition;
	//void processEvent();
	bool _moveUp;
	bool _moveDown;
	bool _moveLeft;
	bool _moveRight;
};

#endif