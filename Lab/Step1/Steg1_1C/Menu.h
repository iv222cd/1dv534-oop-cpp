#ifndef MENU_H
#define MENU_H

/**
* @brief    Class for displaying a menu and getting a menu choice from the user.
*/
class Menu
{
public:
   Menu();
   ~Menu();
   void showMenu();
   char getMenuChoice();
};

#endif /* MENU_H */