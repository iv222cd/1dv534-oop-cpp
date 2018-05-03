#ifndef CROWN_AND_ANCHOR_GAME_H
#define CROWN_AND_ANCHOR_GAME_H

#include "IGame.h"

class CrownAndAnchorGame : public IGame
{
public:
   CrownAndAnchorGame();
   ~CrownAndAnchorGame() {}
   int play(char* bet, int amount);
   int getID() const;
};

#endif /* CROWN_AND_ANCHOR_GAME_H */