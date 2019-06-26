/**
 * @class EventHandler
 * @author Catherine Honegger and Christian Kamwangala
 * @date 03/10/2015
 * @file EventHandler.h
 * @brief This class is responsible for handling the user's input during the game
 */

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "DataTypes.h"
#include "SfmlDataTypes.h"
#include "GamePresenter.h"

class EventHandler
{
public:
	/**
	 * @brief Default constructor.
	 * @param presenterPtr is a shared pointer of type GamePresenter.
	 */
	EventHandler(const std::shared_ptr<GamePresenter> presenterPtr);
	
	/**
	 * @brief Destructor. 
	 * @details Responsible for managing the life of EventHander object.
	 */
	~EventHandler();
	
	/**
	 * @brief Process the event.
	 * @details This function processes the event during the game.
	 * @param event is an instance of sf::event.
	 * @param isPlaying is a boolean used to check if the game is playing.
	 */
	void processEvent(const Event& event, bool& isPlaying);
	   
private:
	void handleInput(Keyboard key, bool isPressed,bool& isPlaying);
	std::shared_ptr<GamePresenter> _presenter;
};

#endif
