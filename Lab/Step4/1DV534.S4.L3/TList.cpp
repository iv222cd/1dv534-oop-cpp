#include <iostream>
#include "List.h"

TList::TList(const char* tword, TList* tnext) : next(tnext)
{
   size_t size = strlen(tword) + 1;
   word = new char[size];
   strncpy_s(word, size, tword, size);
}
