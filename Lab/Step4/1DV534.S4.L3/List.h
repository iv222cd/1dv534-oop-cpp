#ifndef LIST_H
#define LIST_H

class TList {
   friend class WList;
public:
   TList(const char* tword, TList* tnext);
   virtual ~TList() { delete word; }
   const char* getWord() const { return word; }
   const TList* successor() const { return next; }
private:
   char* word;
   TList* next;
};

class WList {
public:
   //----- instance methods
   WList(const char* wword, const char* tword, WList* wnext);
   ~WList();
   //----- class methods belonging to the class object
   static WList* insert(const char* wword, const char* tword);
   static bool remove(const char* wword, const char* tword);
   static void killWlist();
   static void showWlist();
   static const TList* translate(const char* wword);
   static bool save(const char* filename);
   static bool load(const char* filename);
private:
   //----- class constants
   static const char FILE_SEPARATOR = '\t';
   //----- class private template methods
   template <class T>
   static void removeNode(T &prevNode, T &node, T &head);
   template <class T>
   static bool findNode(const char * word, T &prevNode, T &node, T &head);
   //----- class privatemethods
   bool insertTword(const char* tword);
   //----- class private member variables
   static WList* whead;
   char* word;
   TList* thead;
   WList* next;
};

/******************************************************************************
* Private template function members
******************************************************************************/

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


#endif /* LIST_H */