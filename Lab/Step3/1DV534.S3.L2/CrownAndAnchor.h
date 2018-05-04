#ifndef CROWN_AND_ANCHOR_H
#define CROWN_AND_ANCHOR_H

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
   const char* SymbolName(Symbol);
   Symbol randomSymbol();
   bool isSymbol(char * SymbolName, Symbol);
};

#endif /* CROWN_AND_ANCHOR_H */
