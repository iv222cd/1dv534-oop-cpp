#include <iostream>
#include "List.h"

WList* WList::whead = nullptr; // Initilizing static member variables of list

/**
* Constructor
*/
WList::WList(const char* wword, const char* tword, WList* wnext) : word(wword)
{
   thead = new TList(tword, nullptr); // TList next is a nullpointer since this is the first entry for this word

   // Insert this WList into the linked list.
   next = wnext;

   // Find the object who is pointing to next and repoint it to this.
   if (wnext == whead)
   {
      whead = this; // If next object is head, just repont the head to this object.
   }
   else
   {
      WList* wp = whead;

      while (wp)
      {
         if (wp->next == wnext)
         {
            wp->next = this; // Repoint
            break;
         }
         wp = wp->next;
      }
   }
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
   bool wordInList = false; // flag if wword is in Wlist and later if tword is in TList.

   // Check if wword is in WList.
   WList* wp = whead;
   while (wp)
   {
      if (strcmp(wp->word, wword) == 0)
      {
         wordInList = true;
         break;
      }
      else if (strcmp(wp->word, wword) > 0)
      {
         break;
      }
      wp = wp->next;
   }

   if (wordInList)
   {
      // If wword in WList, check if tword in TList of this WList object.
      wordInList = false;
      const TList* tp = wp->thead;
      while (tp)
      {
         if (strcmp(tp->getWord(), tword) == 0)
         {
            // The wword and tword already exist in the lexikon.
            wp = nullptr;
            wordInList = true;
            break;
         }
         tp = tp->successor();
      }
      if (!wordInList)
      {
         // tword not in the TList for this WList object. Add it.
         wp->thead = new TList(tword, wp->thead);
         // TODO: Add the tword to TList in order.
      }
   }
   else
   {
      // wword not in WList, add a new one.
      wp = new WList(wword, tword, wp);
   }

   return wp;
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

const TList* WList::translate(const char* wword)
{
   WList* wp = whead;
   TList* tp = nullptr;
   while (wp)
   {
      if (strcmp(wp->word, wword) == 0)
      {
         tp = wp->thead;
         break;
      }
      wp = wp->next;
   }
   return tp;
}
