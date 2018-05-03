#ifndef CROWN_AND_ANCHOR_PLAYER_H
#define CROWN_AND_ANCHOR_PLAYER_H

#include "IPlayer.h"
#include "IGame.h"

class CrownAndAnchorPlayer : public IPlayer
{
   IGame* _game;
   int _money;
   int _betCount;
public:
   CrownAndAnchorPlayer(int money) : _money(money), _betCount(0) {}
   ~CrownAndAnchorPlayer() {}

   bool setGame(IGame* game);
   bool play(int numberOfTimes);
   int getMoney() const { return _money; }
   int getBetCount() const { return _betCount; }

};

#endif /* CROWN_AND_ANCHOR_PLAYER_H */