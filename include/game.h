// game.h
#ifndef GAME_H
#define GAME_H

#include "characters.h"


class Game {
public:
    Game();
    void start();
    void scene_00_waydown();
    void scene_01_chantI();
    void scene_02_waitForMe();
    void scene_03_howLong();
    void scene_04_chantII();
    void scene_05_epicIII();
    void scene_06_doubtComesIn();
    void scene_07_roadToHell();
    void endGame();
    
private:
    Character player;  // Player character (Orpheus)
    void init();
};

#endif // GAME_H
