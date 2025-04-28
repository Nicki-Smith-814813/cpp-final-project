#include "utils.h"
#include "scenes/faithSystem.h"
#include "scenes/scene_05_epicIII.h"
#include "characters.h"

void scene_05_epicIII(Character& player) {
    displayDialogue("The Fates circle around Hades, whispering in his ear with venomous doubt.");
    displaySpeakerDialogue("Fates","'Are you sure about this, Hades? Letting them go? It could unravel everything you've built,'");
    displayDialogue("The fates hiss like a serpent waiting to strike.");
    displaySpeakerDialogue("Fates","'You should have kept her here, where she belongs.'");
    displayDialogue("they continue, their voices like a dark wind.");

    displayDialogue("Hades looks uncertain, the Fates' words lingering in his mind.");
    displaySpeakerDialogue("Hades","'I... I don’t know,'");
    displayDialogue("Hades mutters.");
    displaySpeakerDialogue("Hades", "'But if they leave, will the system hold? Will everything fall apart?'");
    displaySpeakerDialogue("Persephone","'You will never know unless you give him a chance,'");
    displayDialogue("Persephone says softly, but firmly, stepping forward.");
    displaySpeakerDialogue("Persephone","'Give him the opportunity. I believe in him.'");

    displayDialogue("Hades sighs, staring at Orpheus, his expression hard to read.");
    displaySpeakerDialogue("Hades","'Alright, Orpheus. One last chance. Show me you’re worthy. I’ll give you a musical challenge. If you succeed, you and Eurydice can leave Hadestown. Fail... and you’ll remain here forever.'");

    displaySpeakerDialogue("Hades","'But understand this, Orpheus,'");
    displayDialogue("Hades continues, his voice lowering to a grave tone.");
    displaySpeakerDialogue("Hades","'If you succeed, Eurydice will be free... but she will remain behind, in the shadows. You will lead her out of Hadestown, but if you look back... if you turn your gaze to see her, even once, all will be lost.'");

    displayDialogue("The weight of Hades' words hangs in the air. The challenge is not just to leave... but to trust that Eurydice is behind him, without looking back.");

    // Call the musical game
    bool orpheusSuccess = musicalGame();

    if (orpheusSuccess) {
        // Orpheus wins the game and convinces Hades
        displayDialogue("Hades nods, his face softening.");
        displaySpeakerDialogue("Hades","'You’ve done it, Orpheus. Go. Be with Eurydice. But remember, the moment you look back... it's over.'");
    } else {
        // Orpheus fails, give another chance
        displaySpeakerDialogue("Hades","'You failed, Orpheus.'");
        displayDialogue("Hades says coldly.");
        displaySpeakerDialogue("Hades","'But I'll give you one more chance. Try again.'");

        // Second chance to play the musical game
        orpheusSuccess = musicalGame();

        if (orpheusSuccess) {
            displayDialogue("Hades nods reluctantly.");
            displaySpeakerDialogue("Hades", "'Fine. You’ve convinced me. Go.'");
        } else {
            // If the player fails twice, Persephone intervenes
            displaySpeakerDialogue("Persephone","'That’s enough, Hades!'");
            displayDialogue("Persephone exclaims, stepping forward.");
            displaySpeakerDialogue("Persephone", "He’s tried his best, and that’s all that matters! Let them go. You owe them that much.'");
            displayDialogue("Hades looks at Persephone, then at Orpheus, and finally gives in.");
            displaySpeakerDialogue("Hades","'Alright, alright. Fine. You may leave Hadestown... but remember, Orpheus, this is your last chance. And don't look back.'");
        }
    }
}