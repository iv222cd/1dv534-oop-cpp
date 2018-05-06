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

class App {
public:
   App();
   int run();
private:
   Menu menu;
   void printStartInfo();
   void printPlayerInfo();
   void waitForUser();
   void playGames(int money, int times);
   int getMoneyFromUser();
   int getBettingTimesFromUser();
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

App::App()
{
   menu.addMenuChoice(MENU_ITEM_PLAY, "Play games");
   menu.addMenuChoice(MENU_ITEM_SET_TIMES, "Change number of times to play.");
   menu.addMenuChoice(MENU_ITEM_SET_MONEY, "Set how much money the player has.");
   menu.addMenuChoice(MENU_ITEM_QUIT, "Quit");
}

int App::run() {

   bool quit = false;
   int choice;

   int money = 1000; // If user tells nothing else, play with 1000 for betting.
   int times = 100; // If user tells nothing else, play the game a 100 times.

   printStartInfo();
   waitForUser();

   while (!quit)
   {
      menu.showMenu();
      choice = menu.getMenuChoice();

      switch (choice)
      {
      case MENU_ITEM_PLAY:
         playGames(money, times);
         break;
      case MENU_ITEM_SET_TIMES:
         times = getBettingTimesFromUser();
         break;
      case MENU_ITEM_SET_MONEY:
         money = getMoneyFromUser();
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


void App::printStartInfo()
{
   std::cout << "Play game... \n";
}


void App::printPlayerInfo()
{
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


void App::playGames(int money, int times)
{
   CrownAndAnchorPlayer player(money);
   CrownAndAnchorGame game;
   
   GameFramework house(&player, &game);
   house.playBettingGames(times);
}

int App::getMoneyFromUser()
{
   int money;
   std::cout << "\nHow much money should the user play with?";
   getIntFromUser(money);
   return money;
}

int App::getBettingTimesFromUser()
{
   int times;
   std::cout << "\nHow many times should the user bet?";
   getIntFromUser(times);
   return times;
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

int main() {
   App app;
   return app.run();
}