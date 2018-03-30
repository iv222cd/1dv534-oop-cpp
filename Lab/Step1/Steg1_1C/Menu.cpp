#include "Menu.h"
#include <iostream>

using std::cout;
using std::cin;

/**
* @brief    Constructor
*/
Menu::Menu() {}

/**
* @brief    Destructor
*/
Menu::~Menu() {}

/**
* @brief    Clear CLI and print application menu.
*/
void Menu::showMenu()
{
   cout << "\n";
   cout << "\nMENU";
   cout << "\n----";
   cout << "\n";
   cout << "\n1. Display temperature values";
   cout << "\n2. View maximum and minimum temperatures";
   cout << "\n3. View average temperature";
   cout << "\n4. Quit";
   cout << "\n";
}

/**
* @brief   Get user choice from CLI.
* 
* If user enter an invalid char, continue promting until a valid choice is given.
* 
* @return   A valid menu choice (menuCoice_e enum).
*/
Menu::menuCoice Menu::getMenuChoice()
{
   int i = 0;
   char input;

   while (0 == i)
   {
      cout << "\nMake your choice: ";
      cin.get(input).ignore(INT_MAX, '\n'); // Get first char. Ignor rest until new line.

      if (!cin.good()) // TODO What does this actually do??
      {
         cin.clear();
         cin.ignore(INT_MAX, '\n');
      }

      i = atoi(&input);		// atoi() wants a char-pointer (char*) as argument
                           // Converts string to int-value
      if (i < 1 || i > 4)
      {
         cout << "\nNot a valid choice!";
         i = 0;
      }
   }
   return (menuCoice)i;
}
