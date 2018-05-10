#include <iostream>
#include "List.h"

WList* WList::whead = nullptr; // Initilizing static member variables of list

/**
* Constructor
*/
WList::WList(const char* wword, const char* tword, WList* wnext) : word(wword)
{
   // TODO: Set new WList as head for now. Later, change to insert where it should be.
   thead = new TList(tword, nullptr);
   next = whead;
   whead = this;
}

/**
* Destructor
*/
WList::~WList()
{
   // Delete thread that belongs to this word.
   if (thead)
   {
      const TList* tp = thead;
      const TList* tpNext;
      while (tp)
      {
         tpNext = tp->successor();
         delete tp;
         tp = tpNext;
      }
   }
}

/*********************************************************************
* static WList* WList::insert( char* wword, char* tword )
* -------------------------------------------------------
* If wword is not found in wlist, this class method will insert a new
* WList node at the proper position in the wlist. It will also create
* a tlist entry for tword. If wword is already in wlist, its tlist
* will be extended with a new Tlist node containing tword.
* Method will return a pointer to the affected WList if successful,
* otherwise it will return NULL meaning that the tword already has
* been registered with this wword or that some other error occurred. *
*********************************************************************/
WList* WList::insert(const char* wword, const char* tword)
{
   WList* newList = nullptr;
   // TODO, see if word already in list.
   newList = new WList(wword, tword, whead);
   return newList;
}


void WList::killWlist()
{
   // Delete all objects in the list.
   if (whead)
   {
      const WList* wp = whead;
      const WList* wpNext;
      while (wp)
      {
         wpNext = wp->next;
         delete wp;
         wp = wpNext;
      }
   }
}


void WList::showWlist()
{
   std::cout << "Contents of Registry\n--------------------\n";
   const WList* wp = whead;
   while (wp)
   {
      std::cout << wp->word << " :";
      const TList* tp = wp->thead;
      while (tp)
      {
         std::cout << "\t" << tp->getWord();
         tp = tp->successor();
      }
      std::cout << "\n";
      wp = wp->next;
   }
}
