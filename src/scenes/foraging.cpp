#include "scenes/foraging.h"
#include "utils.h"
#include <limits>
#include <iostream>     // for cout
#include <cstdlib>      // for rand() and srand()
#include <ctime>        // for time()
#include <algorithm>    // for max(), if used

using namespace std;


void forageForResources() {
    srand(time(0)); // Seed RNG

    int woodGathered = 0;
    int foodGathered = 0;

    displayDialogue("You and Eurydice head into the woods to gather supplies.");
    displayDialogue("Time is limited. You have 4 chances to gather food or firewood.");

    for (int turn = 1; turn <= 4; ++turn) {
        cout << "Turn " << turn << ": What do you want to do?\n";
        cout << "1. Gather Firewood\n";
        cout << "2. Search for Food\n";
    
        int choice = getValidatedInput<int>("Choose an action (1-2): ", 1, 2);
    
        // Determine success (70% chance)
        bool success = (rand() % 100) < 70;
    
        if (choice == 1) {
            if (success) {
                woodGathered++;
                displayDialogue("You gather a bundle of firewood.");
            } else {
                displayDialogue("You search, but the branches are wet and useless.");
            }
        } else if (choice == 2) {
            if (success) {
                foodGathered++;
                displayDialogue("You find edible roots and berries.");
            } else {
                displayDialogue("You find spoiled or poisonous plants — nothing usable.");
            }
        }
    }

    // Evaluate total resources
    displayDialogue("You return to Eurydice with your haul.");

    if (woodGathered >= 2 && foodGathered >= 2) {
        displayDialogue("You’ve done well — enough food and firewood. Eurydice smiles and squeezes your hand.");
    } else {
        displayDialogue("Eurydice looks concerned. 'It’s not enough. We’ll need to be careful.'");
    }

    displayDialogue("Suddenly, while reaching for a branch, Eurydice yelps in pain!");
    displayDialogue("A snake slithers away. She’s been bitten. Her breathing grows shallow.");
    displayDialogue("You cradle her in your arms. The venom spreads fast. Her fate now lies with the gods...");
}
