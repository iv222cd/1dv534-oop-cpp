#include "Compare.h"

/**
* @brief Compare the content of string1 and string2.
* Compare the strings char by char ('A' != 'a').
* @Note The strings has to be null terminated!
* return true if string are equal.
* return false if string are not equal.
*/
bool Compare::equal(const char * string1, const char * string2)
{
   bool isEqual = false;

   // Loop util end of a string, or strings not equal.
   while ((*string1 != '\0') && (*string2 != '\0') && (*string1 == *string2))
   {
      *string1++;
      *string2++;
   }

   // If end of both strings reached they are equal.
   if ((*string1 == '\0') && (*string2 == '\0'))
   {
      isEqual = true;
   }

   return isEqual;
}