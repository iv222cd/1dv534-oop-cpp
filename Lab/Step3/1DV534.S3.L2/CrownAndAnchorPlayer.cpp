#include <cstdlib>
#include "CrownAndAnchorPlayer.h"


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
   
   for (int i = 0; i < numberOfTimes; i++)
   {
      if (_money == 0)
      {
         status = false; // Out of money.
         break;
      }

      bet = win + 1; // This player bets more if the last round was a successful one.

      if (bet > _money)
      {
         bet = _money; // Bet all.
      }
      _betCount++;
      win = _game->play(NULL, bet);
      _money -= bet;
      _money += win;
   }
   return status;
}