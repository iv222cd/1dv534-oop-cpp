#ifndef LIST_H
#define LIST_H

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

class TList : public List<TList> {
   friend class WList;
public:
   TList(const char* word, TList* next) : List<TList>(word, next) {}
   ~TList() {}
   const char* getWord() const { return word; }
   const TList* successor() const { return next; }
};

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