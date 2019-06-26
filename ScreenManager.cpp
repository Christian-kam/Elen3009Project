#include "ScreenManager.h"

ScreenManager::ScreenManager()
:_rightBoundary{3690}
,_leftBoundary{290}
,_upBoundary{37}
,_downBoundary{690}
,_textSpeed{0.f,0.f}
{} // Nothing left to do


void ScreenManager::setCameraPosition(sf::Vector2f& cameraPosition, const Sprite& _playerSprite)
{
	if(_playerSprite.getPosition().x + _playerSprite.getOrigin().x > _windowWidth /2 && _playerSprite.getPosition().x + _playerSprite.getOrigin().x < (_windowWidth * 4.5))
		cameraPosition.x = _playerSprite.getPosition().x  + _playerSprite.getOrigin().x;
		
	else if(_playerSprite.getPosition().x + _playerSprite.getOrigin().x < _windowWidth /2 && _playerSprite.getPosition().x + _playerSprite.getOrigin().x > (-_windowWidth /4 ))
		cameraPosition.x = _playerSprite.getPosition().x  + _playerSprite.getOrigin().x;
}

void ScreenManager::setHighlightsPosition(const Sprite& _playerSprite, Sprite& _top, Sprite& _bottom)
{

	if(_playerSprite.getPosition().x >= _rightBoundary) 
	{
	   _top.setPosition({_rightBoundary,_upBoundary});
		_bottom.setPosition({_rightBoundary,_downBoundary});
	}   
	else if(_playerSprite.getPosition().x <= _leftBoundary)
	{
		_top.setPosition({_leftBoundary,_upBoundary});
		_bottom.setPosition({_leftBoundary,_downBoundary});
	}

	else
	{  
		_top.setPosition({_playerSprite.getPosition().x,_upBoundary});    
		_bottom.setPosition({_playerSprite.getPosition().x,_downBoundary});
	}

}

void ScreenManager::displaySplashScreen(View& currentView, renderWindow& window, Text& _message)
{
	_message.setString("Welcome to Defender Arcade v4.0!\n Catherine Honegger \n Christian Kamwangala \n \n Press Enter to begin");
	currentView.reset(sf::FloatRect(0, 0, _windowWidth, _windowHeight));
	window.setView(currentView);
	_message.setPosition(70.f, 200.f);
	window.draw(_message);
	window.display();
	window.clear();
}

void ScreenManager::displayCreditScreen(bool wonGame, View& currentView, renderWindow& window, Text& _message)
{
	_message.setCharacterSize(25);
	if(wonGame)
	{
		_message.setString("You Won!\n Thanks for playing Defender Arcade!"
		"\n \n Authors: "
		"\n \n Catherine Honegger " 
		"\n Christian Kamwangala"
		"\n \n Testing team: "
		"\n \n Joyce and Rakesh"
		"\n Brian and Chris"
		"\n T-mac and Beekay"
		"\n Yannick and Junior"
		"\n \n Notes: "
		"\n No animals were harmed during the making of the game (^_^)"
		"\n \n Copyright: "
		"Wits University 2015"
		"\n \n Pess M to restart the game");
	}
	else
	{
		_message.setString("You Lost!\n Thanks for playing Defender Arcade!"
		"\n \n Authors: "
		"\n \n Catherine Honegger " 
		"\n Christian Kamwangala"
		"\n \n Testing team: "
		"\n \n Joyce and Rakesh"
		"\n Brian and Chris"
		"\n T-mac and Beekay"
		"\n Yannick and Junior"
		"\n \n Notes: "
		"\n No animals were harmed during the making of the game (^_^)"
		"\n \n Copyright: "
		"Wits University 2015"
		"\n \n Pess M to restart the game");        
	}
	
	_textSpeed.y -= 0.2f;
	
	currentView.reset(sf::FloatRect(0, 0, _windowWidth, _windowHeight));
	window.setView(currentView);
	_message.setPosition(90.f, 200.f);
	_message.move(_textSpeed);
	window.draw(_message);
	window.display();
	window.clear();
}
