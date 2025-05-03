#include "utils.h"
#include "scenes/scene_06_doubtComesIn.h"
#include "characters.h"
#include "scenes/faithSystem.h"
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

    displaySpeakerDialogue("Fates","Fates: 'You don't know where you are.'");
    displaySpeakerDialogue("Fates","Fates:'You don't know how far.'");
    displaySpeakerDialogue("Fates","Fates:'You don't even know what you're walking toward.'");

    displayDialogue("You grit your teeth. You press on.\n");
    
    askFaithQuestions(player);


    displayDialogue("\nThe whispers grow louder. The doubt heavier.\n");

    displaySpeakerDialogue("Fates","Fates:'Did you ever really believe you could do it?'");
    displaySpeakerDialogue("Fates","Fates:'You’re gonna lose her. You’re gonna lose her.'");

    displayDialogue("Your hands tremble. Your heart stutters.\n");
    displayDialogue("One more choice. One last step...\n");

    if (player.faith >= 80) {
        displayDialogue("You trust in love. You trust she follows. You do not turn.\n");
        displayDialogue("The whispers of doubt fade behind you, powerless now.\n");
    } else {
        displayDialogue("You falter. Fear seizes you.\n");
        displayDialogue("You turn.\n");
        displayDialogue("The Fates exhale, satisfied.\n");
    }
    

    displayDialogue("The final fate is set...\n");
    dramaticPause(1000);
}
