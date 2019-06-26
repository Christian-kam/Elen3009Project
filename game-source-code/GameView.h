/**
 * @class GameView
 * @author Catherine Honegger and Christian Kamwangala
 * @date 03/10/2015
 * @file GameView.h
 * @brief The GameView class is responsible for rendering Entities onto the screen.
 * The class recieves keyboard prompts along with object information via the Controller class.
 */
 
#include "DataTypes.h"
#include "SfmlDataTypes.h"
#include <cstdlib>
#include "GamePresenter.h"
#include "EventHandler.h"
#include "ScreenManager.h"

#ifndef GAMEVIEW_H
#define GAMEVIEW_H

//typedefs
using Resources_ptr = std::shared_ptr<ResourcesHolder>;
using Presenter_ptr = std::shared_ptr<GamePresenter>;
using Handler_ptr = std::shared_ptr<EventHandler>;
using ScreenManager_ptr = std::unique_ptr<ScreenManager>;
class GameView 
{	
public:

	/**
	 * @brief GameView Constructor.
	 * It creates an instance of GameView and sets all the relevant attributes.
	 */
	GameView();
	
	/**
	 * @brief GameView Destructor,
	 * releases all resources used by GameView.
	 */
	~GameView();
	
	/**
	 * @brief GameView run.
	 * Contains the game loop.
	 */
	void run();
	
	/**
	 * @brief GameView getState.
	 * This function returns true if restart was selected by the user, false otherwise.
	 * @return bool.
	 */
	bool getState();
	
	/**
	 * @brief GameView terminate.
	 * This function returns true if the user decides to exit the game, false otherwise.
	 * @return bool
	 */
	bool terminate();
	
private:

	Sprite _playerSprite;
	Sprite _background;
	Sprite _highlightTop;
	Sprite _highlightBottom;
	Clock _clock;
	Clock _clock2;
	std::vector<Sprite> _landers;
	std::vector<Sprite> _lasers;
	std::vector<Sprite> _missiles;
	std::vector<Sprite> _powerUp;
	std::vector<Sprite> _heatMissiles;
	std::string _name;
	renderWindow _screen;
	View _mainView;
	View _map;
	Time _time;
	Time _time1;
	Font _font;
	Text _pauseMessage;
	sf::Vector2f cameraPosition;

	void renderScreen();
	void drawEntities();
	void updateView(View& currentView);
	void InitializeMessages();
	
	ScreenManager_ptr _screenManager;
	Resources_ptr _resourcesHolder;
	Presenter_ptr _presenter;
	Handler_ptr _eventHandler;
	
	bool isPlaying = false;
	void displayInfo();
	void displayScore();
	bool _isScoreOnDisplay;
	bool _over;
	bool _restart;
	bool _terminate;
};

#endif
