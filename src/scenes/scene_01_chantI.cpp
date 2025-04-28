#include "scenes/faithSystem.h"
#include "scenes/scene_01_chantI.h"
#include "scenes/foraging.h"
#include <iostream>
#include "utils.h"
#include "characters.h"
using namespace std;

void scene_01_chantI(Character& player) {
    displayDialogue("The journey begins... Orpheus, your music has the power to heal, but does it have the power to save?\n");
    displayDialogue("You see Eurydice across the distance, her figure shimmering with uncertainty. But in her eyes, there is hope—a fragile hope.\n");
    displaySpeakerDialogue("Orpheus","'Eurydice... I'm coming for you,' you say, heart pounding, determined to overcome whatever stands in your way.\n");
    displayDialogue("The road to Hadestown is long, and the Fates are watching...\n");

    // Player makes a choice: Listen to Eurydice's concerns or stay focused on the song
    int choice;
    cout << "Do you want to listen to Eurydice's concerns about food and firewood?\n";
    cout << "1. Listen to her concerns.\n";
    cout << "2. Stay focused on the song.\n";
    cout << "Enter 1 or 2: ";
    cin >> choice;

    if (choice == 1) {
        forageForResources(); // Transition to foraging simulator
    } else {
        displayDialogue("You remain focused on your song, determined to bring the seasons back in tune.\n");
        displayDialogue("But Eurydice seems troubled, her eyes glancing at the sparse surroundings. You feel a sense of unease...\n");
    }
};