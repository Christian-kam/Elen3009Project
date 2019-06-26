// Catherine Honegger and Christian Kamwangala
//
#include "GameView.h"

GameView::GameView()
:_playerSprite()
,_background()
,_highlightTop()
,_highlightBottom()
,_landers()
,_lasers()
,_missiles()
,_powerUp()
,_heatMissiles()
,_name{"Defender"}
,_screen{videoMode(_windowWidth, _windowHeight), _name}
,_mainView()
,_map()
,_time(sf::seconds(0.05f))
,_time1(sf::seconds(1.0f))
,_font()
,_pauseMessage()
,cameraPosition()
,_screenManager(new ScreenManager())
,_resourcesHolder(new ResourcesHolder())
,_presenter(new GamePresenter(_resourcesHolder))
,_eventHandler(new EventHandler(_presenter))
,_isScoreOnDisplay{false}
,_over{false}
,_restart{false}
,_terminate{false}
{
	srand(time(NULL));
	_screen.setVerticalSyncEnabled(true);
	_screen.setKeyRepeatEnabled(true);
	
	_mainView.reset(sf::FloatRect(0, 0, _windowWidth, _windowHeight));
	_mainView.setViewport(sf::FloatRect(0,0, 1.f, 1.f));
	
	//minimap
	_map.reset(sf::FloatRect(0, 0, _windowWidth, _windowHeight));
	_map.setViewport(sf::FloatRect(0.25f,0,0.5f,0.25f));
	_map.zoom(1.95);
	
	cameraPosition = {_windowWidth/2,_windowHeight/2};
	
	_resourcesHolder->loadTexture(ID::background,"resources/GreenCathy3.png");
	//_resourcesHolder->loadTexture(ID::splashScreen,"resources/GreenCathy3.png");
	_resourcesHolder->loadTexture(ID::playerShip,"resources/Player.png");
	_resourcesHolder->loadTexture(ID::lander,"resources/lander.png");
	_resourcesHolder->loadTexture(ID::playerLaser,"resources/greenLaserRay.png");
	_resourcesHolder->loadTexture(ID::landerMissile,"resources/missile.png");
	_resourcesHolder->loadTexture(ID::highlight,"resources/blue.png");
	_resourcesHolder->loadTexture(ID::powerUp,"resources/powerUp.png");
	_resourcesHolder->loadTexture(ID::playerMissile,"resources/heatSeeking.png");


	_background.setTexture(_resourcesHolder->getTexture(ID::background));
	_playerSprite.setTexture(_resourcesHolder->getTexture(ID::playerShip));
	
	_highlightTop.setTexture(_resourcesHolder->getTexture(ID::highlight));
	_highlightBottom.setTexture(_resourcesHolder->getTexture(ID::highlight));
	
	_highlightTop.setOrigin((_resourcesHolder->getTexture(ID::highlight)).getSize().x/2,(_resourcesHolder->getTexture(ID::highlight)).getSize().y/2);
	_highlightBottom.setOrigin((_resourcesHolder->getTexture(ID::highlight)).getSize().x/2,(_resourcesHolder->getTexture(ID::highlight)).getSize().y/2);
	
	_presenter->updateGame(_playerSprite, _landers, _lasers,_missiles,_powerUp,_heatMissiles);
	
	InitializeMessages();
	
	
}

GameView::~GameView()
{
	_presenter.reset();
	_eventHandler.reset();
	_resourcesHolder.reset();
}

void GameView::run()
{
	while(_screen.isOpen())
	{
		sf::Event event;
		while (_screen.pollEvent(event))
		{
			if(event.type == Event::Closed || event.key.code == Keyboard::Escape)
			{
				_terminate = true;
				_screen.close();
			}
			else if(_over && event.key.code == Keyboard::M)
			{
				_restart = true;
				_screen.close();
			}
			else
			{
				_eventHandler->processEvent(event,isPlaying);
			}
		}
	
		if(isPlaying && !_restart)
		{
			if(_presenter->getStatus())
				renderScreen();
			else
			{
				if(!_isScoreOnDisplay)
				{
					Clock _clock;
					Time _time{sf::seconds(5.0f)};
					while(_clock.getElapsedTime() < _time)
					{
							displayScore();
							
					}
					_isScoreOnDisplay = true;
				}   
				
				if (_presenter->getRemainingLanders() == 0)
					_screenManager->displayCreditScreen(true, _mainView, _screen, _pauseMessage);
				else
				{
				_screenManager->displayCreditScreen(false, _mainView, _screen, _pauseMessage);
				}
				_over = true;
			}
		}
		else
		{
			_screenManager->displaySplashScreen(_mainView, _screen, _pauseMessage);
		}
	}
}

void GameView::renderScreen()
{
	_presenter->updateGame(_playerSprite, _landers, _lasers,_missiles,_powerUp,_heatMissiles);
	_screenManager->setCameraPosition(cameraPosition, _playerSprite); // 
	updateView(_mainView); 
	drawEntities();
	displayInfo();
//******************************************
	_screenManager->setCameraPosition(cameraPosition, _playerSprite); 
	updateView(_map);
	_screenManager->setHighlightsPosition(_playerSprite, _highlightTop, _highlightBottom);
	_screen.draw(_highlightTop);
	_screen.draw(_highlightBottom);
	
	drawEntities();
//******************************************
	_screen.display();
	_screen.clear();
}

void GameView::InitializeMessages()
{
	if (!_font.loadFromFile("resources/sansation.ttf"))
		throw failedToLoadPicture{};
		
	_pauseMessage.setFont(_font);
	_pauseMessage.setCharacterSize(40);
	_pauseMessage.setPosition(70.f, 600.f);
	_pauseMessage.setColor(sf::Color::White);    
}


void GameView::drawEntities()
{
	_screen.draw(_playerSprite);
	
	for (const auto& iter: _lasers)
		_screen.draw(iter);

	for(const auto& iter: _landers)
		_screen.draw(iter);
		
	for(const auto& iter: _missiles)
	_screen.draw(iter);
	
	for(const auto& iter: _powerUp)
	_screen.draw(iter);
	
	   
	for(const auto& iter: _heatMissiles)
	_screen.draw(iter);
}

void GameView::updateView(sf::View& currentView)
{
	currentView.setCenter(cameraPosition);
	_screen.setView(currentView);
	_screen.draw(_background);
}

 void GameView::displayInfo()
 {
	sf::Font _font;
	sf::Text _textScore;
	if (!_font.loadFromFile("resources/sansation.ttf"))
		throw failedToLoadPicture{};

	 _textScore.setFont(_font);
	_textScore.setCharacterSize(18);
	_textScore.setPosition(cameraPosition.x -250, 0.f);
	_textScore.setString("Smart Bombs: " + std::to_string(_presenter->getNumSmart()) + "  | "  "Lives: " + std::to_string(_presenter->getLives()) + "  |  " + "Remaining Landers: " + std::to_string(_presenter->getRemainingLanders()) + " |  Score: " + std::to_string(_presenter->getCurrentScore()));
	_textScore.setColor(sf::Color::White);
	_screen.draw(_textScore);
 }

void GameView::displayScore()
{
	_mainView.reset(sf::FloatRect(0, 0, _windowWidth, _windowHeight));
	_screen.setView(_mainView);
	
	sf::Font _font;
	sf::Text _textScore;
	if (!_font.loadFromFile("resources/sansation.ttf"))
		throw failedToLoadPicture{};

	 _textScore.setFont(_font);
	_textScore.setCharacterSize(40);
	_textScore.setPosition(90.f, 200.f);
	
	if(_presenter->isTopScore())
	{
		_textScore.setString("Congratulation New High Score: " + std::to_string(_presenter->getCurrentScore()));
	}
	else
	{
		_textScore.setString("High Score: " + std::to_string(_presenter->getTopScore()) + "  | "  "Your Score: " + std::to_string(_presenter->getCurrentScore()));
	}
	
	_textScore.setColor(sf::Color::White);
	
	_screen.draw(_textScore);
	_screen.display();
	_screen.clear();

}

bool GameView::getState()
{
	return _restart;
}

bool GameView::terminate()
{
	return _terminate;
}
