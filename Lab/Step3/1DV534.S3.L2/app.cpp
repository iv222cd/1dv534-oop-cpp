#include <iostream>
#include "IPlayer.h"
#include "IGame.h"
#include "CrownAndAnchorPlayer.h"
#include "CrownAndAnchorGame.h"

class App {
public:
   App(IPlayer* player, IGame* game) : _player(player), _game(game) {}
   int run();
private:
   IPlayer * _player;
   IGame* _game;
};

int App::run() {
   _player->setGame(_game);
   _player->play(10000);
   std::cout << "Efter " << _player->getBetCount() << " spel har spelaren " << _player->getMoney() << " kronor kvar!" << std::endl;
   std::cin.get();
   return 0;
}

int main() {
   CrownAndAnchorPlayer player(1000); // Start with a player that has 1000 Kr
   CrownAndAnchorGame game;
   App app(&player, &game);
   return app.run();
}