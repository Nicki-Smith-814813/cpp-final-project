#ifndef GAME_H
#define GAME_H
#include "characters.h"

class Game {
public:
    Game();
    void showMainMenu();
    void start();
    void endGame();

private:
    Character player;  // Player character (Orpheus)
    void init();
};

#endif // GAME_H

