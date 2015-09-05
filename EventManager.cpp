#include "EventManager.h"

//EventManager::EventManager(renderWindow& screen): _screen{screen}
//{
//	
//}

float EventManager::getXPosition() const 
{
	return _playerPosition.x;
}

float EventManager::getYPosition() const 
{
	return _playerPosition.y;
}

void EventManager::processEvent(const Event& event)
{
	//Event event;
	
	//while (_screen.pollEvent(event))
	//{
		switch(event.type)
		{
			case Event::KeyPressed:
				handleUserInput(event.key.code, true);
				break;
			case Event::KeyReleased:
				handleUserInput(event.key.code, false);
				break;
			//case Event::Closed:
			//	_screen.close();
			//	break;
		}
	//}
}

void EventManager::handleUserInput(Keyboard::Key key, bool isPressed)
{
	_moveUp = false;
	_moveDown = false;
	_moveLeft = false;
	_moveRight = false;
	
	if(isPressed)
	{
		switch(key)
		{
			case Keyboard::W:
				_moveUp = isPressed;
				_playerPosition = _player.move(pDirection::up);
				break;
			case Keyboard::S:
				_moveDown = isPressed;
				_playerPosition = _player.move(pDirection::down);
				break;
			case Keyboard::A:
				_moveLeft = isPressed;
				_playerPosition = _player.move(pDirection::left);
				break;
			case Keyboard::D:
				_moveRight = isPressed;
				_playerPosition = _player.move(pDirection::right);
				break;
		}
		
	}
}

bool EventManager::getUp() const
{
	return _moveUp;
}

bool EventManager::getDown() const
{
	return _moveDown;
}

bool EventManager::getLeft() const
{
	return _moveLeft;
}

bool EventManager::getRight() const
{
	return _moveRight;
}

float EventManager::getSpeed() const
{
	return _player.getSpeed();

}