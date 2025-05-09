#include "utils.h"
#include "scenes/faithSystem.h"
#include "scenes/scene_07_roadToHell.h"
#include "characters.h"

// Function for the epilogue
void scene_07_roadToHell(Character& player) {

    if (player.faith >= 80) {
        displayDialogue("You step out into the morning's light, fresh air wafting across your face, only to feel a hand gently grasp yours from behind.");
        printAsciiArt("eurydice.txt");
        displaySpeakerDialogue("Eurydice","You did it, Orpheus! You've saved me, you had faith in me!");
    } else if (player.trust >= 70) {
        displayDialogue("You hesitate. But her voice... it's there.");
        displayDialogue("You remember everything she’s risked to follow you.");
        displayDialogue("You do not turn.");
        printAsciiArt("eurydice.txt");
        displaySpeakerDialogue("Eurydice","You did it, Orpheus! You've saved me, you had faith in me!");
        player.faith += 10;

    } else {
        displayDialogue("You turn and she's gone, a mist fleeing the morning light.");
        printAsciiArt("fates_snarl.txt");

        displayDialogue("Hermes sighs deeply, his voice full of mourning.\n");
        displaySpeakerDialogue("Hermes"," 'Orpheus, you were so close... Yet doubt led you astray. The journey, once so full of hope, has ended in despair. You turned back, and in that moment, Eurydice was lost once more. The Underworld claims her again.'\n");
        displaySpeakerDialogue("Hermes"," 'But there is a sliver of light in the darkness. Though Orpheus has failed, love is not entirely lost. Hades and Persephone, the gods of this place, have found something anew in their shared grief and longing. Perhaps there is hope for them, even if Orpheus' fate is sealed.'\n");
        displayDialogue("Hermes pauses, his voice heavy.\n");
        displaySpeakerDialogue("Hermes"," 'There will be no second chances. Orpheus and Eurydice will never again walk the earth together. This tale, tragic as it is, has come to its bitter end.'\n");
        displaySpeakerDialogue("Hermes"," 'But love, true as it is, will find its way. And maybe... just maybe, the gods will find their way too.'\n");
        return;
    }

    displayDialogue("Hermes' voice brightens, filled with a note of joy.\n");
    displaySpeakerDialogue("Hermes"," 'And so, Orpheus did it! Against all odds, he walked the long path out of the Underworld with Eurydice behind him. The curse was broken. They were free!' \n");
    displaySpeakerDialogue("Hermes"," 'Together, they returned to the world above, their love stronger than ever. Orpheus' song became a hymn of victory, echoing through the world as a testament to the power of belief and love.'\n");
    displaySpeakerDialogue("Hermes"," 'And there is more. The bond between Hades and Persephone, strained for so long, was mended. Through the trials and heartache, they rediscovered the spark that once united them. Their love, too, found new life, rekindled like the warmth of a fire in the coldest of winters.'\n");
    displaySpeakerDialogue("Hermes"," 'For Orpheus and Eurydice, the road ahead is bright with hope. For Hades and Persephone, perhaps there is now a chance at peace.'\n");
    displaySpeakerDialogue("Hermes"," 'And so, the story of Orpheus and Eurydice finds its ending. But as always, the Fates watch. Will it be happiness or heartache next? Only time will tell.'\n");
    displaySpeakerDialogue("Hermes"," 'For now, we can say this: Orpheus won his freedom. And love... love has a way of prevailing.'\n");


// Final narration from Hermes
displayDialogue("Hermes' voice fades as the scene comes to a close, leaving you with the feeling that no matter the outcome, the story of Orpheus will echo through eternity.\n");
displayDialogue("The End...\n");
}