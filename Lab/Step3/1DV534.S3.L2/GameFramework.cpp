#include <iostream>
#include <stdexcept>      // std::invalid_argument
#include "GameFramework.h"

/**
* @brief Constructor, connects the player and the game.
* Throws an invalud argument exception if the player cannot set the game.
*/

GameFramework::GameFramework(IPlayer* player, IGame* game) : _player(player), _game(game)
{
   if (!_player->setGame(_game))
   {
      throw std::invalid_argument("This player cannot play this game!");
   }
}

/**
* @brief Let the player play the game numberOfTimes.
* Print the result to Terminal.
*/
void GameFramework::playBettingGames(int numberOfTimes)
{
   if (!_player->play(numberOfTimes))
   {
      std::cout << "Player is out of money!" << std::endl;
   }
   std::cout << "After " << _player->getBetCount() << " rounds the player has " << _player->getMoney() << " left!" << std::endl;
}