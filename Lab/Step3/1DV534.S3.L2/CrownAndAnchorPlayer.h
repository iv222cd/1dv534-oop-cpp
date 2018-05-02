#ifndef CROWN_AND_ANCHOR_PLAYER_H
#define CROWN_AND_ANCHOR_PLAYER_H

#include "IPlayer.h"

class CrownAndAnchorPlayer : public IPlayer
{
public:
   CrownAndAnchorPlayer() {}
   CrownAndAnchorPlayer(int) {}
   ~CrownAndAnchorPlayer() {}

   bool setGame(IGame* game);
   bool play(int numberOfTimes);
   int getMoney() const;
   int  getBetCount() const;

};

#endif /* CROWN_AND_ANCHOR_PLAYER_H */