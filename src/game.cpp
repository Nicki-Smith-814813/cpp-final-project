#include "characters.h"

// Include all scene headers


#include <iostream>
using namespace std;

// Main flow controller
void playGame() {
    cout << "Welcome to 'Hadestown'..." << endl;
    
    // Introduce player character
    Orpheus.name = "Orpheus";
    Eurydice.name = "Eurydice";
    
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
