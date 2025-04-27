#include "utils.h"
#include "scene_02_waitForMe.h"
// WaitForMe: The moment where Hermes breaks the news and sends Orpheus on his journey.
void waitForMe() {
    displayDialogue("Hermes appears before you, his face grim.\n");
    displayDialogue("'Orpheus, I regret to inform you that Eurydice has passed away... The snakebite was too much, or perhaps the cold was stronger than we realized. She's gone.'\n");
    displayDialogue("Your heart sinks into your chest. Eurydice, the woman you loved, is no longer in this world.\n");
    displayDialogue("Hermes continues, 'But you mustn’t let this be the end. There’s a place called Hadestown, a dark and twisted world. If you wish to retrieve her, you must go there... You must descend into the Underworld.'\n");
    displayDialogue("'Follow the road to the gates of Hadestown. There, you will find your answers. But be warned, it is a journey filled with peril.'\n");

    // Begin the journey
    displayDialogue("With a heavy heart, you begin your journey toward Hadestown. The Fates seem to swirl about you, their eyes glinting with malicious amusement.\n");

    mythQuestions();  // Fates ask questions about Greek myths

    // Outcome based on faith
    if (faith > 100) {
        faith = 100;  // Cap faith at 100%
    } else if (faith <= 0) {
        faith = 0;  // Don't allow negative faith
    }

    if (faith >= 75) {
        displayDialogue("You feel a renewed sense of purpose, bolstered by the knowledge you’ve gained. Eurydice’s memory fuels your determination.\n");
    } else if (faith >= 50) {
        displayDialogue("Your resolve is shaky, but you continue the journey, hoping that your faith will strengthen along the way.\n");
    } else {
        displayDialogue("Doubt creeps in. The path ahead seems endless, and your faith falters as you press on.\n");
    }
}