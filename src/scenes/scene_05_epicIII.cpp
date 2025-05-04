#include "utils.h"
#include "scenes/faithSystem.h"
#include "characters.h"
#include <iostream>
using namespace std;

void scene_05_epicIII(Character& player) {
    displayDialogue("The Fates circle around Hades, whispering in his ear with venomous doubt.");
    displaySpeakerDialogue("Fates"," 'Are you sure about this, Hades? Letting them go? It could unravel everything you've built,'");
    displayDialogue("The Fates hiss like serpents waiting to strike.");
    displaySpeakerDialogue("Fates"," 'You should keep her here, where she belongs.'");
    displayDialogue("Their voices slither into Hades' mind like dark mist.");
    dramaticPause(1500);
    displayDialogue("Hades looks uncertain, the Fates' words lingering.");
    displaySpeakerDialogue("Hades"," 'I... I don't know...' he mutters.");
    dramaticPause(500);
    displaySpeakerDialogue("Hades"," 'But if they leave, will the system hold? Will everything fall apart?'");

    displaySpeakerDialogue("Persephone"," 'You will never know unless you give him a chance.'");
    displayDialogue("Persephone says softly but firmly.");
    displaySpeakerDialogue("Persephone"," 'Give him the opportunity. I believe in him.'");

    displayDialogue("Hades sighs heavily, staring at Orpheus.");
    displaySpeakerDialogue("Hades"," 'Alright, Orpheus. One last chance. We'll see if you can survive a musical trial.'");

    printAsciiArt("lyre.txt");
    bool orpheusSuccess = musicalGame(player, false, 1); // First try

    if (!orpheusSuccess) {
        dramaticPause(1000);
        displaySpeakerDialogue("Hades", " 'Fine. Try again. But know this — the melody grows longer.'");

        orpheusSuccess = musicalGame(player, true, 2); // Second harder try
    }

    if (orpheusSuccess) {
        displaySpeakerDialogue("Hades", " 'You have proven yourself... for now.'");
    } else {
        // Both normal tries failed
        decreaseFaith(player, 15);
        displaySpeakerDialogue("Fates"," '*You fall again... the thread unravels faster.*'");

        displaySpeakerDialogue("Persephone","Peresphone:'That's enough, Hades! He's tried his best!'");
        displayDialogue("Persephone steps forward, fury in her voice.");

        displaySpeakerDialogue("Fates"," 'One. Last. Thread.'");
        dramaticPause(1000);

        // 🌟 Dynamic taunt BEFORE the final choice
        randomizedFatesTaunt(player);

        // 🌟 Offer final choice
        cout << "\nDo you dare to attempt the Fates' final melody?\n";
        cout << "1. Yes, face them.\n";
        cout << "2. No, accept your fate.\n";
        cout << "Enter choice (1 or 2): ";
        
        int choice = 0;
        while (true) {
            if (cin >> choice && (choice == 1 || choice == 2)) {
                break;
            } else {
                cout << "Please enter 1 or 2: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        

        if (choice == 1) {
            bool fatesChallenge = musicalGame(player, true, 3);

            if (fatesChallenge) {
                displaySpeakerDialogue("Hades"," 'Fine. You've earned it. Go.");
                increaseFaith(player, 20); // 🌟 Reward Faith for surviving the Fates!
            } else {
                displaySpeakerDialogue("Fates"," *Snapped like a broken string...*");
                displayDialogue("The Fates cackle as the melody collapses into silence.");
            }
        } else {
            displaySpeakerDialogue("Fates"," *Coward... Not even a last stand.*");
            displayDialogue("The Fates turn away, laughing cruelly as the melody dies.");
        }
    }
}
