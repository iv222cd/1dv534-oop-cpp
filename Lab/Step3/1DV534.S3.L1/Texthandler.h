#ifndef TEXTHANDLER_H
#define TEXTHANDLER_H

/**
* @brief Class for reading and storing stories from a file.
*/
class Texthandler
{
   const int _maxTextsToStore;
   int _nrOfTexts;
   char **texts;
   void replaceSpecialChars(char * buffert);
public:
   Texthandler(const char*, int);
   ~Texthandler();
   int antalTexter() { return _nrOfTexts; }
   int maxAntalTexter() { return _maxTextsToStore; }
   const char *text(int i);
};

#endif /* TEXTHANDLER_H */

