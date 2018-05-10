#include <iostream>
#include <fstream>
#include <sstream>
#include "List.h"

WList* WList::whead = nullptr; // Initilizing static member variables of list

/**
* Constructor
*/
WList::WList(const char* wword, const char* tword, WList* wnext)
{
   size_t size = strlen(wword) + 1;
   word = new char[size];
   strncpy_s(word, size, wword, size);

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
   delete word;
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
   if (findNode(wword, wpTmp, wp))
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
   if (findNode(wword, wpPrev, wp))
   {
      // If wword in WList, check if tword in TList of this WList object.
      TList* tp;
      TList* tpPrev;

      if (wp->findNode(tword, tpPrev, tp))
      {
         wp->removeNode(tpPrev, tp);
         if (!wp->thead)
         {
            wp->removeNode(wpPrev, wp);
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
   WList* wp;
   WList* wpTmp;
   TList* tp = nullptr;

   if (findNode(wword, wpTmp, wp))
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
               f << "\t" << tp->getWord();
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
   char* wword = wBuffer;
   char* tword;
   char* c;

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
            for (c = wBuffer; c < (wBuffer + BUFFER_SIZE) && (*c != '\0'); c++)
            {
               if (*c == '\t')
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
   if (!findNode(tword, tpPrev, tp))
   {
      wordInserted = true;
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
   }

   return wordInserted;
}

void WList::removeNode(WList* prevNode, WList* node)
{
   if (prevNode)
   {
      prevNode->next = node->next;
   }
   else
   {
      whead = node->next;
   }
   delete node;
}



void WList::removeNode(TList* prevNode, TList* node)
{
   if (prevNode)
   {
      prevNode->next = node->next;
   }
   else
   {
      // Word is first in list.
      thead = node->next;
   }
   delete node;
}

bool WList::findNode(const char* wword, WList* &prevNode, WList* &node)
{
   bool wordInList = false;
   node = whead;
   prevNode = nullptr;
   int compare;

   // If wword in WList, check if tword in TList of this WList object.
   while (node)
   {
      compare = strcmp(node->word, wword);
      if (compare == 0)
      {
         // The wword and tword already exist in the lexikon.
         wordInList = true;
         break;
      }
      else if (compare > 0)
      {
         break;
      }
      prevNode = node;
      node = node->next;
   }
   return wordInList;
}


bool WList::findNode(const char* tword, TList* &prevNode, TList* &node)
{
   bool wordInList = false;
   node = thead;
   prevNode = nullptr;
   int compare;

   // If wword in WList, check if tword in TList of this WList object.
   while (node)
   {
      compare = strcmp(node->word, tword);
      if (compare == 0)
      {
         // The wword and tword already exist in the lexikon.
         wordInList = true;
         break;
      }
      else if (compare > 0)
      {
         break;
      }
      prevNode = node;
      node = node->next;
   }

   return wordInList;
}