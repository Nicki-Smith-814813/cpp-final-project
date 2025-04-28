#include "utils.h"
#include "scenes/faithSystem.h"
#include "characters.h"
#include <iostream>
using namespace std;

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

        orpheusSuccess = musicalGame(player, true, 2); // second try (harder)

        if (!orpheusSuccess) {
            decreaseFaith(player, 15);
            displaySpeakerDialogue("Fates", "*You fall again... the thread unravels faster.*");

            displaySpeakerDialogue("Persephone", "That's enough, Hades! He's tried his best!");
            displayDialogue("Persephone steps forward, fury in her voice.");
            displaySpeakerDialogue("Fates", "One. Last. Thread.");
            dramaticPause(1000);

            if (!orpheusSuccess) {
                decreaseFaith(player, 15);
                displaySpeakerDialogue("Fates", "*You fall again... the thread unravels faster.*");
        
                displaySpeakerDialogue("Persephone", "That's enough, Hades! He's tried his best!");
                displayDialogue("Persephone steps forward, fury in her voice.");
                
                displaySpeakerDialogue("Fates", "One. Last. Thread.");
                dramaticPause(1000);
        
                // 🌟 Call dynamic randomized taunt based on current faith
                randomizedFatesTaunt(player);
        
            // Offers the player the chance for one final round.
                cout << "\nDo you dare to attempt the Fates' final melody?\n";
                cout << "1. Yes, face them.\n";
                cout << "2. No, accept your fate.\n";
                cout << "Enter choice (1 or 2): ";
        
                int choice = 0;
                while (true) {
                    cin >> choice;
                    if (choice == 1 || choice == 2) {
                        break;
                    } else {
                        cout << "Please enter 1 or 2: ";
                    }
                }
        
                if (choice == 1) {
                    bool fatesChallenge = musicalGame(player, true, 3);
        
                    if (fatesChallenge) {
                        displaySpeakerDialogue("Hades", "Fine. You've earned it. Go.");
                        increaseFaith(player, 20); // 🌟 Reward Faith boost for surviving Fates challenge
                    } else {
                        displaySpeakerDialogue("Fates", "*Snapped like a broken string...*");
                        displayDialogue("The Fates cackle as the melody collapses into silence.");
                    }
                } else {
                    displaySpeakerDialogue("Fates", "*Coward... Not even a last stand.*");
                    displayDialogue("The Fates turn away, laughing cruelly as the melody dies.");
                }
            }
        }
    }
