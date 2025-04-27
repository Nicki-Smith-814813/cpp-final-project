#include "utils.h"
#include "faithSystem.h"
#include "scene_05_epicIII.h"


void epicIII() {
    displayDialogue("The Fates circle around Hades, whispering in his ear with venomous doubt.\n");
    displayDialogue("'Are you sure about this, Hades? Letting them go? It could unravel everything you've built,' they hiss.\n");
    displayDialogue("'You should have kept her here, where she belongs,' they continue, their voices like a dark wind.\n");

    displayDialogue("Hades looks uncertain, the Fates' words lingering in his mind.\n");
    displayDialogue("'I... I don’t know,' Hades mutters. 'But if they leave, will the system hold? Will everything fall apart?'\n");
    displayDialogue("'You will never know unless you give him a chance,' Persephone says softly, but firmly, stepping forward. 'Give him the opportunity. I believe in him.'\n");

    displayDialogue("Hades sighs, staring at Orpheus, his expression hard to read.\n");
    displayDialogue("'Alright, Orpheus. One last chance. Show me you’re worthy. I’ll give you a musical challenge. If you succeed, you and Eurydice can leave Hadestown. Fail... and you’ll remain here forever.'\n");

    displayDialogue("'But understand this, Orpheus,' Hades continues, his voice lowering to a grave tone. 'If you succeed, Eurydice will be free... but she will remain behind, in the shadows. You will lead her out of Hadestown, but if you look back... if you turn your gaze to see her, even once, all will be lost.'\n");

    displayDialogue("The weight of Hades' words hangs in the air. The challenge is not just to leave... but to trust that Eurydice is behind him, without looking back.\n");

    // Call the musical game
    bool orpheusSuccess = musicalGame();

    if (orpheusSuccess) {
        // Orpheus wins the game and convinces Hades
        displayDialogue("Hades nods, his face softening. 'You’ve done it, Orpheus. Go. Be with Eurydice. But remember, the moment you look back... it's over.'\n");
    } else {
        // Orpheus fails, give another chance
        displayDialogue("'You failed, Orpheus,' Hades says coldly. 'But I'll give you one more chance. Try again.'\n");

        // Second chance to play the musical game
        orpheusSuccess = musicalGame();

        if (orpheusSuccess) {
            displayDialogue("Hades nods reluctantly, 'Fine. You’ve convinced me. Go.'\n");
        } else {
            // If the player fails twice, Persephone intervenes
            displayDialogue("'That’s enough, Hades!' Persephone exclaims, stepping forward. 'He’s tried his best, and that’s all that matters! Let them go. You owe them that much.'\n");
            displayDialogue("Hades looks at Persephone, then at Orpheus, and finally gives in.\n");
            displayDialogue("'Alright, alright. Fine. You may leave Hadestown... but remember, Orpheus, this is your last chance. And don't look back.'\n");
        }
    }
}