#ifndef MENU_H
#define MENU_H

#include "MenuItem.h"

/**
* @brief    Class for displaying a menu and getting a menu choice from the user.
*/
class Menu
{
   enum{ MAX = 20 };
   MenuItem menuList[MAX];
   int nrOfItems;

public:
   Menu();
   ~Menu();
   void addMenuChoice(char id, const char* description);
   void showMenu();
   char getMenuChoice();
};

#endif /* MENU_H */