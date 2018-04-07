
#include "Menu.h"
#include <iostream>

using std::cout;
using std::cin;

/**
* @brief    Constructor
*/
Menu::Menu() : nrOfItems(0)
{
}

/**
* @brief    Destructor
*/
Menu::~Menu()
{
}

/**
* @brief    Add a new menu item.
*
* Do not add the same menu id twice.
* The menu can only store up to 20 items.
*
* @param id is the char associated with the menu choice, shown in the menu list and returned from the function getMenuChoice().
*        Note! the id needs to be uniqe for this menu.
* @param Description is a string describing the item shown to the user.
*/
void Menu::addMenuChoice(char id, const char* description)
{
   if (nrOfItems < MAX)
   {
      menuList[nrOfItems].setItem(id, description);
      nrOfItems++;
   }
}

/**
* @brief    Clear CLI and print application menu.
*/
void Menu::showMenu()
{
   system("cls");

   cout << "\n";
   cout << "\nMENU";
   cout << "\n----";
   cout << "\n";

   for (int i = 0; i < nrOfItems; i++)
   {
      cout << "\n" << menuList[i].getItemId() << ". " << menuList[i].getDesciption();
   }
   cout << "\n";
}

/**
* @brief   Get user choice from CLI.
*
* If user enter an invalid char, continue promting until a valid choice is given.
*
* @return   A valid menu choice.
*/
char Menu::getMenuChoice()
{
   bool valid = false;
   char choice;

   while (!valid)
   {
      cout << "\nMake your choice: ";
      cin.get(choice).ignore(INT_MAX, '\n'); // Get first char. Ignore rest until new line.

      if (!cin.good())
      {
         cin.clear();
         cin.ignore(INT_MAX, '\n');
      }

      for (int i = 0; i < nrOfItems; i++)
      {
         if (choice == menuList[i].getItemId())
         {
            valid = true;
            break;
         }
      }
      
      if (!valid)
      {
         cout << "\nNot a valid choice!";
      }
   }

   return choice;
}
