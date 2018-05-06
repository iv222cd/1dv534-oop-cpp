#include <cstdlib> // For randomization
#include <ctime> // Used for initilizing randomisator
#include <iostream> // Used for initilizing randomisator
#include "CrownAndAnchor.h"

const char *SYMBOL_NAMES[] = { "crown", "anchor", "diamond", "spade", "club", "heart" }; /** Char strings representing the six symbols on the Crown and Anchor mat or dice. */

/**
* @brief Constructor.  Initilize randomizator.
*/
CrownAndAnchor::CrownAndAnchor()
{
   srand((int)time(0)); // Initilize randomizator with current time.
}

/**
* @brief Constructor. Initilize randomizator.
* 
* @return String represeting the symbol.
* @return NULL if int not represinting a symbol.
*/
const char* CrownAndAnchor::SymbolName(int symbol)
{
   const char* name = NULL;
   if ((symbol >= 0) && (symbol < SYMBOLS_MAX))
   {
      name = SYMBOL_NAMES[symbol];
   }
   return name;
}

/**
* @brief Get a random Crown and Anchor symbol. Can be used as a dice.
* @return Random Crown and Anchor symbol.
*/
CrownAndAnchor::Symbol CrownAndAnchor::randomSymbol()
{
   int dice = rand() % 6;
   return (Symbol)dice;
}

/**
* @brief Compare th a char string with the char strings the int represents.
* @return true if the int represent the symbol name.
* @return false if the int does not represent the symbol name.
*/
bool CrownAndAnchor::isSymbol(char * SymbolName, int symbol)
{
   bool equal = false;
   if ((symbol >= 0) && (symbol < SYMBOLS_MAX))
   {
      if (strcmp(SymbolName, SYMBOL_NAMES[symbol]) == 0)
      {
         equal = true;
      }
   }
   return equal;
}