#ifndef CROWN_AND_ANCHOR_H
#define CROWN_AND_ANCHOR_H

/**
* @brief Class represinting a Crown and Anchor mat or dice.
* Use the symbol enum or the get char string representation of the symbols.
*/
class CrownAndAnchor
{
public:
   typedef enum SYMBOLS {
      CROWN = 0,
      ANCHOR,
      DIAMOND,
      SPADE,
      CLUB,
      HEART,
      SYMBOLS_MAX
   } Symbol;

   CrownAndAnchor();
   const char* SymbolName(int);
   Symbol randomSymbol();
   bool isSymbol(char *, int);
};

#endif /* CROWN_AND_ANCHOR_H */
