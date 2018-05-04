#include <cstdlib> // For randomization
#include <ctime> // Used for initilizing randomisator
#include <iostream> // Used for initilizing randomisator
#include "CrownAndAnchor.h"

const char *SYMBOL_NAMES[] = { "crown", "anchor", "diamond", "spade", "club", "heart" };


CrownAndAnchor::CrownAndAnchor()
{
   srand((int)time(0)); // Initilize randomizator.
}

const char* CrownAndAnchor::SymbolName(Symbol symbol)
{
   return SYMBOL_NAMES[symbol];
}

CrownAndAnchor::Symbol CrownAndAnchor::randomSymbol()
{
   int dice = rand() % 6;
   return (Symbol)dice;
}

bool CrownAndAnchor::isSymbol(char * SymbolName, Symbol symbol)
{
   bool equal = false;
   if (strcmp(SymbolName, SYMBOL_NAMES[symbol]) == 0)
   {
      equal = true;
   }
   return equal;
}