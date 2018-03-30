#ifndef MENU_H
#define MENU_H

/**
* @brief    Class for displaying a menu and getting a menu choice from the user.
*/
class Menu
{
public:
   enum menuCoice
   {
      DISPLAY_VALUES = 1,
      VIEW_MAX_AND_MIN,
      VIEW_AVERAGE,
      QUIT
   };

   Menu();
   ~Menu();
   void showMenu();
   menuCoice getMenuChoice();
};

#endif /* MENU_H */