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

// Main flow controller
void playGame() {
    cout << "Welcome to 'Hadestown'..." << endl;
    
    // Gameplay loop (linear, scene by scene)
    scene_00_waydown();
    scene_01_chantI();
    scene_02_waitForMe();
    scene_03_howLong();
    scene_04_chantII();
    scene_05_epicIII();
    scene_06_doubtComesIn();
    scene_07_roadToHell();

    cout << "\nThanks for playing!" << endl;
}
