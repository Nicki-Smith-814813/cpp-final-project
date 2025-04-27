#include "foraging.h"
#include "utils.h"

void forageForResources() {
    srand(time(0)); // Seed random number generator

    int woodGathered = 0;
    int foodGathered = 0;

    // Let the player gather resources
    cout << "You and Eurydice head out into the woods to gather food and firewood.\n";
    cout << "You have some time, but not a lot, and you need to make the most of it.\n";

    // Foraging attempt: the player gathers a mix of wood and food.
    for (int i = 0; i < 3; ++i) {
        int outcome = rand() % 2; // Random success (0 or 1)
        if (outcome == 0) {
            woodGathered++;
            cout << "You successfully gather some firewood.\n";
        } else {
            foodGathered++;
            cout << "You find some food to bring back.\n";
        }
    }

    // After foraging, check how well the player did
    cout << "You return to Eurydice with your haul.\n";

    if (woodGathered >= 2 && foodGathered >= 2) {
        displayDialogue("You’ve done well gathering enough food and firewood. Eurydice seems satisfied and relieved.");
    } else {
        displayDialogue("Eurydice seems worried. You didn’t gather enough food or firewood.");
    }

    displayDialogue("Suddenly, while gathering firewood, Eurydice steps on a snake! She screams in pain and falls to the ground.");
    displayDialogue("You rush to her aid. The venom is spreading quickly. Eurydice’s fate is uncertain...\n");
}
