#include "characters.h"
#include "utils.h"
#include "game.h"
#include "scenes/scene_00_waydown.h"
#include "scenes/scene_01_chantI.h"
#include "scenes/scene_02_waitForMe.h"
#include "scenes/scene_03_howLong.h"
#include "scenes/scene_04_chantII.h"
#include "scenes/scene_05_epicIII.h"
#include "scenes/scene_06_doubtComesIn.h"
#include "scenes/scene_07_roadToHell.h"
#include <iostream>

using namespace std;

#ifdef AUTOSAVE
    #define AUTO_SAVE(player) saveGame(player, "autosave.dat")
#else
    #define AUTO_SAVE(player) // nothing
#endif


// Constructor
Game::Game() {
    init();
}

// Initialize player and other settings
void Game::init() {
 
}

// Main game start function
void Game::start() {
    cout << "Welcome to 'Hadestown'..." << endl;
    
    #ifdef AUTOSAVE
    cout << "\n[Autosave Mode Activated]\n" << endl;
#endif

    scene_00_waydown(player);
    AUTO_SAVE(player);

    scene_01_chantI(player);
    AUTO_SAVE(player);

    scene_02_waitForMe(player);
    AUTO_SAVE(player);

    scene_03_howLong(player);
    AUTO_SAVE(player);

    scene_04_chantII(player);
    AUTO_SAVE(player);

    scene_05_epicIII(player);
    AUTO_SAVE(player);

    scene_06_doubtComesIn(player);
    AUTO_SAVE(player);

    scene_07_roadToHell(player);
    AUTO_SAVE(player);

    endGame();
}



// Endgame sequence
void Game::endGame() {
    cout << "\nThanks for playing!" << endl;
}
