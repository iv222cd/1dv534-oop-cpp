#include <fstream>
#include <iostream>
#include "Texthandler.h"


const char *SEPARATOR = "%%%%%"; /** Text separator used in file to separate the texts. */
const int MAX_NR_OF_TOKENS_IN_TEXT = 10000 + sizeof(SEPARATOR)/sizeof(SEPARATOR[0]); /** No text should contain more than this number of tokens. */

/******************************************************************************
* Private member functions
******************************************************************************/

/**
* @brief Replace special chars that differs from file format to consol format (åäö).
* Replace åäöÅÄÖ-chars in buffert from file format to corresponding tokens on console format.
* Other chars are ignored.
*
* @param    buffert   NULL-terminated string buffert with chars to replace.
*/
void Texthandler::replaceSpecialChars(char * buffert)
{
   char* p = buffert;
   while (*p) {
      // håller på tills den träffar '\0' 
      if (*p == -59) *p = -113;
      if (*p == -60) *p = -114;
      if (*p == -42) *p = -103;
      if (*p == -27) *p = -122;
      if (*p == -28) *p = -124;
      if (*p == -10) *p = -108;
      ++p;
   }
}

/******************************************************************************
* Public member functions
******************************************************************************/

/**
* @brief Overloaded constructor.
*
* This constructor will read the text stories from fileName and allocatie memory for each text.
* The stories should all be less that 10 000 tokens, and separated with a line equal to '%%%%%'
*
* @param    fileName          Name to textfile to read from.
* @param    maxTextsToStore   Maximum number of text to read and store from file. Ignoring if there are more text to be read.
*/
Texthandler::Texthandler(const char* fileName, int maxTextsToStore) : _maxTextsToStore(maxTextsToStore), _nrOfTexts(0)
{
   std::ifstream f;
   char buffer[MAX_NR_OF_TOKENS_IN_TEXT]; // Input buffer
   char *ptrBuffer; // Pointer to current working position in buffer
   bool firstSeparatorFound = false;

   texts = new char*[_maxTextsToStore];

   ptrBuffer = buffer;

   f.open(fileName, std::ios::in);
   if (f)
   {
      while (f.getline(ptrBuffer, MAX_NR_OF_TOKENS_IN_TEXT - (ptrBuffer - buffer)))
      {
         if (strncmp(ptrBuffer, SEPARATOR, strlen(SEPARATOR)) == 0)
         {
            // Line was a spearator line.
            if (!firstSeparatorFound)
            {
               firstSeparatorFound = true;
            }
            else
            {
               // Store the previous text
               int lenOfNewText = strlen(buffer) - strlen(SEPARATOR);
               texts[_nrOfTexts] = new char[lenOfNewText + 1]; // +1 is for storing end token.
               strncpy(texts[_nrOfTexts], buffer, lenOfNewText);
               texts[_nrOfTexts][lenOfNewText] = '\0'; // Text should end with '\0'
               replaceSpecialChars(texts[_nrOfTexts]); // Replacing special tokens (åäö) that differs from file to console.

               // Prepear input buffer stuff for next text
               ptrBuffer = buffer;
               buffer[0] = '\0';
               _nrOfTexts++;

               if (_nrOfTexts == _maxTextsToStore)
               {
                  break;
               }
            }
         }
         else if (firstSeparatorFound)
         {
            // Normal storie line.
            ptrBuffer += f.gcount() - 1; // -1 is for pointing on end char, so we can replce it with '\n'
            if (*ptrBuffer == '\0')
            {
               *ptrBuffer = '\n';
            }
            ptrBuffer += 1;
         }
         // Other lines before first separator ignored.
      }
      if (!f.eof() && (_nrOfTexts != _maxTextsToStore))
      {
         // EOF not reached, and max number of texts not reached. we must be out of buffer.
         char error_msg[] = "\nMore than 10 000 tokens in the text. Internal buffer to small.\n";
         std::cout << error_msg; // Printing error msg to cout since main application doesn't
         throw std::overflow_error(error_msg);
      }
      f.close();
   }
   else
   {
      // Could not open file.
      char error_msg[] = "\nCould not open file.\n";
      std::cout << error_msg; // Printing error msg to cout since main application doesn't
      throw std::invalid_argument(error_msg);
   }
}

/**
* @brief Get text number i.
*
* @param i   Text number index. Index starts a 1. Maximum value for i is antalTexter.
*
* @return   pointer to text i.
* @return   NULL pointer if i is out of bounds.
*/
const char *Texthandler::text(int i)
{
   char *ptrText = NULL;
   // Note! Index i startes at 1, not 0.
   if ((i - 1 >= 0) && (i - 1 < _nrOfTexts))
   {
      ptrText = texts[i - 1];
   }
   return ptrText;
}

/**
* @brief Destructor.
*/
Texthandler::~Texthandler()
{
   for (int i = 0; i < _nrOfTexts; i++)
   {
      delete[] texts[i];
   }
   delete[] texts;
}