#include <iostream>
#include "IPlayer.h"
#include "IGame.h"
#include "CrownAndAnchorPlayer.h"
#include "CrownAndAnchorGame.h"
#include "Menu.h"

class App {
public:
   App(IPlayer* player, IGame* game);
   int run();
private:
   IPlayer * _player;
   IGame* _game;
   Menu menu;

   void printStartInfo();
   void printPlayerInfo();
   void waitForUser();
};


App::App(IPlayer* player, IGame* game) : _player(player), _game(game)
{
   menu.addMenuChoice('1', "Play games");
   menu.addMenuChoice('2', "Change number of times to play.");
   menu.addMenuChoice('3', "Set how much money the player has.");
   menu.addMenuChoice('4', "Quit");
}

int App::run() {

   bool quit = false;
   int choice;

   int money = 1000;
   int times = 100;


   if (!_player->setGame(_game))
   {
      quit = true;
   }

   printStartInfo();
   waitForUser();

   while (!quit)
   {
      menu.showMenu();
      choice = menu.getMenuChoice();

      switch (choice)
      {
      case '1':
         _player->play(10000);
         std::cout << "Efter " << _player->getBetCount() << " spel har spelaren " << _player->getMoney() << " kronor kvar!" << std::endl;
         break;
      case '2':
         // Read nr of play times.
         break;
      case '3':
         // Read money.
         break;
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

int main() {
   CrownAndAnchorPlayer player(1000); // Start with a player that has 1000 Kr
   CrownAndAnchorGame game;
   App app(&player, &game);
   return app.run();
}