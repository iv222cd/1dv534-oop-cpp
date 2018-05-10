#ifndef LIST_H
#define LIST_H

class TList {
   friend class WList;
public:
   TList(const char* tword, TList* tnext) : word(tword), next(tnext) {}
   virtual ~TList() {}
   const char* getWord() const { return word; }
   const TList* successor() const { return next; }
private:
   const char* word;
   TList* next;
};

class WList {
public:
   //----- instance methods
   WList(const char* wword, const char* tword, WList* wnext);
   ~WList();
   //----- class methods belonging to the class object
   static WList* insert(const char* wword, const char* tword);
   static bool remove(const char* wword, const char* tword) { return false; }
   static void killWlist();
   static void showWlist();
   static const TList* translate(const char* wword);
   static bool save(const char* filename) { return true; }
   static bool load(const char* filename) { return true; }
private:
   static WList* whead;
   const char* word;
   TList* thead;
   WList* next;
};

#endif /* LIST_H */