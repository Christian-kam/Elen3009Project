/**
 * @class ScreenManager
 * @author Catherine Honegger and Christian Kamwangala
 * @date 03/10/2015
 * @file ScreenManager.h
 * @brief This class is responsible for managing the different screens.
 */
 
#include "SfmlDataTypes.h"
#include "DataTypes.h"

#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

class failedToLoadFonts{};

class ScreenManager
{
public:
	
	/**
	 * @brief Default constructor.
	 */
	ScreenManager();
	
	/**
	 * @brief This function sets the view focus on the player's position.
	 * @param cameraPosition is the position of the game's focus.
	 * @param _playerSprite is the playership's sprite.
	 */
	void setCameraPosition(sf::Vector2f& cameraPosition, const Sprite& _playerSprite);
	
	/**
	 * @brief This function sets the position of the highlights.
	 * @param _playerSprite is the playership's sprite.
	 * @param _top is the top highlight's sprite.
	 * @param _bottom is the bottom highlight's sprite.
	 */
	void setHighlightsPosition(const Sprite& _playerSprite, Sprite& _top, Sprite& _bottom);
	
	/**
	 * @brief This function is responsible for displaying the credit screen
	 * @param wonGame is a boolean used to check whether the player won the game or not.
	 * @param currentview is the view on which the credits will be displayed.
	 * @param window is the game's window.
	 * @param _message contains the credits string.
	 */
	void displayCreditScreen(bool wonGame, View& currentview, renderWindow& window, Text& _message);
	
	/**
	 * @brief This function displays the start game message.
	 * @param currentview is the view on which the credits will be displayed.
	 * @param window is the game's window.
	 * @param _message contains the start game string.
	 */
	void displaySplashScreen(View& currentview, renderWindow& window, Text& _message);

private:
	float _rightBoundary;
	float _leftBoundary;
	float _upBoundary;
	float _downBoundary;
	Text _message;
	std::string _creditsString;
	sf::Vector2f _textSpeed;

};

#endif