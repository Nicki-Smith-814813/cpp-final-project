#include "utils.h"
#include "scenes/scene_04_chantII.h"
#include "scenes/faithSystem.h"
#include "characters.h"
// Function to handle the chantII scene
void chantII(Character& player) {
    displayDialogue("Hades stands before Orpheus, a smirk crossing his face as he issues the challenge.\n");
    displayDialogue("'Alright, Orpheus,' Hades says, 'Let’s see if you can keep up. We’re going to play a little game. It's a Hades says challenge. If you succeed, I'll let you play your song. If you fail... well, let's just say you'll need someone to speak on your behalf.'\n");

    // Call the Hades says challenge
    bool orpheusSuccess = hadesSaysChallenge();

    if (orpheusSuccess) {
        // Orpheus wins the Hades says challenge
        displayDialogue("'Well done, Orpheus,' Hades grins, stepping aside. 'You’ve earned your chance. Now, play me that song. Let’s see if you can truly convince me.'\n");
    } else {
        // Orpheus fails, Persephone steps in
        displayDialogue("'That was... less than impressive,' Hades chuckles darkly.\n");
        displayDialogue("'I can't believe you failed that,' Persephone says, stepping forward, a little amused but mostly concerned. 'Hades, you can't be serious. Let him play the song. He deserves the chance.'\n");
        displayDialogue("Hades hesitates, his gaze softening slightly as he looks at Persephone.\n");
        displayDialogue("'Fine,' he sighs. 'But only because you’ve asked me to.'\n");
        displayDialogue("Persephone smiles at Orpheus, giving him a reassuring nod. 'You’ve got this, Orpheus. Don’t let him win just yet.'\n");
    }
}