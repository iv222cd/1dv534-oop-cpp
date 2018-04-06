#ifndef MENU_H
#define MENU_H

#include "MenuItem.h"

/**
* @brief    Class for displaying a menu and getting a menu choice from the user.
*/
class Menu
{
   enum{ MAX = 10 };
   MenuItem menuList_[MAX];
   const char* menuList[MAX];
   int nrOfItems;

public:
   Menu();
   ~Menu();
   void addMenuChoice(const char* description);
   void addMenuChoice(int id, const char* description);
   void showMenu();
   int getMenuChoice();
};

#endif /* MENU_H */