#ifndef MENU_H
#define MENU_H

enum menuCoice_e
{
   DISPLAY_VALUES = 1,
   VIEW_MAX_AND_MIN,
   VIEW_AVERAGE,
   QUIT
};

/**
* @brief    Class for displaying a menu and getting a menu choice from the user.
*/
class Menu
{
public:
   Menu();
   ~Menu();
   void showMenu();
   menuCoice_e getMenuChoice();
};

#endif /* MENU_H */