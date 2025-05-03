#include "utils.h"
#include "scenes/scene_03_howLong.h"
#include "characters.h"



void scene_03_howLong() {

    printAsciiArt("wine.txt");
    
    displayDialogue("The scene opens in the grand, dimly lit quarters of the Underworld’s ruling couple.\n");
    displayDialogue("Persephone is pacing, clearly agitated, while Hades remains seated, his brow furrowed as he stares into the distance.\n");

    // Dialogue between Hades and Persephone
    displaySpeakerDialogue("Persephone","Persephone:'Hades, you can't just keep things the way they are!");
    displaySpeakerDialogue("Persephone","Persephone:'Orpheus deserves the chance to bring Eurydice back.");
    displaySpeakerDialogue("Persephone","Persephone:'If you don't let him go, it will only make things worse.'");

    displaySpeakerDialogue("Hades","Hades:(calmly, but with tension in his voice)'You think I don't know that? I care about Orpheus, I do. But allowing one person to leave... What happens when others see that? The whole system will collapse.'");

    displaySpeakerDialogue("Persephone","(passionately): 'You don't get it, do you? You're not seeing the bigger picture!'");
    displaySpeakerDialogue("Persephone","Persephone:'You think I'm here because of all of this—this throne, this power.'");
    dramaticPause(500);
    displaySpeakerDialogue("Persephone","Persephone:'But it’s you I want, not the riches or the walls of this place!'");
    displaySpeakerDialogue("Persephone","Persephone:'You’re so focused on maintaining control that you’ve forgotten how to love me.'");

    displaySpeakerDialogue("Hades","Hades(looking away, voice filled with regret):");
    dramaticPause(500);
    displaySpeakerDialogue("Hades","Hades:'Everything I do... I do it out of love for you. I want to keep you safe, to make sure you're not lost, but it feels like I’m losing you anyway. I’ve built this place for you, for us. Can’t you see that?'");

    displaySpeakerDialogue("Persephone","Persphone:(stops pacing, turning to him, hurt): 'You built a world, Hades...'");
    dramaticPause(500);
    displaySpeakerDialogue("Persephone","Persephone:'But not one where I feel like I belong. I don’t need the bright lights of the world above. I need you. Just YOU.'");
    displaySpeakerDialogue("Persephone","Persphone:'But you’ve become a ghost in your own kingdom.'");

    displaySpeakerDialogue("Hades","Hades(his voice cracks slightly): 'I’m not a ghost. I’m just...'");
    dramaticPause(500);
    displaySpeakerDialogue("Hades","Hades:'...scared. I don’t know how to fix what’s broken.'");
    displaySpeakerDialogue("Hades","Hades:'And I fear that if I allow even one person to leave Hadestown, it will all fall apart.'");
    displaySpeakerDialogue("Hades","Hades:'The power I’ve built... I’ve worked my whole life to make sure it stands.'");

    displaySpeakerDialogue("Persephone","Persephone:(softly, with a gentle but firm tone): 'I understand your fear. But you can’t rule everything. And you can’t keep me here with your walls.'");
    displaySpeakerDialogue("Persephone","Persephone:'If you love me, show me that you’re willing to fight for us—'");
    dramaticPause(500);
    displaySpeakerDialogue("Persephone","Persephone:'by trusting in love, not power.'");

    displaySpeakerDialogue("Hades","(pauses, looking at her with longing, but still uncertain): 'And if everything falls apart? If this all ends, what then?'");

    displaySpeakerDialogue("Persephone","(sighing, looking at him with a mix of sadness and affection): 'Maybe it’s time for something different, Hades.'");
    displaySpeakerDialogue("Persephone","Persephone:'Time to trust that love can heal us, instead of more control.'");

    // Scene ends with unresolved tension, leaving the player to reflect on their relationship
    displayDialogue("There’s a long silence between them. Hades’ eyes meet Persephone’s, but neither knows how to bridge the gap that’s formed between them.");
    displayDialogue("The tension hangs thick in the air as the conversation fades. But for now, no more words are spoken.");
    displayDialogue("The weight of the Underworld looms over them both.");
}
