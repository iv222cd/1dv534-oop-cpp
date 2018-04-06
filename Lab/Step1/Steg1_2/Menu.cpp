
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

void Menu::addMenuChoice(const char* description)
{
   if (nrOfItems < MAX)
   {
      menuList[nrOfItems] = description;
      menuList_[nrOfItems].setItem(nrOfItems, description);
      nrOfItems++;
   }
}

void Menu::addMenuChoice(int id, const char* description)
{
   if (nrOfItems < MAX)
   {
      menuList[nrOfItems] = description;
      menuList_[nrOfItems].setItem(id, description);
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
      cout << "\n" << menuList_[i].getItemId() << ". " << menuList_[i].getDesciption();
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
int Menu::getMenuChoice()
{
   bool valid = false;
   int choice = 0;
   char input;

   while (!valid)
   {
      cout << "\nMake your choice: ";
      cin.get(input).ignore(INT_MAX, '\n'); // Get first char. Ignore rest until new line.

      if (!cin.good())
      {
         cin.clear();
         cin.ignore(INT_MAX, '\n');
      }

      choice = atoi(&input);

      for (int i = 0; i < nrOfItems; i++)
      {
         if (choice == menuList_[i].getItemId())
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
