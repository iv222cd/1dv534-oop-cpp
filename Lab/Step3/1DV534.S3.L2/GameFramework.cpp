#include <iostream>
#include "GameFramework.h"

/**
* @brief Connect the player and the game and let the player play the game numberOfTimes.
* Print the result to Terminal.
* Thows a ... error if the player is unable to play this game.
*/
void GameFramework::playBettingGames(int numberOfTimes)
{
   if (_player->setGame(_game))
   {
      if (!_player->play(numberOfTimes))
      {
         std::cout << "Player is out of money!" << std::endl;
      }
      std::cout << "After " << _player->getBetCount() << " the player has " << _player->getMoney() << " money left!" << std::endl;
   }
   else
   {
      // TODO: Throw error. player and game does not go well together.
   }
}