#include <iostream>
#include "utils.h"
#include "scenes/scene_00_waydown.h"
#include "scenes/faithSystem.h"
#include <vector>
using namespace std;

// Forward Declarations
void hermesNarration();
void talkToEurydice(Character& player);
void persephoneAndHadesConflict();

// Scene 00
void scene_00_waydown(Character& player) {
    hermesNarration();
    talkToEurydice(player);
    persephoneAndHadesConflict();
}

// Hermes’ narration to set the stage
void hermesNarration() {
    std::cout << "Hermes speaks with a playful yet knowing tone...\n\n";
    displayDialogue("Ah, Orpheus, a dreamer with a heart full of music... But your journey, my friend, is not one of simple melodies. "
                    "You seek Eurydice, the woman who follows you without question—her heart steadfast in faith, while your own is tangled in the notes of hope.\n");
    displayDialogue("But beware, the Fates are watching... they offer glittering promises, but remember—they do not offer salvation. "
                    "Hadestown isn’t a gold mine; it’s a graveyard. It is a place of forgotten songs, where dreams go to die.\n");
    displayDialogue("And then there is Persephone, caught between the bottle and the man who once loved her. The cold silence of Hades, the wall he’s built around his heart—"
                    "but love... love doesn’t stay silent for long, Orpheus. Not even in the depths of the underworld.\n");
}

// Function for dialogue with Eurydice
void talkToEurydice(Character& player) {
    std::vector<std::string> choices = {
        "Tell Eurydice: 'Hadestown is a graveyard, not a gold mine. Don't believe the Fates.'",
        "Tell Eurydice: 'The Fates speak only truth. Maybe you should listen to them.'",
        "Stay silent and let Eurydice decide on her own."
    };

    std::cout << "You approach Eurydice...\n\n";
    displayDialogue("Eurydice stands before you, her eyes tired but filled with that same unyielding faith she’s always had in you. "
                    "She listens to the Fates, their promises of a better life, a life where she’s not cold and hungry. But you know her better than anyone.\n");

    // Displaying choices
    std::cout << "Choose what to say to Eurydice:\n";
    for (size_t i = 0; i < choices.size(); ++i) {
        std::cout << i + 1 << ". " << choices[i] << "\n";
    }

    int choice = 0;
    while (true) {
        std::cin >> choice;
        if (choice >= 1 && choice <= 3) break;
        else std::cout << "Please choose a valid option (1-3): ";
    }

    switch (choice) {
        case 1:
            displayDialogue("You speak softly but firmly: 'Hadestown is a graveyard, Eurydice. It may glitter with gold, but it will take everything from you, piece by piece.'");
            player.faith += 2; // Boost faith, as Orpheus speaks from the heart, warning her of the truth.
            break;
        case 2:
            displayDialogue("You say with conviction: 'The Fates speak only truth, Eurydice. This is your chance to leave all the suffering behind. Don’t turn your back on it.'");
            player.trust += 1; // Boost trust, as Orpheus tries to guide her, but in a more pragmatic way.
            break;
        case 3:
            displayDialogue("You remain silent. Eurydice gazes at you, but her expression betrays a flicker of doubt. She sighs, then looks away.");
            break;
        default:
            std::cout << "Invalid choice.\n";
    }
}

// Persephone and Hades' bickering (simple dialogue)
void persephoneAndHadesConflict() {
    displayDialogue("In the distance, the echoes of Persephone and Hades' argument reach your ears. Their voices are sharp, filled with frustration.\n");
    displayDialogue("'You’re shutting me out, Hades!' Persephone's voice cracks, the alcohol slurring her words. 'I’m doing the best I can to survive down here, but you—' she breaks off in a sob.\n");
    displayDialogue("'You think I don’t care, Persephone? I’m doing what I must to keep this place running!' Hades growls, his tone colder than the underworld itself. 'This is bigger than us.'\n");
    displayDialogue("Their words stab at each other, but neither can break the walls they’ve built between them.\n");
}