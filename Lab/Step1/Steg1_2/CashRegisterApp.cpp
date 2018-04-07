/**********************************************************************/
// File: App.cpp
// Summary: Main program file for Lab 2, Step 1
//          The program lets the user add item to a cash register.
//          The register is opened when the program starts,
//          and closed when the program ends.
// Version: Version 1.1 - 2018-04-07
// Author:  Ingrid Wiklund
// -------------------------------------------
// Log:  2018-04-02 Created the file. Ingrid
//       2018-04-07 Update to Version 1.1. Added input error handling.
/**********************************************************************/

#include <iostream>
#include <iomanip>
#include "CashRegister.h"
#include "Menu.h"

const char* REGISTER_FILE_NAME = "Register.txt"; /** Output file. */
const int NR_OF_CATEGORIES = 5; /** Allowed number of categories. Aloowed categories will be 1 to NR_OF_CATEGORIES */
const int BUFFER_SIZE = 256; /** Size of temporary buffer for storing strings. */
const char ERROR_VALUE[] = "Could not read value.\n"; /** Error message to show if an incorect value is give by user. */



/**
* @brief Application class allowing the user to enter values into the Cash register.
*/
class CashRegisterApp
{
   Menu menu;
   CashRegister cashRegister;

   void printStartInfo();
   void getItemFromUser();
   void showSumOfBatch();
   void waitForUser();
   bool getIntFromUser(int &value);
   bool getDoubleFromUser(double &value);
   bool getStringFromUser(char *string, int bufSize);

   /**
   * Enum for numbers displayed by the menu.
   */
   enum menuItems {
      MENU_ITEM_ADD = 1,
      MENU_ITEM_SUM,
      MENU_ITEM_QUIT
   };
public:
   CashRegisterApp(const char*, int);
   void run();
private:
};

/**
* @brief Main function of this application.
*/
int main()
{
   CashRegisterApp app(REGISTER_FILE_NAME, NR_OF_CATEGORIES);

   app.run();
   return 0;
}

/**
* @brief Constructor for CashRegisterApp
*
* @param registerFile   Output file of the cash register.
* @param nrOfCategories Number of valid categories of the register.
*/
CashRegisterApp::CashRegisterApp(const char* registerFile, int nrOfCategories) : cashRegister(registerFile, nrOfCategories)
{
   menu.addMenuChoice(MENU_ITEM_ADD, "Add new item");
   menu.addMenuChoice(MENU_ITEM_SUM, "Show sum");
   menu.addMenuChoice(MENU_ITEM_QUIT, "Quit");
}

/**
* @brief Function for running the application.
*
* Prints menu and get user input.
*/
void CashRegisterApp::run()
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
}

/** Private functions **********************************************************************/

/**
* @brief Promt user to write category, price and description of a new item.
*
* If any incorrect user input is give, end with error message.
*/
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
               std::cout << "Item "<< description << " for price " << price << " in category " << category << " added.";
            }
            else
            {
               std::cout << "Could not add item. Is category correct?";
            }
         }
      }
   }
}

/**
* @brief Show total of batch so far and reset batsh.
*/
void CashRegisterApp::showSumOfBatch()
{
   std::cout << std::setw(30) << std::left << "\nThe total for this sale was:" << cashRegister.batchTotal() << " SEK" << '\n';
}

/**
* @brief Wait for user action.
*/
void CashRegisterApp::waitForUser()
{
   std::cout << "\nPress any key to continue...";
   std::cin.get();
}

/**
* @brief Print startup info for this application
*/
void CashRegisterApp::printStartInfo()
{
   std::cout << "\nOpening Cash Register";
   std::cout << "\n";
   std::cout << "\n---------------------";
   std::cout << "\n";
}

/**
* @brief Read an int from user.
*
* If unable to read, give an error message to user.
*
* @param value for storing the int
* @return true if an int could be read
* @return false if unable to read value.
*/
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
      std::cout << ERROR_VALUE;
   }

   return status;
}

/**
* @brief Read an double from user.
*
* If unable to read, give an error message to user.
*
* @param value for storing the double
* @return true if a double could be read
* @return false if unable to read value.
*/
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
      std::cout << ERROR_VALUE;
   }

   return status;
}

/**
* @brief Read a string from user.
*
* If unable to read, give an error message to user.
*
* @param string buffer for storing the string
* @param bufSize size of string buffer
* @return true if a string could be read
* @return false if unable to read value.
*/
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
      std::cout << ERROR_VALUE;
   }

   return status;
}
