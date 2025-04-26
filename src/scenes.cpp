// scenes.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "scenes.h"
#include "characters.h"
#include <vector>
using namespace std;

// Function to display dialogue
void displayDialogue(const std::string& dialogue) {
    std::cout << dialogue << "\n\n";
}

// Hermes’ narration to set the stage
void hermesNarration() {
    std::cout << "Hermes speaks with a playful yet knowing tone...\n\n";
    displayDialogue("Ah, Orpheus, a dreamer with a heart full of music... But your journey, my friend, is not one of simple melodies. "
                    "You seek Eurydice, the woman who follows you without question—her heart steadfast in faith, while your own is tangled in the notes of hope.\n");
    displayDialogue("But beware, the Fates are watching... they offer glittering promises, but remember—they do not offer salvation. "
                    "Hadestown isn’t a gold mine; it’s a graveyard. It is a place of forgotten songs, where dreams go to die.\n");
    displayDialogue("And then there is Persephone, caught between the bottle and the man who once loved her. The cold silence of Hades, the wall he’s built around his heart—"
                    "but love... love doesn’t stay silent for long, Orpheus. Not even in the depths of the underworld.\n");
}

// Function for dialogue with Eurydice
void talkToEurydice(Character& player) {
    std::vector<std::string> choices = {
        "Tell Eurydice: 'Hadestown is a graveyard, not a gold mine. Don't believe the Fates.'",
        "Tell Eurydice: 'The Fates speak only truth. Maybe you should listen to them.'",
        "Stay silent and let Eurydice decide on her own."
    };

    std::cout << "You approach Eurydice...\n\n";
    displayDialogue("Eurydice stands before you, her eyes tired but filled with that same unyielding faith she’s always had in you. "
                    "She listens to the Fates, their promises of a better life, a life where she’s not cold and hungry. But you know her better than anyone.\n");

    // Displaying choices
    std::cout << "Choose what to say to Eurydice:\n";
    for (size_t i = 0; i < choices.size(); ++i) {
        std::cout << i + 1 << ". " << choices[i] << "\n";
    }

    int choice = 0;
    while (true) {
        std::cin >> choice;
        if (choice >= 1 && choice <= 3) break;
        else std::cout << "Please choose a valid option (1-3): ";
    }

    switch (choice) {
        case 1:
            displayDialogue("You speak softly but firmly: 'Hadestown is a graveyard, Eurydice. It may glitter with gold, but it will take everything from you, piece by piece.'");
            player.faith += 2; // Boost faith, as Orpheus speaks from the heart, warning her of the truth.
            break;
        case 2:
            displayDialogue("You say with conviction: 'The Fates speak only truth, Eurydice. This is your chance to leave all the suffering behind. Don’t turn your back on it.'");
            player.trust += 1; // Boost trust, as Orpheus tries to guide her, but in a more pragmatic way.
            break;
        case 3:
            displayDialogue("You remain silent. Eurydice gazes at you, but her expression betrays a flicker of doubt. She sighs, then looks away.");
            break;
        default:
            std::cout << "Invalid choice.\n";
    }
}

// Persephone and Hades' bickering (simple dialogue)
void persephoneAndHadesConflict() {
    displayDialogue("In the distance, the echoes of Persephone and Hades' argument reach your ears. Their voices are sharp, filled with frustration.\n");
    displayDialogue("'You’re shutting me out, Hades!' Persephone's voice cracks, the alcohol slurring her words. 'I’m doing the best I can to survive down here, but you—' she breaks off in a sob.\n");
    displayDialogue("'You think I don’t care, Persephone? I’m doing what I must to keep this place running!' Hades growls, his tone colder than the underworld itself. 'This is bigger than us.'\n");
    displayDialogue("Their words stab at each other, but neither can break the walls they’ve built between them.\n");
}
void forageForResources() {
    srand(time(0)); // Seed random number generator

    int woodGathered = 0;
    int foodGathered = 0;

    // Let the player gather resources
    cout << "You and Eurydice head out into the woods to gather food and firewood.\n";
    cout << "You have some time, but not a lot, and you need to make the most of it.\n";

    // Foraging attempt: the player gathers a mix of wood and food.
    for (int i = 0; i < 3; ++i) {
        int outcome = rand() % 2; // Random success (0 or 1)
        if (outcome == 0) {
            woodGathered++;
            cout << "You successfully gather some firewood.\n";
        } else {
            foodGathered++;
            cout << "You find some food to bring back.\n";
        }
    }

    // After foraging, check how well the player did
    cout << "You return to Eurydice with your haul.\n";

    if (woodGathered >= 2 && foodGathered >= 2) {
        displayDialogue("You’ve done well gathering enough food and firewood. Eurydice seems satisfied and relieved.");
    } else {
        displayDialogue("Eurydice seems worried. You didn’t gather enough food or firewood.");
    }

    // Now, no matter what, the snake bite happens
    displayDialogue("Suddenly, while gathering firewood, Eurydice steps on a snake! She screams in pain and falls to the ground.");
    displayDialogue("You rush to her aid. The venom is spreading quickly. Eurydice’s fate is uncertain...\n");
}

// Chant I: The initial moment where Orpheus and Eurydice are brought together.
void chantI() {
    displayDialogue("The journey begins... Orpheus, your music has the power to heal, but does it have the power to save?\n");
    displayDialogue("You see Eurydice across the distance, her figure shimmering with uncertainty. But in her eyes, there is hope—a fragile hope.\n");
    displayDialogue("'Eurydice... I'm coming for you,' you say, heart pounding, determined to overcome whatever stands in your way.\n");
    displayDialogue("The road to Hadestown is long, and the Fates are watching...\n");

    // Player makes a choice: Listen to Eurydice's concerns or stay focused on the song
    int choice;
    cout << "Do you want to listen to Eurydice's concerns about food and firewood?\n";
    cout << "1. Listen to her concerns.\n";
    cout << "2. Stay focused on the song.\n";
    cout << "Enter 1 or 2: ";
    cin >> choice;

    if (choice == 1) {
        forageForResources(); // Transition to foraging simulator
    } else {
        displayDialogue("You remain focused on your song, determined to bring the seasons back in tune.\n");
        displayDialogue("But Eurydice seems troubled, her eyes glancing at the sparse surroundings. You feel a sense of unease...\n");
    }
}

// Initialize faith variable
float faith = 100.0f;  // Start with full faith

// Helper function to display dialogue
void displayDialogue(const string& dialogue) {
    cout << dialogue << "\n\n";
}

// Function to handle Fates' questions
void mythQuestions() {
    int correctAnswers = 0;

    cout << "The Fates swirl around you, their voices sharp and mocking.\n";
    cout << "'Let's see if you truly understand the world you're trying to change,' they sneer.\n";
    
    // Question 1
    cout << "Who was the hero that completed the Twelve Labors?\n";
    cout << "1. Perseus\n";
    cout << "2. Heracles\n";
    cout << "3. Theseus\n";
    cout << "Enter your answer (1, 2, or 3): ";
    int answer;
    cin >> answer;
    if (answer == 2) {
        cout << "Correct! Heracles did complete the Twelve Labors.\n";
        correctAnswers++;
        faith += 10;  // Gain faith for the correct answer
    } else {
        cout << "Wrong! The correct answer is Heracles.\n";
        faith -= 10;  // Lose faith for the wrong answer
    }

    // Question 2
    cout << "Who turned into a spider after being defeated by Athena in a weaving contest?\n";
    cout << "1. Medusa\n";
    cout << "2. Arachne\n";
    cout << "3. Hera\n";
    cout << "Enter your answer (1, 2, or 3): ";
    cin >> answer;
    if (answer == 2) {
        cout << "Correct! Arachne was turned into a spider.\n";
        correctAnswers++;
        faith += 10;
    } else {
        cout << "Wrong! The correct answer is Arachne.\n";
        faith -= 10;
    }

    // Question 3
    cout << "Who was cursed to turn everything they touched into gold?\n";
    cout << "1. Midas\n";
    cout << "2. King Minos\n";
    cout << "3. Persephone\n";
    cout << "Enter your answer (1, 2, or 3): ";
    cin >> answer;
    if (answer == 1) {
        cout << "Correct! King Midas turned everything he touched into gold.\n";
        correctAnswers++;
        faith += 10;
    } else {
        cout << "Wrong! The correct answer is Midas.\n";
        faith -= 10;
    }

    // End the question section
    if (correctAnswers >= 2) {
        displayDialogue("The Fates seem to soften their stance, impressed with your knowledge.");
    } else {
        displayDialogue("The Fates sneer. 'Not enough knowledge to change the fate of others.'");
    }

    cout << "Your current faith level: " << faith << "%\n";
}

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

void howLong() {
    displayDialogue("The scene opens in the grand, dimly lit quarters of the Underworld’s ruling couple.\n");
    displayDialogue("Persephone is pacing, clearly agitated, while Hades remains seated, his brow furrowed as he stares into the distance.\n");

    // Dialogue between Hades and Persephone
    displayDialogue("Persephone: 'Hades, you can't just keep things the way they are! Orpheus deserves the chance to bring Eurydice back. If you don't let him go, it will only make things worse.'\n");

    displayDialogue("Hades (calmly, but with tension in his voice): 'You think I don't know that? I care about Orpheus, I do. But allowing one person to leave... What happens when others see that? The whole system will collapse.'\n");

    displayDialogue("Persephone (passionately): 'You don't get it, do you? You're not seeing the bigger picture! You think I'm here because of all of this—this throne, this power. But it’s you I want, not the riches or the walls of this place! You’re so focused on maintaining control that you’ve forgotten how to love me.'\n");

    displayDialogue("Hades (looking away, voice filled with regret): 'Everything I do... I do it out of love for you. I want to keep you safe, to make sure you're not lost, but it feels like I’m losing you anyway. I’ve built this place for you, for us. Can’t you see that?'\n");

    displayDialogue("Persephone (stops pacing, turning to him, hurt): 'You built a world, Hades... But not one where I feel like I belong. I don’t need the bright lights of the world above. I need you. Just you. But you’ve become a ghost in your own kingdom.'\n");

    displayDialogue("Hades (his voice cracks slightly): 'I’m not a ghost. I’m just... scared. I don’t know how to fix what’s broken. And I fear that if I allow even one person to leave Hadestown, it will all fall apart. The power I’ve built... I’ve worked my whole life to make sure it stands.'\n");

    displayDialogue("Persephone (softly, with a gentle but firm tone): 'I understand your fear. But you can’t rule everything. And you can’t keep me here with your walls. If you love me, show me that you’re willing to fight for us—by trusting in love, not power.'\n");

    displayDialogue("Hades (pauses, looking at her with longing, but still uncertain): 'And if everything falls apart? If this all ends, what then?' \n");

    displayDialogue("Persephone (sighing, looking at him with a mix of sadness and affection): 'Maybe it’s time for something different, Hades. Time to trust that love can heal us, instead of more control.'\n");

    // Scene ends with unresolved tension, leaving the player to reflect on their relationship
    displayDialogue("There’s a long silence between them. Hades’ eyes meet Persephone’s, but neither knows how to bridge the gap that’s formed between them.\n");
    displayDialogue("The tension hangs thick in the air as the conversation fades. But for now, no more words are spoken. The weight of the Underworld’s rules looms over them both.\n");
}
// Function to simulate the hades says challenge
bool hadesSaysChallenge() {
    string playerInput;
    int score = 0;

    // Commands for the hades says challenge
    string commands[] = {
        "Hades says touch your nose.",
        "Touch your toes.",
        "Hades says clap your hands.",
        "Spin around.",
        "Hades says raise your right hand."
    };

    // Number of hades says commands to give
    int numCommands = 5;

    // Seed the random number generator
    srand(time(0));

    // Hades says game loop
    for (int i = 0; i < numCommands; ++i) {
        int randCommand = rand() % 5; // Choose a random command

        // If the command is "Hades says" or not
        if (randCommand % 2 == 0) { // Even numbers are "Hades says" commands
            displayDialogue(commands[randCommand]);  // Display the command

            // Get player's input (responding "yes" or "no")
            cout << "Did you follow the command? (yes/no): ";
            cin >> playerInput;

            // Check if player responded correctly
            if (playerInput == "yes") {
                score++;
            } else {
                displayDialogue("You failed to follow the command!");
            }
        } else {
            displayDialogue("Do not do anything. (No Hades says!)");

            cout << "Did you follow the command? (yes/no): ";
            cin >> playerInput;

            // If the player does it anyway, they fail
            if (playerInput == "yes") {
                displayDialogue("You were supposed to ignore this command!");
            }
        }
    }

    // Determine success based on the number of correct responses
    if (score == 3) {
        displayDialogue("You successfully followed Hades' commands!");
        return true;  // Player wins
    } else {
        displayDialogue("You failed to follow the commands correctly.");
        return false;  // Player loses
    }
}

// Function to handle the chantII scene
void chantII() {
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
// Function to simulate the musical game (matching a simple melody or rhythm)
bool musicalGame() {
    string playerInput;
    int score = 0;

    // A simple sequence of notes (or rhythm) for Orpheus to follow
    string notes[] = {"Do", "Re", "Mi", "Fa", "So"};
    int numNotes = 5;

    // Seed the random number generator
    srand(time(0));

    // Start the musical game
    displayDialogue("Hades leans back, watching Orpheus with a calculating gaze.\n");
    displayDialogue("'Alright, Orpheus,' Hades says, 'Let’s see if you can truly sing your way out of this place. Follow the sequence and show me you're worthy of leaving Hadestown.'\n");

    // Generate a random sequence of notes (a simple melody)
    int melody[3];
    for (int i = 0; i < 3; ++i) {
        melody[i] = rand() % numNotes;  // Randomly select notes
    }

    // Display the melody for the player to follow
    displayDialogue("Here’s the melody. Follow it.\n");
    for (int i = 0; i < 3; ++i) {
        cout << notes[melody[i]] << " ";
    }
    cout << "\n";

    // Ask the player to repeat the melody
    cout << "Enter the melody sequence (Do, Re, Mi, Fa, So): ";
    for (int i = 0; i < 3; ++i) {
        cin >> playerInput;
        
        // Check if player’s input matches the generated melody
        if (playerInput == notes[melody[i]]) {
            score++;
        } else {
            displayDialogue("You missed a note! Try again.\n");
            return false;  // Player failed, return false
        }
    }

    // If the player matches the entire melody
    if (score == 3) {
        displayDialogue("'Well done, Orpheus,' Hades says, clearly impressed. 'You’ve earned it. You and Eurydice may leave Hadestown.'\n");
        return true;  // Player succeeded
    }

    return false;  // Player failed
}

// Function to handle the epicIII scene
void epicIII() {
    displayDialogue("The Fates circle around Hades, whispering in his ear with venomous doubt.\n");
    displayDialogue("'Are you sure about this, Hades? Letting them go? It could unravel everything you've built,' they hiss.\n");
    displayDialogue("'You should have kept her here, where she belongs,' they continue, their voices like a dark wind.\n");

    displayDialogue("Hades looks uncertain, the Fates' words lingering in his mind.\n");
    displayDialogue("'I... I don’t know,' Hades mutters. 'But if they leave, will the system hold? Will everything fall apart?'\n");
    displayDialogue("'You will never know unless you give him a chance,' Persephone says softly, but firmly, stepping forward. 'Give him the opportunity. I believe in him.'\n");

    displayDialogue("Hades sighs, staring at Orpheus, his expression hard to read.\n");
    displayDialogue("'Alright, Orpheus. One last chance. Show me you’re worthy. I’ll give you a musical challenge. If you succeed, you and Eurydice can leave Hadestown. Fail... and you’ll remain here forever.'\n");

    // Add the "do not look back" restriction and mention Eurydice's fate
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

// Function for the roadtohell epilogue
void roadtohell() {
    // Assuming the faith variable is already defined globally or accessible here
    extern int faith;  // Faith should be updated in doubtcomesin() to reflect the player's choice

    // Intro by Hermes
    displayDialogue("Hermes' voice, now soft and sorrowful, fills the air...\n");

    // Check outcome based on faith value
    if (faith < 50) {
        // If Orpheus looked back and failed
        displayDialogue("Hermes sighs deeply, his voice full of mourning.\n");
        displayDialogue("'Orpheus, you were so close... Yet doubt led you astray. The journey, once so full of hope, has ended in despair. You turned back, and in that moment, Eurydice was lost once more. The Underworld claims her again.'\n");
        displayDialogue("'But there is a sliver of light in the darkness. Though Orpheus has failed, love is not entirely lost. Hades and Persephone, the gods of this place, have found something anew in their shared grief and longing. Perhaps there is hope for them, even if Orpheus' fate is sealed.'\n");
        displayDialogue("Hermes pauses, his voice heavy.\n");
        displayDialogue("'There will be no second chances. Orpheus and Eurydice will never again walk the earth together. This tale, tragic as it is, has come to its bitter end.'\n");
        displayDialogue("'But love, true as it is, will find its way. And maybe... just maybe, the gods will find their way too.'\n");
    } else {
        // If Orpheus succeeded and didn't look back
        displayDialogue("Hermes' voice brightens, filled with a note of joy.\n");
        displayDialogue("'And so, Orpheus did it! Against all odds, he walked the long path out of the Underworld with Eurydice behind him. The curse was broken. They were free!' \n");
        displayDialogue("'Together, they returned to the world above, their love stronger than ever. Orpheus' song became a hymn of victory, echoing through the world as a testament to the power of belief and love.'\n");
        displayDialogue("'And there is more. The bond between Hades and Persephone, strained for so long, was mended. Through the trials and heartache, they rediscovered the spark that once united them. Their love, too, found new life, rekindled like the warmth of a fire in the coldest of winters.'\n");
        displayDialogue("'For Orpheus and Eurydice, the road ahead is bright with hope. For Hades and Persephone, perhaps there is now a chance at peace.'\n");
        displayDialogue("'And so, the story of Orpheus and Eurydice finds its ending. But as always, the Fates watch. Will it be happiness or heartache next? Only time will tell.'\n");
        displayDialogue("'For now, we can say this: Orpheus won his freedom. And love... love has a way of prevailing.'\n");
    }

    // Final narration from Hermes
    displayDialogue("Hermes' voice fades as the scene comes to a close, leaving you with the feeling that no matter the outcome, the story of Orpheus will echo through eternity.\n");
    displayDialogue("The End...\n");
}