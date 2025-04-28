#include "utils.h"
#include "scenes/faithSystem.h"
#include "characters.h"

void scene_05_epicIII(Character& player) {
    displayDialogue("The Fates circle around Hades, whispering in his ear with venomous doubt.");
    displaySpeakerDialogue("Fates", "'Are you sure about this, Hades? Letting them go? It could unravel everything you've built,'");
    displayDialogue("The Fates hiss like a serpent waiting to strike.");
    displaySpeakerDialogue("Fates", "'You should have kept her here, where she belongs.'");
    displayDialogue("Their voices slither into Hades' mind like dark mist.");

    displayDialogue("Hades looks uncertain, the Fates' words lingering.");
    displaySpeakerDialogue("Hades", "'I... I don't know...'");
    displayDialogue("Hades mutters.");
    displaySpeakerDialogue("Hades", "'But if they leave, will the system hold? Will everything fall apart?'");

    displaySpeakerDialogue("Persephone", "'You will never know unless you give him a chance.'");
    displayDialogue("Persephone says softly but firmly.");
    displaySpeakerDialogue("Persephone", "'Give him the opportunity. I believe in him.'");

    displayDialogue("Hades sighs heavily, staring at Orpheus.");
    displaySpeakerDialogue("Hades", "'Alright, Orpheus. One last chance. We'll see if you can survive a musical trial.'");

    bool orpheusSuccess = musicalGame(player, false, 1); // first try

    if (!orpheusSuccess) {
        dramaticPause(1000);
        displaySpeakerDialogue("Hades", "Fine. Try again. But know this — the melody grows longer.");

        orpheusSuccess = musicalGame(player, true, 2); // retry, harder

        if (!orpheusSuccess) {
            decreaseFaith(player, 15);
            displaySpeakerDialogue("Fates", "*You fall again... the thread unravels faster.*");

            displaySpeakerDialogue("Persephone", "That's enough, Hades! He's tried his best!");
            displayDialogue("Persephone steps forward, fury in her voice.");

            displaySpeakerDialogue("Fates", "One. Last. Thread.");

            // Dynamic taunt
            if (player.faith >= 70.0f) {
                displaySpeakerDialogue("Fates", "*Strong thread yet, little songbird... but can you hold it?*");
            } else if (player.faith >= 40.0f) {
                displaySpeakerDialogue("Fates", "*The thread frays... one wrong note and you're gone.*");
            } else {
                displaySpeakerDialogue("Fates", "*Ha! Barely a thread left! One pull and you fall apart.*");
            }

            // Final Fates Challenge
            bool fatesChallenge = musicalGame(player, true, 3); // 10 notes

            if (fatesChallenge) {
                displaySpeakerDialogue("Hades", "Fine. You've earned it. Go.");
            } else {
                displaySpeakerDialogue("Fates", "*Snapped like a broken string...*");
                displayDialogue("The Fates cackle as the melody collapses into silence.");
            }
        } else {
            displaySpeakerDialogue("Hades", "You have proven yourself... for now.");
        }
    } else {
        displaySpeakerDialogue("Hades", "You have proven yourself... for now.");
    }
}
