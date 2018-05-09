#ifndef LIST_H
#define LIST_H

class TList {
public:
   TList(char* tword, TList* tnext) {}
   virtual ~TList() {}
   const char* getWord() const { return word; }
   const TList* successor() const { return next; }
private:
   char* word;
   TList* next;
};

class WList {
public:
   //----- instance methods
   WList( char* wword, char* tword, WList* wnext ) {}
   ~WList() {}
   //----- class methods belonging to the class object
   static WList* insert(char* wword, char* tword) { return whead; }
   static bool remove(const char* wword, const char* tword) { return false; }
   static void killWlist() {}
   static void showWlist() {}
   static const TList* translate(char* wword) { return whead->thead; }
   static bool save(char* filename) { return false; }
   static bool load(const char* filename) { return false; }
private:
   static WList* whead;
   char* word;
   TList* thead;
   WList* next;
};

#endif /* LIST_H */