#ifndef GAME_FRAMEWORK_H
#define GAME_FRAMEWORK_H

#include "IGame.h"
#include "IPlayer.h"

class GameFramework
{
   IPlayer* _player;
   IGame* _game;
public:
   GameFramework(IPlayer* player, IGame* game) : _player(player), _game(game) {}
   void playBettingGames(int times);
};

#endif /* GAME_FRAMEWORK_H */