#ifndef LIST_H
#define LIST_H

/**
* @brief Class template for storing char string words in a linked list node.
* The class represents one node and manage memory for it's own word.
* The class does not keep track of the list head and does not manage memory for other nodes.
*/
template <class ListType>
class List {
public:
   template <class ListType>
   List(const char* lword, ListType* lnext) : next(lnext) {
      size_t size = strlen(lword) + 1;
      word = new char[size];
      strncpy_s(word, size, lword, size);
   }
   ~List() {
      delete word;
   }
protected:
   char* word;
   ListType* next;
};

/**
* @brief Class for a simple liked list node.
* Uses List template as base and ands some getters.
* Friend of WList so WList objects can manage the list as a whole.
*/
class TList : public List<TList> {
   friend class WList;
public:
   TList(const char* word, TList* next) : List<TList>(word, next) {}
   ~TList() {}
   const char* getWord() const { return word; }
   const TList* successor() const { return next; }
};

/**
* @brief Class for a linked list storing a dictionary.
* A list node contains a char string word and a ponter to a linked list
* of char string words representing the translation.
*
* Each class object represents a node in the list and
* static members of this class manages the list as a whole.
* Each node manages it's own linked list representing the translation words.
*
* Uses List template as base for managing memory of each node word.
*/
class WList : public List<WList> {
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
   TList* thead;
};

#endif /* LIST_H */