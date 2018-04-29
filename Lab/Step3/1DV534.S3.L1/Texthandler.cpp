#include <fstream>
#include "Texthandler.h"

#include <iostream>

// TODO: REQ: Replace tokens for åäö with others accoring to:
//char* p = buffert;
//while (*p) {
//   // håller på tills den träffar '\0' 
//   if (*p == -59) *p = -113;
//   if (*p == -60) *p = -114;
//   if (*p == -42) *p = -103;
//   if (*p == -27) *p = -122;
//   if (*p == -28) *p = -124;
//   if (*p == -10) *p = -108;
//   ++p;
//}

// TODO: REQ: Replace '\0' with '\n' for console.

// TODO: REQ: Throw error (show message and exit) if text longer than MAX_NUM_OF_TOKENS

const char *SEPARATOR = "%%%%%"; /** Text separator used in file to separate the texts. */
const int MAX_NR_OF_TOKENS_IN_TEXT = 10000; /** No text should contain more than this number of tokens. */

/**
* @brief Overloaded constructor.
* @param    fileName          Name to textfile to read from.
* @param    maxTextsToStore   Maximum number of text to read and store from file.
*/
Texthandler::Texthandler(const char* fileName, int maxTextsToStore) : _maxTextsToStore(maxTextsToStore), _antalTexter(0)
{
   std::ifstream f;
   char lineBuffer[MAX_NR_OF_TOKENS_IN_TEXT]; // TODO: Maybe move to heap instead.
   char textBuffer[MAX_NR_OF_TOKENS_IN_TEXT]; // TODO: Maybe move to heap instead.
   char *ptrBuff;
   int pos = 0;
   bool first = true;
   int nrOfLines = 0;

   texter = new char*[_maxTextsToStore];

   ptrBuff = textBuffer;
   textBuffer[0] = '\0';

   f.open(fileName, std::ios::in);
   if (f)
   {
      while (f.getline(lineBuffer, MAX_NR_OF_TOKENS_IN_TEXT))
      {
         int cmp = strncmp(lineBuffer, SEPARATOR, strlen(SEPARATOR));
         if (cmp == 0)
         {
            if (first)
            {
               first = false;
            }
            else
            {
               int len = strlen(textBuffer);
               char * ptr = new char[len + 1];
               strncpy(ptr, textBuffer, len + 1);
               texter[_antalTexter] = ptr;
               _antalTexter++;
               // TODO: Error if more than max.
               ptrBuff = textBuffer;
               textBuffer[0] = '\0';
            }
            // Start/end of text 1
            std::streampos startPos = f.tellg();
         }
         else if (!first)
         {
            // Read text to buffer
            //Still space in buffer?
            int lineLen = strlen(lineBuffer);
            if ((ptrBuff - textBuffer) + lineLen < MAX_NR_OF_TOKENS_IN_TEXT)
            {
               strncat(ptrBuff, lineBuffer, lineLen);
               ptrBuff += lineLen;
               strncat(ptrBuff, "\n", 1);
               ptrBuff += 1;
            }
         }
         nrOfLines++;
      }
      f.close();
   }
}

const char *Texthandler::text(int i)
{
   char *p1 = NULL;
   if ((i - 1 >= 0) && (i - 1 < _antalTexter))
   {
      p1 = texter[i - 1];
   }
   return p1;
}

/**
* @brief Destructor.
*/
Texthandler::~Texthandler()
{
   for (int i = 0; i < _antalTexter; i++)
   {
      delete[] texter[i];
   }
   delete[] texter;
}