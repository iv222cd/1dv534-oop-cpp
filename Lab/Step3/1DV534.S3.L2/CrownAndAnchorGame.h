#ifndef CROWN_AND_ANCHOR_GAME_H
#define CROWN_AND_ANCHOR_GAME_H

#include "IGame.h"
#include "CrownAndAnchor.h"

class CrownAndAnchorGame : public IGame
{
   CrownAndAnchor dice;
public:
   int play(char* bet, int amount);
   int getID() const;
};

#endif /* CROWN_AND_ANCHOR_GAME_H */