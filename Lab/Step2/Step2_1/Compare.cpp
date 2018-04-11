#include "Compare.h"

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