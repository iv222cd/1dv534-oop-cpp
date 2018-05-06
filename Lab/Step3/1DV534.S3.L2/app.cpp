#include <iostream>
#include <typeinfo>
#include "IPlayer.h"
#include "IGame.h"
#include "CrownAndAnchorPlayer.h"
#include "CrownAndAnchorGame.h"
#include "Menu.h"
#include "GameFramework.h"

const int BUFFER_SIZE = 256; /** Size of temporary buffer for storing strings. */
const char ERROR_VALUE[] = "Could not read value.\n"; /** Error message to show if an incorect value is give by user. */

/**
* @brief Class for running a program letting a user control a player playing the betting game Crown and Anchor.
*/
class App {
public:
   App();
   int run();
private:
   Menu menu;
   int _money;
   int _bettingTimes;
   void printStartInfo();
   void printPlayerInfo();
   void waitForUser();
   void playGames();
   void getMoneyFromUser();
   void getBettingTimesFromUser();
   bool getIntFromUser(int &value);

   /**
   * Enum for numbers displayed by the menu.
   */
   enum menuItems : char {
      MENU_ITEM_PLAY = '1',
      MENU_ITEM_SET_TIMES,
      MENU_ITEM_SET_MONEY,
      MENU_ITEM_QUIT
   };
};

/**
* @brief Constructor. Setting menu choises and how much money and betting times for the player to start with.
*/
App::App() : _money(1000), _bettingTimes(10)
{
   menu.addMenuChoice(MENU_ITEM_PLAY, "Play games");
   menu.addMenuChoice(MENU_ITEM_SET_TIMES, "Change number of times the player should bet on the game.");
   menu.addMenuChoice(MENU_ITEM_SET_MONEY, "Set how much money the player has.");
   menu.addMenuChoice(MENU_ITEM_QUIT, "Quit");
}

/**
* @brief Running the application.
* Runs until the user gives a quit signal, or an unknown error occures.
* @return 0 if ended normally
* @return -1 if an unexpected error occured.
*/
int App::run() {

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
      case MENU_ITEM_PLAY:
         playGames();
         break;
      case MENU_ITEM_SET_TIMES:
         getBettingTimesFromUser();
         break;
      case MENU_ITEM_SET_MONEY:
         getMoneyFromUser();
         break;
      case MENU_ITEM_QUIT: /* Fall through intended*/
      default:
         std::cout << "\nQuitting.";
         quit = true;
         break;
      }
      waitForUser();
   }
   return 0;
}

/**
* @brief Print info about the program to command line.
*/
void App::printStartInfo()
{
   // TODO: Write
   std::cout << "Play game... \n";
}

/**
* @brief Print info about the player and the game to command line.
*/
void App::printPlayerInfo()
{
   // TODO: Write
   std::cout << "player... \n";
}

/**
* @brief Wait for user action.
*/
void App::waitForUser()
{
   std::cout << "\nPress Enter to continue...";
   std::cin.ignore(INT_MAX, '\n');
}

/**
* @brief Sets up a player of Crown and Anchor with a game.
* Then plays it a number of times. (or until the player is out of money.)
*/
void App::playGames()
{
   CrownAndAnchorPlayer player(_money);
   CrownAndAnchorGame game;
   
   GameFramework house(&player, &game);
   house.playBettingGames(_bettingTimes);
}

/**
* @brief Ask user to input how much money the player should play with via the command line.
* If an inccorect value is given an error message vill be shown and the money variable is not changed.
*/
void App::getMoneyFromUser()
{
   std::cout << "\nHow much money should the user play with?";
   getIntFromUser(_money);
}

/**
* @brief Ask user to input how many times the player should bet with via the command line.
* If an inccorect value is given an error message vill be shown and the money variable is not changed.
*/
void App::getBettingTimesFromUser()
{
   std::cout << "\nHow many times should the user bet?";
   getIntFromUser(_bettingTimes);
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
bool App::getIntFromUser(int &value)
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
* @brief Read an int from user.
*
* If unable to read, give an error message to user.
*
* @param value for storing the int
* @return true if an int could be read
* @return false if unable to read value.
*/
int main() {
   App app;
   return app.run();
}