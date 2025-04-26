// game.h
#ifndef GAME_H
#define GAME_H

#include "characters.h"
#include "scenes.h"

class Game {
public:
    Game();
    void start();
    void playIntro();
    void chantI();
    void waitforme();
    void howlong();
    void chantII();
    void epicIII();
    void doubtcomesin();
    void roadtohell();
    void endGame();
    
private:
    Character player;  // Player character (Orpheus)
    void init();
};

#endif // GAME_H
