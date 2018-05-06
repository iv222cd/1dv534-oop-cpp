#include <cstdlib>
#include <iostream>
#include "CrownAndAnchorPlayer.h"
#include "CrownAndAnchor.h"

/**
* @brief Set what game this player should play. Must be a specific Crown and Anchor game.
* @param game. Game this player should play
* @return true if this player can play the game.
* @return false if this player cannot play the game.
*/
bool CrownAndAnchorPlayer::setGame(IGame* game)
{
   bool status = true;

   _game = game;

   if (_game->getID() != 26501)
   {
      status = false;
   }
   return status;
}

/**
* @brief Start and play the game.
* @param numberOfTimes. Times the player should play this game before giving up.
* @return true if the player played the game numberOfTimes.
* @return false if the player went out of money
*/
bool CrownAndAnchorPlayer::play(int numberOfTimes)
{
   bool status = true;
   int bet = 1;
   int win = 0;
   CrownAndAnchor playMat;
   
   for (int i = 0; i < numberOfTimes; i++)
   {
      if (_money == 0)
      {
         status = false; // Out of money.
         break;
      }

      bet = win != 0 ? win : 1; // This player bets more if the last round was a successful one.

      if (bet > _money)
      {
         bet = _money; // Bet all.
      }
      _betCount++;

      const char * bettingSymbol = playMat.SymbolName(playMat.randomSymbol());

      // Need to transfer the const char string to a non const char before calling game->play.
      char * bettingSymbolTemp = new char[strlen(bettingSymbol) + 1];
      memcpy(bettingSymbolTemp, bettingSymbol, strlen(bettingSymbol) + 1);

      win = _game->play(bettingSymbolTemp, bet);
      delete[] bettingSymbolTemp;

      _money -= bet;
      _money += win;
   }
   return status;
}