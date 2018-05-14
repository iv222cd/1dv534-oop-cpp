#include <iostream>
#include <fstream>
#include "List.h"

WList* WList::whead = nullptr; // Initilizing static member variables of list

/******************************************************************************
* Public function members
******************************************************************************/

/**
* @brief Constructor of an WList node.
* Creating a new node with a new translation word list and inserting it before wnext in the linked list.
* @param wword    char string word to be stored in this node.
* @param tword    char string word with a translation of wword. 
* @param wnext    WList node that this node should be inserted before.
*                 If wnext is head of list this node replace it as head node.
*/
WList::WList(const char* wword, const char* tword, WList* wnext) : List<WList>(wword, wnext)
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
         // Find the node before wnext in list and repoint it to this object.
         if (wp->next == wnext)
         {
            wp->next = this;
            break;
         }
         wp = wp->next;
      }
   }
}

/**
* @brief Destructor of this WList node.
* Also delete all nodes in translation list.
* Note that memory management of word is made by the base class List<WList>
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

/**
* @brief Insert a new word pair into WList.
* If wword is not found in wlist, this class method will insert a new
* WList node at the proper position in the wlist. It will also create
* a tlist entry for tword. If wword is already in wlist, its tlist
* will be extended with a new Tlist node containing tword.
* Method will return a pointer to the affected WList if successful,
* otherwise it will return NULL meaning that the tword already has
* been registered with this wword or that some other error occurred. *
* @param wword    WList char string word.
* @param tword    char string word that represents a translation of wword
* @return   WList pointer to new WList node.
* @return   nullptr if wword already in WList.
*/
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

/**
* @brief Remove a new word pair from WList.
* This class method will find the wlist node for wword, and then
* traverse its tlist until tword is found. It will then remove that
* TList node. If this operation makes the tlist empty, the method
* will also remove the WList node.
* Method will return true if operation was successful, otherwise false.
* It will normally return false only if tword is not found for wword.
* @param wword    WList char string word.
* @param tword    TList char string word to remove.
* @return   true  if word removed.
* @return   false if word not removed due to that the word is not in list or other error.
*/
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
/**
* @brief    Empty WList and delete all nodes.
*/
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

/**
* @brief    Print a representation of WList to CLI.
*/
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

/**
* @brief    Give the translation of a word.
* This method will traverse WList until wword is found and return the pointer to the TList head.
* @paramt   wword    char string with word to translate.
* @return   TList*   Head of a TList that represents a translation of wword.
* @return   nullptr  if wword not in WList
*/
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

/**
* @brief    Save WList to file.
* @paramt   filename    file to save the WList in.
* @return   true   if successful.
* @return   false  if an error occured.
*/
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

/**
* @brief    Load WList from file.
* @paramt   filename    file to load the WList from.
* @return   true   if successful.
* @return   false  if an error occured.
*/
bool WList::load(const char* filename)
{
   bool status = false;
   const int BUFFER_SIZE = 256;
   char wBuffer[BUFFER_SIZE];
   const char* wword = wBuffer;
   const char* tword;

   // TODO: add some error handling.

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

/*****************************************************************************
* Private template function members
******************************************************************************/

/**
* @brief    Template function for removing a node in a linked list.
* The nodes needs to have a member called next that points to the next member.
* @paramt   prevNode    Node before the node to be removed. Set to null if node is head of list.
* @paramt   node.       Node to be removed.
* @paramt   head.       Head node of list.
*/
template <class T>
void WList::removeNode(T &prevNode, T &node, T &head)
{
   if (prevNode)
   {
      prevNode->next = node->next;
   }
   else
   {
      // Word is first in list.
      head = node->next;
   }
   delete node;
}

/**
* @brief    Template function for finding a word node in a linked list.
* The nodes needs to have a member called next that points to the next member
* and a member called word with a char string.
* The words in the list should be sorted with strcmp.
* Last member of list need to point to null.
* @paramt   word        Word to find
* @paramt   output prevNode    Will point to node before the found word. If node is head prevNode is set to null.
* @paramt   output node.       Node matching word. If word not found set to the node where a potential new word should be added.
* @paramt   head.       Head node of list.
* @return   true   if word is found. Node contains word.
* @return   false  if word is not found. Node is the node before the word should be stored.
*/
template <class T>
bool WList::findNode(const char * word, T &prevNode, T &node, T &head)
{
   bool wordInList = false;
   int compare;

   node = head;
   prevNode = nullptr;

   // If wword in WList, check if tword in TList of this WList object.
   while (node)
   {
      compare = strcmp(node->word, word);
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

/******************************************************************************
* Private function members
******************************************************************************/

/**
* @brief    Isert a new translation of WList word into TList.
* @paramt   tword        char string word with translation.
* @return   true   if tword is inserted into the TList.
* @return   false  if tword already in TList.
*/
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
