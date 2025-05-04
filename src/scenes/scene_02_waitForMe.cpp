#include "utils.h"
#include "scenes/scene_02_waitForMe.h"
#include "scenes/faithSystem.h"
#include "characters.h"

// WaitForMe: The moment where Hermes breaks the news and sends Orpheus on his journey.
void scene_02_waitForMe(Character& player) {
    displayDialogue("Hermes appears before you, his face grim.");
    dramaticPause(500);
    displaySpeakerDialogue("Hermes","'Orpheus, I regret to inform you that Eurydice has passed away...'"); 
    displaySpeakerDialogue("Hermes","'The snakebite was too much, or perhaps the cold was stronger than we realized.'");
    dramaticPause(500);
    displaySpeakerDialogue("Hermes","'She's gone.'");
    displayDialogue("Your heart sinks into your chest. Eurydice, the woman you loved, is no longer in this world.");
    dramaticPause(1000);
    displaySpeakerDialogue("Hermes","Hermes continues:'But you mustn’t let this be the end. There’s a place called Hadestown, a dark and twisted world.'");
    displaySpeakerDialogue("Hermes", "'If you wish to retrieve her, you must go there... You must descend into the Underworld.'");
    displaySpeakerDialogue("Hermes","'Follow the road to the gates of Hadestown. There, you will find your answers.'");
    displaySpeakerDialogue("Hermes","'But be warned, it is a journey filled with peril.'");

    // Begin the journey
    dramaticPause(500);
    displayDialogue("With a heavy heart, you begin your journey toward Hadestown.");
    displaySpeakerDialogue("Orpheus","Orpheus:'Eurydice... I'm coming for you,' you say, heart pounding, determined to overcome whatever stands in your way.");
    displayDialogue("The road to Hadestown is long, and the Fates are watching...");

    mythQuestions(player);
   
}