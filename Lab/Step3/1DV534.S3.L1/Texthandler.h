#ifndef TEXTHANDLER_H
#define TEXTHANDLER_H

class Texthandler
{
   const int _maxTextsToStore;
   int _antalTexter;
   char **texter;
   void replaceSpecialChars(char * buffert);
public:
   Texthandler(const char*, int);
   ~Texthandler();
   int antalTexter() { return _antalTexter; }
   int maxAntalTexter() { return _maxTextsToStore; }
   const char *text(int i);
};

#endif /* TEXTHANDLER_H */

