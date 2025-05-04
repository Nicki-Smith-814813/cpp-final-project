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
void theFatesGlitteringPromises();
void talkToEurydice(Character& player);
void persephoneAndHadesConflict();

// Scene entry point
void scene_00_waydown(Character& player) {
    hermesNarration();
    theFatesGlitteringPromises();
    talkToEurydice(player);
    persephoneAndHadesConflict();
}

// Hermes' Narration
void hermesNarration() {
    displaySpeakerDialogue("Hermes","'Ah, Orpheus, a dreamer with a heart full of music... But your journey is not one of simple melodies.'");
    displaySpeakerDialogue("Hermes","'You seek Eurydice, the woman who follows you without question - her heart steadfast in faith, while yours is tangled in hope.'");
    displaySpeakerDialogue("Hermes","'But beware, the Fates are watching... glittering promises, but no salvation. Hadestown is a graveyard, not a gold mine.'");
    displaySpeakerDialogue("Hermes","'Love doesn't stay silent for long, not even in the depths of the underworld.'");
}

//The Fates' speak to Eurydice
void theFatesGlitteringPromises() {
    displaySpeakerDialogue("Fates","*Where is he now, your golden-voiced boy?*");
    displaySpeakerDialogue("Fates","*Chasing melodies in his head while your stomach knots itself shut.*");
    
    displaySpeakerDialogue("Eurydice","'He’s trying. He believes things will turn around.'");
    displaySpeakerDialogue("Fates","*Belief doesn’t fill your hands, girl.*");
    displaySpeakerDialogue("Fates","*It doesn’t keep the wolves from your door.*");
    
    displaySpeakerDialogue("Fates","*Hadestown does.*");
    displaySpeakerDialogue("Fates","*A bed. A job. Bread every day. And no waiting on a man who forgets to come home.*");
    
    displaySpeakerDialogue("Eurydice","'...He hasn’t forgotten me.'");
    displaySpeakerDialogue("Fates","*No? Then why do you eat alone?*");
    
    displaySpeakerDialogue("Fates","*Why do your bones shake when the wind howls?*");
    displaySpeakerDialogue("Fates","*Come underground. At least there, the silence is warm.*");
    
}

// Eurydice Dialogue Choices
void talkToEurydice(Character& player) {
    vector<string> choices = {
    "Say: 'You're not forgotten, Eurydice. I'm still here. You don’t have to go.'",
    "Say: 'Maybe... maybe they're right. You deserve more than what I’ve given you.'",
    "Say nothing. Just watch her eyes drift toward the dark."

    };

    displayDialogue("You approach Eurydice...");
    displayDialogue("Eurydice stands before you, tired but filled with unyielding faith. She listens to the Fates, but you know her better than anyone.");
    printAsciiArt("eurydice.txt");

    for (size_t i = 0; i < choices.size(); ++i) {
        cout << i + 1 << ". " << choices[i] << endl;
    }

    int choice = getValidatedInput<int>("Answer: ", 1, 3);

    switch (choice) {
        case 1:
            displaySpeakerDialogue("Orpheus", "'You're not forgotten, Eurydice. I'm still here. You don’t have to go.'");

            player.faith += 10;
            player.trust += 10;
            break;
        case 2:
            displaySpeakerDialogue("Orpheus", "'Maybe... maybe they're right. You deserve more than what I’ve given you.'");

            player.trust -= 5;
            player.faith -= 5;
            break;
        case 3:
            displayDialogue("You say nothing. Eurydice’s eyes linger on you, then drift toward the dark.");

            player.trust -= 10;
            player.faith -= 10;
            break;
    }

    // Clamp trust
    player.trust = max(0, min(100, player.trust));
    // Clamp faith
    player.faith = max(0, min(100, player.faith));

    // Branching outcome based on trust
    if (player.trust <= 10) {
        displaySpeakerDialogue("Eurydice","'You say that now... but will you still be here tomorrow?'");
        displayDialogue("Her voice trembles — but she hasn’t walked away. Not yet.");

    } else if (player.trust <= 5) {
        displaySpeakerDialogue("Eurydice", "'At least you're honest. I don’t want to keep waiting for a dream to feed me.'");
        displayDialogue("She turns slightly toward the Fates, her posture guarded but drawn.");
    } else {
        displaySpeakerDialogue("Eurydice", "'...Nothing? Not even now?'");
        displayDialogue("She shakes her head and starts walking toward the waiting dark.");

    }
}

// Persephone and Hades Argument
void persephoneAndHadesConflict() {
    displaySpeakerDialogue("Persephone","'You’re shutting me out, Hades!'");
    displaySpeakerDialogue("Hades","'You think I don’t care, Persephone?'");
    displaySpeakerDialogue("Hades","'I do what I must to keep this place running!'");
    displaySpeakerDialogue("Persephone","'I’m doing the best I can...'");
    dramaticPause(1000);
    displaySpeakerDialogue("Persephone","'but you—you built walls too high to climb.'");
    displayDialogue("Their words stab at each other, but neither can break the walls they've built between them.");

}
