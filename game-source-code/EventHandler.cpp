#include "EventHandler.h"
EventHandler::EventHandler(const std::shared_ptr<GamePresenter> presenterPtr)

:_presenter(presenterPtr)
{ } // nothing else to do

EventHandler::~EventHandler()
{
	_presenter.reset();
}

void EventHandler::processEvent(const Event& event, bool& isPlaying)
{
	switch(event.type)
	{
		case Event::KeyPressed:
			handleInput(event.key.code, true, isPlaying);
			break;
		case Event::KeyReleased:
			handleInput(event.key.code, false,isPlaying);
			break;
		default:
		;
	}    
}

void EventHandler::handleInput(Keyboard key, bool isPressed, bool& isPlaying)
{
	if (key == Keyboard::Return)
		isPlaying = true;
	if(isPlaying )
	{
		if(isPressed)
		{
			switch(key)
			{
				case Keyboard::W:
					_presenter->updatePlayerLogic(Direction::up);
					break;
				case Keyboard::S:
					_presenter->updatePlayerLogic(Direction::down);
					break;
				case Keyboard::A:
					_presenter->updatePlayerLogic(Direction::left);
					break;
				case Keyboard::D:
					_presenter->updatePlayerLogic(Direction::right);
					break;
				case Keyboard::Space:
					_presenter->shoot(true);
					break;
				case Keyboard::RShift:
					_presenter->smart();
				default:
				;
			}
				
		}
	
	}
}

