#include "utils.h"
#include "characters.h"
#include "scenes/scene_00_waydown.h"
#include <vector>     
#include <cstddef>  
#include <iostream>
#include <string>
using namespace std;

// Forward declare helpers
void hermesNarration();
void talkToEurydice(Character& player);
void persephoneAndHadesConflict();

// Scene entry point
void scene_00_waydown(Character& player) {
    hermesNarration();
    talkToEurydice(player);
    persephoneAndHadesConflict();
}

// Hermes' Narration
void hermesNarration() {
    displaySpeakerDialogue("Hermes", "Ah, Orpheus, a dreamer with a heart full of music... But your journey is not one of simple melodies.");
    displaySpeakerDialogue("Hermes", "You seek Eurydice, the woman who follows you without question - her heart steadfast in faith, while yours is tangled in hope.");
    displaySpeakerDialogue("Hermes", "But beware, the Fates are watching... glittering promises, but no salvation. Hadestown is a graveyard, not a gold mine.");
    displaySpeakerDialogue("Hermes", "Love doesn't stay silent for long, not even in the depths of the underworld.");
}

// Eurydice Dialogue Choices
void talkToEurydice(Character& player) {
    vector<string> choices = {
        "Tell Eurydice: 'Hadestown is a graveyard, not a gold mine. Don't believe the Fates.'",
        "Tell Eurydice: 'The Fates speak only truth. Maybe you should listen to them.'",
        "Stay silent and let Eurydice decide on her own."
    };

    displayDialogue("You approach Eurydice...");
    displaySpeakerDialogue("Narration", "Eurydice stands before you, tired but filled with unyielding faith. She listens to the Fates, but you know her better than anyone.");
    printAsciiArt("eurydice.txt");
    cout << "Choose what to say to Eurydice:\n";
    for (size_t i = 0; i < choices.size(); ++i) {
        cout << i + 1 << ". " << choices[i] << endl;
    }

    int choice = 0;
    while (true) {
        int answer = getValidatedInput<int>("Answer: ", 1, 3);
        if (choice >= 1 && choice <= 3) break;
        else cout << "Please choose a valid option (1-3): ";
    }

    switch (choice) {
        case 1:
            displaySpeakerDialogue("Orpheus", "Hadestown is a graveyard, Eurydice. It may glitter with gold, but it will take everything from you.");
            player.faith += 2;
            break;
        case 2:
            displaySpeakerDialogue("Orpheus", "The Fates speak truth, Eurydice. Maybe you should listen to them.");
            player.trust += 1;
            break;
        case 3:
            displayDialogue("You remain silent. Eurydice sighs and looks away.");
            break;
    }
}

// Persephone and Hades Argument
void persephoneAndHadesConflict() {
    displaySpeakerDialogue("Persephone", "You’re shutting me out, Hades!");
    displaySpeakerDialogue("Hades", "You think I don’t care, Persephone? I do what I must to keep this place running!");
    displaySpeakerDialogue("Persephone", "I’m doing the best I can... but you—you built walls too high to climb.");
    displayDialogue("Their words stab at each other, but neither can break the walls they've built between them.");
}
