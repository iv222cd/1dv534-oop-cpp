#include <iostream>
#include "GameFramework.h"

void GameFramework::playBettingGames(int times)
{
   bool status = false;
   if (_player->setGame(_game))
   {
      if (_player->play(times))
      {
         status = true;
      }
      std::cout << "Efter " << _player->getBetCount() << " spel har spelaren " << _player->getMoney() << " kronor kvar!" << std::endl;
   }
   else
   {
      // TODO: Throw error. player and game does not go well together.
   }
}