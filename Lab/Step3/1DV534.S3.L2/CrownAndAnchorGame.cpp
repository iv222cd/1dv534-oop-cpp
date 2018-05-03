#include "CrownAndAnchorGame.h"
#include <cstdlib>
#include <ctime> // Used for initilizing randomisator
#include <iostream> // Used for initilizing randomisator

// The game is played between a player and a banker.
// A canvas or felt mat marked with the six symbols is used for play.
// The player places bets on one or more symbols.
// He then throws the three dice.
// If there is a bet on any symbol which comes up on one or more of the dice,
// in addition to returning the stake the banker pays the player the amount
// of his stake for each die showing that symbol :
// even money if one, 2 : 1 if two, and 3 : 1 if three.
// If the symbol doesn't come up, the player loses his bet.

// For simplicity can the playes only bet on one symbol a time in this game.

enum SYMBOLS {
   CROWN = 0,
   ANCHOR,
   DIAMOND,
   SPADE,
   CLUB,
   HEART
};

CrownAndAnchorGame::CrownAndAnchorGame()
{
   srand((int)time(0)); // Initilize randomizator.
}

int CrownAndAnchorGame::play(char* bet, int amount)
{
   // TODO: Ignore bet for now, but in future let player decide which symbol to bet on.
   const int NUM_OF_DICE = 3;
   int symbol = CROWN; // Use decided bet symbol for now
   int dice;
   int win = 0;

   for (int i = 0; i < NUM_OF_DICE; i++)
   {
      // Throw a dice
      dice = rand() % 6;
      if (dice == symbol)
      {
         win += amount;
      }
   }

   if (win != 0)
   {
      win += amount; // If player won, also return stake.
   }

   return win;
}

int CrownAndAnchorGame::getID() const
{
   return 26501; // Unique ID for this game.
}