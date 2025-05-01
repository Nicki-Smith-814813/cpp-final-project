#include "utils.h"
#include "scenes/scene_02_waitForMe.h"
#include "scenes/faithSystem.h"
#include "characters.h"
// WaitForMe: The moment where Hermes breaks the news and sends Orpheus on his journey.
void scene_02_waitForMe(Character& player) {
    displayDialogue("Hermes appears before you, his face grim.\n");
    displaySpeakerDialogue("Hermes","'Orpheus, I regret to inform you that Eurydice has passed away... The snakebite was too much, or perhaps the cold was stronger than we realized. She's gone.'\n");
    displayDialogue("Your heart sinks into your chest. Eurydice, the woman you loved, is no longer in this world.\n");
    displaySpeakerDialogue("Hermes","continues, 'But you mustn’t let this be the end. There’s a place called Hadestown, a dark and twisted world. If you wish to retrieve her, you must go there... You must descend into the Underworld.'\n");
    displaySpeakerDialogue("Hermes","'Follow the road to the gates of Hadestown. There, you will find your answers. But be warned, it is a journey filled with peril.'\n");

    // Begin the journey
    displayDialogue("With a heavy heart, you begin your journey toward Hadestown. The Fates seem to swirl about you, their eyes glinting with malicious amusement.\n");

    mythQuestions(player);
}