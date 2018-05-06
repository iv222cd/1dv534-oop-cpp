#include "CrownAndAnchorGame.h"
#include <cstdlib>
#include <ctime> // Used for initilizing randomisator
#include <iostream> // Used for initilizing randomisator

/**
* @brief Play one game of crown and anchor.
* @param bet. Set to any char string given as a symbol by the CrownAndAnchor class.
* @return win of the game.
*/
int CrownAndAnchorGame::play(char* bet, int amount)
{
   const int NUM_OF_DICE = 3;
   CrownAndAnchor::Symbol symbol = CrownAndAnchor::CROWN; // Let Crown be the default bet.
   int win = 0;

   // Get if the player specified what symbol to bet on.
   if (bet != NULL)
   {
      for (int i = 0; i < CrownAndAnchor::SYMBOLS_MAX; i++)
      {
         if (dice.isSymbol(bet, i))
         {
            symbol = (CrownAndAnchor::Symbol)i;
            break;
         }
      }
   }

   std::cout << "Betting " << amount <<  " on " << dice.SymbolName(symbol) << ". Dices show: ";

   // Throwing three dicec and see what the game result was.
   for (int i = 0; i < NUM_OF_DICE; i++)
   {
      // Throw a dice
      CrownAndAnchor::Symbol result = dice.randomSymbol();
      std::cout << dice.SymbolName(result) << ", ";
      if (result == symbol)
      {
         win += amount;
      }
   }

   if (win != 0)
   {
      win += amount; // If player won, also return stake.
   }
   std::cout << "win: " << win << "\n";

   return win;
}

/**
* @brief Get Unique ID for Crown and Anchor game.
* @return ID.
*/
int CrownAndAnchorGame::getID() const
{
   return 26501; // Unique ID for this game.
}