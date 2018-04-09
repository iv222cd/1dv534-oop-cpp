#include "Compare.h"

bool Compare::equal(const char * string1, const char * string2)
{
   bool isEqual = false;

   while ((*string1 != '\0') && (*string2 != '\0'))
   {
      if (*string1 != *string2)
      {
         break;
      }
      *string1++;
      *string2++;
   }
   if ((*string1 == '\0') && (*string2 == '\0'))
   {
      isEqual = true;
   }

   return isEqual;
}