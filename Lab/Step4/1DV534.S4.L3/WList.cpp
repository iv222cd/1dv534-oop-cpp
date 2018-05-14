#include <iostream>
#include <fstream>
#include <sstream>
#include "List.h"

WList* WList::whead = nullptr; // Initilizing static member variables of list

/**
* Constructor
*/
WList::WList(const char* wword, const char* tword, WList* wnext) : List<WList*>(wword, wnext)
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
            wp->next = this; // Repoint to this
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
   WList* wp;
   WList* wpTmp;

   // Check if wword is in WList.
   if (findNode(wword, wpTmp, wp, whead))
   {
      if (!wp->insertTword(tword))
      {
         wp = nullptr;
      }
   }
   else
   {
      // wword not in WList, add a new one.
      wp = new WList(wword, tword, wp);
   }

   return wp;
}

/*********************************************************************
* static bool WList::remove( char* wword, char* tword )
* -----------------------------------------------------
* This class method will find the wlist node for wword, and then
* traverse its tlist until tword is found. It will then remove that
* TList node. If this operation makes the tlist empty, the method
* will also remove the WList node.
* Method will return true if operation was successful, otherwise false.
* It will normally return false only if tword is not found for wword.
*
*********************************************************************/
bool WList::remove(const char* wword, const char* tword)
{
   bool status = false;
   WList* wp;
   WList* wpPrev;

   // Check if wword is in WList.
   if (findNode(wword, wpPrev, wp, whead))
   {
      // If wword in WList, check if tword in TList of this WList object.
      TList* tp;
      TList* tpPrev;

      if (findNode(tword, tpPrev, tp, wp->thead))
      {
         removeNode(tpPrev, tp, wp->thead);
         if (!wp->thead)
         {
            // TList is empty. Remove this WList node as well.
            removeNode(wpPrev, wp, whead);
         }
         status = true;
      }
   }

   return status;
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
      whead = nullptr;
   }
}

void WList::showWlist()
{
   const WList* wp = whead;
   const TList* tp;

   std::cout << "Contents of Registry\n";
   std::cout << "--------------------\n";

   while (wp)
   {
      std::cout << wp->word << " :";
      tp = wp->thead;

      while (tp)
      {
         std::cout << FILE_SEPARATOR << tp->word;
         tp = tp->next;
      }
      std::cout << "\n";
      wp = wp->next;
   }
}

const TList* WList::translate(const char* wword)
{
   WList* wp;
   WList* wpTmp;
   TList* tp = nullptr;

   if (findNode(wword, wpTmp, wp, whead))
   {
      tp = wp->thead;
   }
   return tp;
}


bool WList::save(const char* filename)
{
   bool status = false;
   std::fstream f;

   f.open(filename, std::fstream::out);

   if (f)
   {
      try
      {
         const WList* wp = whead;
         const TList* tp;
         while (wp)
         {
            f << wp->word;
            tp = wp->thead;
            while (tp)
            {
               f << FILE_SEPARATOR << tp->getWord();
               tp = tp->successor();
            }
            f << "\n";
            wp = wp->next;
         }
         status = true;
         f.close();
      }
      catch (...)
      {
         f.close();
         throw;
      }
   }

   return status;
}

bool WList::load(const char* filename)
{
   bool status = false;
   const int BUFFER_SIZE = 256;
   char wBuffer[BUFFER_SIZE];
   const char* wword = wBuffer;
   const char* tword;

   killWlist(); // Remove the old list.

   std::fstream f;
   f.open(filename, std::fstream::in);

   if (f)
   {
      try
      {
         while (f.getline(wBuffer, BUFFER_SIZE))
         {
            tword = nullptr;

            for (char* c = wBuffer; c < (wBuffer + BUFFER_SIZE) && (*c != '\0'); c++)
            {
               if (*c == FILE_SEPARATOR)
               {
                  *c = '\0';

                  if (tword)
                  {
                     insert(wword, tword);
                  }
                  tword = c + 1;
               }
            }
            insert(wword, tword);
         }
         status = true;
         f.close();
      }
      catch (...)
      {
         f.close();
         throw;
      }
   }

   return status;
}

/******************************************************************************
* Private function members
******************************************************************************/

bool WList::insertTword(const char* tword)
{
   bool wordInserted = false;
   TList* tp;
   TList* tpPrev;

   // If wword in WList, check if tword in TList of this WList object.
   if (!findNode(tword, tpPrev, tp, thead))
   {
      // tword not in the TList for this WList object. Add it.
      tp = new TList(tword, tp);

      if (tpPrev)
      {
         tpPrev->next = tp;
      }
      else
      {
         thead = tp;
      }
      wordInserted = true;
   }

   return wordInserted;
}
