#include "scenes/faithSystem.h"
#include "scenes/scene_01_chantI.h"
#include "scenes/foraging.h"
#include <iostream>
#include "utils.h"
#include "characters.h"
using namespace std;

void scene_01_chantI(Character& player) {
    displayDialogue("The journey begins... Orpheus, your music has the power to heal, but does it have the power to save?");
    displayDialogue("You see Eurydice, her figure shimmering with uncertainty.");
    displayDialogue("But in her eyes, there is hope—a fragile hope.");
    displaySpeakerDialogue("Eurydice","Eurydice:'How much longer will this song take?'");
    displaySpeakerDialogue("Eurydice","Eurydice:'Love, we need food and firewood the song matters...but-'");
    displaySpeakerDialogue("Eurydice","Eurydice:'...don't I matter too? See I'm setting by food and wood...");
    
    // Player makes a choice
    cout << "Do you want to listen to Eurydice's concerns about food and firewood?\n";
    cout << "1. Listen to her concerns.\n";
    cout << "2. Stay focused on the song.\n";
    int choice = getValidatedInput<int>("Answer: ", 1, 2);

    if (choice == 1) {
        forageForResources(); // Transition to foraging simulator
        player.trust += 10;
        player.faith += 10;
        if (player.faith > 100) player.faith = 100;
        if (player.trust > 100) player.trust = 100;
        displaySpeakerDialogue("Eurydice", "Eurydice:'Thank you for listening, love. I know the song matters—but so do we.'");
    } else {
        displayDialogue("You remain focused on your song, determined to bring the seasons back in tune.");
        displayDialogue("But Eurydice seems troubled, her eyes glancing at the sparse surroundings. You feel a sense of unease...");
        displaySpeakerDialogue("Eurydice","Eurydice:'Fine, work on the song. I know it matters. I'll gather supplies.'");
        player.faith -= 10;
        player.trust -= 10;
        if (player.faith < 0) player.faith = 0;
        if (player.trust <0) player.trust = 0;
    }
    printAsciiArt("snake_bite.txt");
    cout << "Your current faith level: " << player.faith << "%";
}
