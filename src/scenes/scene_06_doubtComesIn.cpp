#include "utils.h"
#include "scenes/scene_06_doubtComesIn.h"
#include "characters.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Scene 6: Doubt Comes In - Faith under siege
void scene_06_doubtComesIn(Character& player) {
    displayDialogue("The road from Hadestown stretches endlessly into the dark.\n");
    displayDialogue("Each step forward feels heavier than the last. Each breath, a battle.\n");
    displayDialogue("Behind you, silence. Ahead, uncertainty. And around you... whispers.\n");

    displaySpeakerDialogue("Fates", "You don't know where you are.");
    displaySpeakerDialogue("Fates", "You don't know how far.");
    displaySpeakerDialogue("Fates", "You don't even know what you're walking toward.");

    displayDialogue("You grit your teeth. You press on.\n");
    
    // Mythological Doubt Quiz
    srand(time(0)); // Random seed

    vector<pair<string, int>> questions = {
        {"Who was cursed to push a boulder uphill for eternity?\n1. Sisyphus\n2. Tantalus\n3. Icarus\n", 1},
        {"Which god was born fully armored from Zeus' head?\n1. Artemis\n2. Athena\n3. Apollo\n", 2},
        {"Who is the goddess of witchcraft and crossroads?\n1. Hera\n2. Hecate\n3. Demeter\n", 2},
        {"Who ferries souls across the river Styx?\n1. Hermes\n2. Charon\n3. Thanatos\n", 2}
    };

    // Ask 2 random doubt questions
    for (int i = 0; i < 2; ++i) {
        int index = rand() % questions.size();
        cout << questions[index].first;
        cout << "Enter your answer (1, 2, or 3): ";
        int answer;
        cin >> answer;

        if (answer == questions[index].second) {
            displaySpeakerDialogue("Fates", "Maybe you know a thing or two...");
            player.faith += 5;
            if (player.faith > 100.0f) player.faith = 100.0f;
        } else {
            displaySpeakerDialogue("Fates", "Didn't think so. Little songbird lost.");
            player.faith -= 10;
            if (player.faith < 0.0f) player.faith = 0.0f;
        }

        questions.erase(questions.begin() + index); // Remove asked question
    }

    displayDialogue("\nThe whispers grow louder. The doubt heavier.\n");

    displaySpeakerDialogue("Fates", "Did you ever really believe you could do it?");
    displaySpeakerDialogue("Fates", "You’re gonna lose her. You’re gonna lose her.");

    displayDialogue("Your hands tremble. Your heart stutters.\n");
    displayDialogue("One more choice. One last step...\n");

    if (player.faith >= 50) {
        displayDialogue("You trust in love. You trust she follows. You do not turn.\n");
    } else {
        displayDialogue("You falter. Fear seizes you.\n");
        displayDialogue("You turn.\n");
    }

    displayDialogue("The final fate is set...\n");
}
