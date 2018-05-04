#include <cstdlib>
#include <iostream>
#include "CrownAndAnchorPlayer.h"
#include "CrownAndAnchor.h"


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
      char * temp = new char[strlen(bettingSymbol) + 1];
      memcpy(temp, bettingSymbol, strlen(bettingSymbol) + 1);
      win = _game->play(temp, bet);
      delete[] temp;

      _money -= bet;
      _money += win;
   }
   return status;
}