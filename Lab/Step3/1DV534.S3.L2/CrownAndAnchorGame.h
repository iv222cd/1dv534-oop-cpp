#ifndef CROWN_AND_ANCHOR_GAME_H
#define CROWN_AND_ANCHOR_GAME_H

#include "IGame.h"
#include "CrownAndAnchor.h"

/**
* @brief Class representing a Crown and Anchor game.
*
* Rules explained:
* The game is played between a player and a banker.
* A canvas or felt mat marked with the six symbols is used for play.
* The player places bets on one or more symbols.
* He then throws the three dice.
* If there is a bet on any symbol which comes up on one or more of the dice,
* in addition to returning the stake the banker pays the player the amount
* of his stake for each die showing that symbol :
* even money if one, 2 : 1 if two, and 3 : 1 if three.
* If the symbol doesn't come up, the player loses his bet.

* For simplicity the player can only bet on one symbol a time in this implementation of the game.
*/

class CrownAndAnchorGame : public IGame
{
   CrownAndAnchor dice;
public:
   int play(char* bet, int amount);
   int getID() const;
};

#endif /* CROWN_AND_ANCHOR_GAME_H */