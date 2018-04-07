/**********************************************************************/
// File: App.cpp
// Summary: Main program file for Lab 2, Step 1
//       
//       
//       
//       
//       
//       
// Version: Version 1.0 - 2018-04-02
// Author:  Ingrid Wiklund
// -------------------------------------------
// Log:  2018-04-02 Created the file. Ingrid
/**********************************************************************/


#include <iostream>
#include <iomanip>
#include "CashRegister.h"
#include "Menu.h"

const char* REGISTER_FILE_NAME = "Register.txt";
const int NR_OF_CATEGORIES = 5;

const int BUFFER_SIZE = 256;

enum menuItems {
   MENU_ITEM_ADD = 1,
   MENU_ITEM_SUM,
   MENU_ITEM_QUIT
};

class CashRegisterApp
{
   Menu menu;
   CashRegister cashRegister;
public:
   CashRegisterApp();
   int run();
   void printStartInfo();
   void getItemFromUser();
   void showSumOfBatch();
   void waitForUser();
   bool getIntFromUser(int &value);
   bool getDoubleFromUser(double &value);
   bool getStringFromUser(char *string, int bufSize);
};

CashRegisterApp::CashRegisterApp() : cashRegister(REGISTER_FILE_NAME, NR_OF_CATEGORIES)
{
   menu.addMenuChoice(MENU_ITEM_ADD, "Add new item");
   menu.addMenuChoice(MENU_ITEM_SUM, "Show sum");
   menu.addMenuChoice(MENU_ITEM_QUIT, "Quit");
}

int CashRegisterApp::run()
{
   bool quit = false;
   int choice;

   printStartInfo();
   waitForUser();

   while (!quit)
   {
      menu.showMenu();
      choice = menu.getMenuChoice();

      switch (choice)
      {
      case MENU_ITEM_ADD:
         getItemFromUser();
         break;
      case MENU_ITEM_SUM:
         showSumOfBatch();
         break;
      case MENU_ITEM_QUIT:
      default:
         std::cout << "\nClosing cash register.";
         quit = true;
         break;
      }
      waitForUser();
   }

   return 0;
}

void CashRegisterApp::getItemFromUser()
{
   std::cout << "\nWrite item info...\n";

   const int BUFFER_SIZE = 256;
   int category = 0;
   double price = 0;
   char description[BUFFER_SIZE];

   std::cout << "Category:";
   if (getIntFromUser(category))
   {
      std::cout << "Price:";
      if (getDoubleFromUser(price))
      {
         std::cout << "Description:";
         if (getStringFromUser(description, BUFFER_SIZE))
         {
            if (cashRegister.registerItem(category, description, price))
            {
               std::cout << "item "<< description << " for price " << price << " in category " << category << " added.";
            }
            else
            {
               std::cout << "Could not add item. Is category correct?";
            }
         }
      }
   }
}

void CashRegisterApp::showSumOfBatch()
{
   std::cout << std::setw(30) << std::left << "\nThe total for this sale was:" << cashRegister.batchTotal() << " SEK" << '\n';
}

void CashRegisterApp::waitForUser()
{
   std::cout << "\nPress any key to continue...";
   std::cin.get();
}

void CashRegisterApp::printStartInfo()
{
   std::cout << "\nOpening Cash Register";
   std::cout << "\n";
   std::cout << "\n---------------------";
   std::cout << "\n";
}

bool CashRegisterApp::getIntFromUser(int &value)
{
   bool status = false;
   long tmpValue;
   char stringBuffer[BUFFER_SIZE];
   char* endPtr;

   std::cin.getline(stringBuffer, BUFFER_SIZE);
   tmpValue = std::strtol(stringBuffer, &endPtr, 10);

   if ((stringBuffer != endPtr) && (tmpValue >= INT_MIN) && (tmpValue <= INT_MAX))
   {
      value = tmpValue;
      status = true;
   }
   else
   {
      std::cout << "Could not read value.";
   }

   return status;
}

bool CashRegisterApp::getDoubleFromUser(double &value)
{
   bool status = false;
   double tmpValue;
   char stringBuffer[BUFFER_SIZE];
   char* endPtr;

   std::cin.getline(stringBuffer, BUFFER_SIZE);
   tmpValue = std::strtod(stringBuffer, &endPtr);

   if ((stringBuffer != endPtr))
   {
      value = tmpValue;
      status = true;
   }
   else
   {
      std::cout << "Could not read value.";
   }

   return status;
}

bool CashRegisterApp::getStringFromUser(char *string, int bufSize)
{
   bool status = false;

   std::cin.getline(string, bufSize);

   if (!std::cin.fail())
   {
      status = true;
   }
   else
   {
      std::cin.clear();
      std::cin.ignore(INT_MAX,'\n');
      std::cout << "Could not read value.\n";
   }

   return status;
}

int main()
{
   CashRegisterApp app;
   return app.run();
}