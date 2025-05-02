#include "scenes/foraging.h"
#include "utils.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

void forageForResources() {
    srand(time(0)); // Seed RNG

    int woodGathered = 0;
    int foodGathered = 0;

    displayDialogue("You and Eurydice head into the woods to gather supplies.\n");
    displayDialogue("Time is limited. You have 3 chances to gather food or firewood.\n");

    for (int turn = 1; turn <= 4; ++turn) {
        int choice = 0;
        bool valid = false;

        // Prompt player for their choice
        while (!valid) {
            cout << "Turn " << turn << ": What do you want to do?\n";
            cout << "1. Gather Firewood\n";
            cout << "2. Search for Food\n";
            cout << "Enter your choice (1 or 2): ";
            cin >> choice;

            if (cin.fail() || (choice != 1 && choice != 2)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                displayDialogue("Please enter 1 or 2.\n");
            } else {
                valid = true;
            }
        }

        // Determine success (70% chance)
        bool success = (rand() % 100) < 70;

        if (choice == 1) {
            if (success) {
                woodGathered++;
                displayDialogue("You gather a bundle of firewood.\n");
            } else {
                displayDialogue("You search, but the branches are wet and useless.\n");
            }
        } else if (choice == 2) {
            if (success) {
                foodGathered++;
                displayDialogue("You find edible roots and berries.\n");
            } else {
                displayDialogue("You find spoiled or poisonous plants — nothing usable.\n");
            }
        }
    }

    // Evaluate total resources
    displayDialogue("You return to Eurydice with your haul.\n");

    if (woodGathered >= 2 && foodGathered >= 2) {
        displayDialogue("You’ve done well — enough food and firewood. Eurydice smiles and squeezes your hand.\n");
    } else {
        displayDialogue("Eurydice looks concerned. 'It’s not enough. We’ll need to be careful.'\n");
    }

    displayDialogue("Suddenly, while reaching for a branch, Eurydice yelps in pain!\n");
    displayDialogue("A snake slithers away. She’s been bitten. Her breathing grows shallow.\n");
    displayDialogue("You cradle her in your arms. The venom spreads fast. Her fate now lies with the gods...\n");
    printAsciiArt("snake_bite.txt");
}
