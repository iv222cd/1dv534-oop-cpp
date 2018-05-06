#ifndef GAME_FRAMEWORK_H
#define GAME_FRAMEWORK_H

#include "IGame.h"
#include "IPlayer.h"

/**
* @brief Simple class for connectin an IPlayer with an IGame and letting the player bet on the game a number of times.
*/
class GameFramework
{
   IPlayer* _player;
   IGame* _game;
public:
   GameFramework(IPlayer* player, IGame* game) : _player(player), _game(game) {}
   void playBettingGames(int numberOfTimes);
};

#endif /* GAME_FRAMEWORK_H */