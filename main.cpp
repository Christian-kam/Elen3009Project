/*! This is file contains main()
  \author Catherine Honegger and Christian Kamwangala
  \version 2.2
  \date 06/09/2015
*/
#include "GameEngine.h"

int main()
{
    std::unique_ptr<GameEngine> _game{new GameEngine()};
    _game->start();

	return 0;
}
