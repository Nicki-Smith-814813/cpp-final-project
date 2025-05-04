#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <limits>
#include <sstream>
#include <cmath>  // for abs()
#include "scenes/faithSystem.h"
#include "characters.h"
#include "utils.h"

using namespace std;

void increaseFaith(Character& player, float amount) {
    player.faith += amount;
    if (player.faith > 100.0f) player.faith = 100.0f;
}

void decreaseFaith(Character& player, float amount) {
    player.faith -= amount;
    if (player.faith < 0.0f) player.faith = 0.0f;
}

void mythQuestions(Character& player) {
    printAsciiArt("fates.txt");

         static vector<MythQuestion> easyQuestions = {
            {"Who is the king of the gods?", {"Zeus", "Poseidon", "Hades"}, 0},
            {"Who is the goddess of love?", {"Aphrodite", "Hera", "Athena"}, 0},
            {"What is the name of the winged horse?", {"Pegasus", "Hydra", "Cerberus"}, 0},
            {"Who has a lightning bolt?", {"Zeus", "Apollo", "Hermes"}, 0},
            {"Who is Hades' wife?", {"Persephone", "Hera", "Athena"}, 0},
            {"What is the underworld river of forgetfulness?", {"Lethe", "Styx", "Acheron"}, 0},
            {"Who opened Pandora's box?", {"Pandora", "Medusa", "Artemis"}, 0},
            {"Who was the god of war?", {"Ares", "Apollo", "Hermes"}, 0},
            {"Which god ruled the sea?", {"Poseidon", "Zeus", "Hephaestus"}, 0},
            {"What creature had snakes for hair?", {"Medusa", "Hydra", "Chimera"}, 0},
            {"What was Medusa turned into?", {"Gorgon", "Siren", "Harpy"}, 0},
            {"Who is the messenger god?", {"Hermes", "Apollo", "Ares"}, 0},
            {"Who is the sun god?", {"Apollo", "Helios", "Zeus"}, 0},
            {"Which god is associated with wine?", {"Dionysus", "Hermes", "Ares"}, 0},
            {"Who was the goddess of the hunt?", {"Artemis", "Athena", "Hera"}, 0},
            {"Which goddess was born from sea foam?", {"Aphrodite", "Athena", "Demeter"}, 0},
            {"Who built the labyrinth?", {"Daedalus", "Minos", "Icarus"}, 0},
            {"Who flew too close to the sun?", {"Icarus", "Perseus", "Achilles"}, 0},
            {"Which hero used a lyre?", {"Orpheus", "Heracles", "Theseus"}, 0},
            {"What is Mount Olympus?", {"Home of the gods", "Underworld", "Battlefield"}, 0}
        };
    
        static vector<MythQuestion> mediumQuestions = {
            {"Who is the goddess of wisdom?", {"Athena", "Artemis", "Hera"}, 0},
            {"Who killed the Minotaur?", {"Theseus", "Heracles", "Perseus"}, 0},
            {"Which hero slew Medusa?", {"Perseus", "Theseus", "Achilles"}, 0},
            {"Who was chained to a rock for stealing fire?", {"Prometheus", "Sisyphus", "Atlas"}, 0},
            {"Which hero completed twelve labors?", {"Heracles", "Theseus", "Jason"}, 0},
            {"Who was punished by rolling a boulder uphill?", {"Sisyphus", "Tantalus", "Prometheus"}, 0},
            {"Who was cursed to turn everything to gold?", {"Midas", "Minos", "Orpheus"}, 0},
            {"Who ferried souls across the Styx?", {"Charon", "Hades", "Hermes"}, 0},
            {"Who is the mother of Persephone?", {"Demeter", "Hera", "Aphrodite"}, 0},
            {"Who did Paris choose as the fairest?", {"Aphrodite", "Athena", "Hera"}, 0},
            {"Which god forged weapons?", {"Hephaestus", "Ares", "Hermes"}, 0},
            {"Who was turned into a spider?", {"Arachne", "Medusa", "Hera"}, 0},
            {"Which hero led the Argonauts?", {"Jason", "Perseus", "Odysseus"}, 0},
            {"Who solved the Sphinx's riddle?", {"Oedipus", "Orpheus", "Theseus"}, 0},
            {"Who was the wife of Odysseus?", {"Penelope", "Helen", "Andromache"}, 0},
            {"Who gave fire to mankind?", {"Prometheus", "Epimetheus", "Hermes"}, 0},
            {"Which monster had multiple heads?", {"Hydra", "Cerberus", "Chimera"}, 0},
            {"Who turned into a laurel tree?", {"Daphne", "Calliope", "Andromeda"}, 0},
            {"What guarded the Underworld?", {"Cerberus", "Hydra", "Chimera"}, 0},
            {"Which hero had a weak heel?", {"Achilles", "Odysseus", "Perseus"}, 0}
        };
    
        static vector<MythQuestion> hardQuestions = {
            {"Who was cursed to eternal thirst?", {"Tantalus", "Sisyphus", "Prometheus"}, 0},
            {"Which god carried the heavens?", {"Atlas", "Cronus", "Hyperion"}, 0},
            {"Who turned Actaeon into a stag?", {"Artemis", "Hera", "Athena"}, 0},
            {"Which muse inspired epic poetry?", {"Calliope", "Clio", "Erato"}, 0},
            {"Who is the goddess of retribution?", {"Nemesis", "Nike", "Nyx"}, 0},
            {"Which Titan ruled during the Golden Age?", {"Cronus", "Oceanus", "Hyperion"}, 0},
            {"What creature is part lion, goat, and snake?", {"Chimera", "Cerberus", "Sphinx"}, 0},
            {"What did Persephone eat in the Underworld?", {"Pomegranate seeds", "Olives", "Grapes"}, 0},
            {"Who is the personification of night?", {"Nyx", "Selene", "Eos"}, 0},
            {"What did Orpheus use to charm Hades?", {"Lyre", "Flute", "Panpipes"}, 0},
            {"Who was the father of the Minotaur?", {"Minos", "Poseidon", "Zeus"}, 0},
            {"What caused Narcissus' death?", {"His reflection", "A curse", "Hera"}, 0},
            {"Which god is twin to Artemis?", {"Apollo", "Ares", "Hermes"}, 0},
            {"What is the name of Hades' helm?", {"Helm of Darkness", "Aegis", "Cap of Invisibility"}, 0},
            {"Which creature is a winged lion with a human face?", {"Sphinx", "Chimera", "Griffin"}, 0},
            {"Who was the mother of Dionysus?", {"Semele", "Rhea", "Leto"}, 0},
            {"Which river must souls cross?", {"Styx", "Lethe", "Phlegethon"}, 0},
            {"Who was punished by having his liver eaten daily?", {"Prometheus", "Tantalus", "Sisyphus"}, 0},
            {"What creature lured sailors with song?", {"Sirens", "Harpies", "Nymphs"}, 0},
            {"What guards the Golden Fleece?", {"Dragon", "Hydra", "Giant"}, 0}
        };
    
        // Fates dialogue by difficulty
        vector<string> correctEasy = {
            "*A lucky guess?*", "*You remember your bedtime stories well.*",
            "*The thread wavers... but does not break.*", "*Even the young get it right sometimes.*"
        };
        vector<string> wrongEasy = {
            "*Tsk, tsk. You weren't paying attention, were you?*", "*That’s not how the myths go.*",
            "*Childish mistake.*", "*Even the Muses groan.*"
        };
        vector<string> correctMedium = {
            "*Hmm. Perhaps there's knowledge in that skull after all.*", "*The thread shimmers faintly...*",
            "*Still standing. Surprising.*", "*Not bad for a mortal.*"
        };
        vector<string> wrongMedium = {
            "*Wrong. The thread snaps ever tighter.*", "*Your grasp of myth is... fragile.*",
            "*Do you even listen when the bards sing?*", "*Another stumble on the staircase to ruin.*"
        };
        vector<string> correctHard = {
            "*You’ve done your homework. Hmph.*", "*A mortal mind sharp enough to cut fate? Intriguing.*",
            "*The tapestry shifts. We didn't expect that.*", "*Very few know that one...*"
        };
        vector<string> wrongHard = {
            "*Pathetic. The threads laugh at you.*", "*That answer belongs in Tartarus.*",
            "*Even the shadows know more.*", "*You were not meant to know this, clearly.*"
        };
    
        // Quiz metadata
        struct QuizLevel {
            string name;
            int questionCount;
            int reward;
            int penalty;
            vector<MythQuestion>* questions;
            vector<string> correctLines;
            vector<string> wrongLines;
        };
    
        vector<QuizLevel> levels = {
            {"easy", 3, 3, 2, &easyQuestions, correctEasy, wrongEasy},
            {"medium", 5, 5, 5, &mediumQuestions, correctMedium, wrongMedium},
            {"hard", 7, 7, 10, &hardQuestions, correctHard, wrongHard}
        };
    
        // Run each difficulty level
        for (const QuizLevel& level : levels) {
            displaySpeakerDialogue("Fates", "*Let us test the thread, " + level.name + " ...*");
            randomizedFatesTaunt(player);
    
            vector<MythQuestion> pool = *level.questions;
            random_shuffle(pool.begin(), pool.end());
            vector<MythQuestion> questions(pool.begin(), pool.begin() + level.questionCount);
    
            int correctAnswers = 0;
    
            for (const MythQuestion& q : questions) {
                vector<pair<int, string>> shuffled;
                for (int j = 0; j < 3; ++j)
                    shuffled.push_back({j, q.options[j]});
                random_shuffle(shuffled.begin(), shuffled.end());
    
                cout << "\n" << q.question << "\n";
                for (int i = 0; i < 3; ++i)
                    cout << (i + 1) << ". " << shuffled[i].second << "\n";
    
                int answer = getValidatedInput<int>("Enter your answer (1-3): ", 1, 3);
                int selectedIndex = shuffled[answer - 1].first;
    
                if (selectedIndex == q.correctIndex) {
                    string line = level.correctLines[rand() % level.correctLines.size()];
                    displaySpeakerDialogue("Fates", line);
                    player.faith += level.reward;
                    player.trust += level.reward;
                    if (rand() % 2 == 0) randomizedFatesTaunt(player);
                    correctAnswers++;
                } else {
                    string line = level.wrongLines[rand() % level.wrongLines.size()];
                    displaySpeakerDialogue("Fates", line);
                    player.faith -= level.penalty;
                    player.trust -= level.penalty;
                    randomizedFatesTaunt(player);
                }
    
                player.faith = max(0, min(100, player.faith));
                player.trust = max(0, min(100, player.trust));
            }
    
            if (correctAnswers == level.questionCount) {
                displaySpeakerDialogue("Fates", "*Hmph. Perhaps you *do* know something.*");
            } else if (correctAnswers >= level.questionCount / 2) {
                displaySpeakerDialogue("Fates", "*Barely good enough.*");
            } else {
                displaySpeakerDialogue("Fates", "*Pitiful. Tattered and threadbare.*");
            }
    
            cout << "Faith: " << player.faith << "% | Trust: " << player.trust << "%\n\n";
        }
    
        displayDialogue("The Fates fall silent... for now.");
    }
    
    

    

// Function to simulate the hades says challenge
bool hadesSaysChallenge(Character& player) {

    vector<string> rawCommands = {
        "Stomp", "Bow", "Raise your hands", "Spin", "Touch your toes"
    };

    vector<string> expectedResponses;

    displaySpeakerDialogue("Hades", "Let's see if you can remember, mortal.");
    displayDialogue("He begins issuing commands, one after another...\n");

    for (int i = 0; i < 5; ++i) {
        int cmdIndex = rand() % rawCommands.size();
        bool isTrap = rand() % 2 == 0;

        string command = rawCommands[cmdIndex];

        if (isTrap) {
            displayDialogue(command);
            expectedResponses.push_back(""); // player should stay silent
        } else {
            displayDialogue("Hades says: " + command);
            expectedResponses.push_back(command); // player must match
        }
    }
    randomizedFatesTaunt(player);
    displayDialogue("\nNow, repeat the commands exactly, one at a time.\n");
    displayDialogue("(If no 'Hades says:' before, simply hit enter to skip to the next command.)\n");
    displayDialogue("(Type your responses exactly: example -> Bow)\n");

    int score = 0;

    for (int i = 0; i < 5; ++i) {
        cout << "Command #" << (i + 1) << ": ";
        string response;
        getline(cin, response);

        if (response == expectedResponses[i]) {
            ++score;
        }
    }

    displayDialogue("\nYou got " + to_string(score) + " out of 5 correct.\n");

    // Adjust stats based on performance
    if (score == 5) {
        displaySpeakerDialogue("Hades","'Impressive. Maybe there's hope for you yet.'");
        player.faith += 10;
        player.trust += 10;
    } else if (score >= 3) {
        displaySpeakerDialogue("Hades","'You’re not entirely hopeless.'");
        player.faith += 5;
        player.trust += 5;
    } else {
        displaySpeakerDialogue("Hades","'Pathetic. Try harder next time.'");
        player.faith -= 5;
        player.trust -= 5;
    }

    // Clamp values between 0 and 100
    player.faith = max(0, min(100, player.faith));
    player.trust = max(0, min(100, player.trust));

    return (score >= 3); // return true if pass, false if fail

    cout << "Your current faith level: " << player.faith << "%\n";
}


// Musical challenge
bool musicalGame(Character& player, bool isRetry, int difficultyLevel) {
    if (isRetry) {
        displaySpeakerDialogue("Hades", "'You dare try again, boy? The melody grows longer...'");
    } else {
        displaySpeakerDialogue("Hades", " 'Let's see if you can truly sing your way out of this place.'");
    }

    int flashDelay = 600;
    int eraseDelay = 300;
    int startDelay = 1000;

    int melodyLength;
    if (difficultyLevel == 1) {
        melodyLength = 5;
    } else if (difficultyLevel == 2) {
        melodyLength = 7;
        displaySpeakerDialogue("Fates", " '*The melody grows longer... the threads twist tighter...*'");
    } else {
        melodyLength = 10;
        displaySpeakerDialogue("Fates", " '*The melody is endless, boy... Can you even hear it anymore?*'");
    }

    string notes[] = {"Do", "Re", "Mi", "Fa", "So", "La", "Ti"};
    int numNotes = 7;
    vector<int> melody;

    displayDialogue("Hades leans back, watching Orpheus with an iron gaze...");
    randomizedFatesTaunt(player);
    displaySpeakerDialogue("Hades", " 'Here’s the melody. Listen carefully.'");
    dramaticPause(startDelay);

    for (int i = 0; i < melodyLength; ++i) {
        int noteIndex = rand() % numNotes;
        melody.push_back(noteIndex + 1);
    }

    auto playMelody = [&]() {
        for (int i = 0; i < melodyLength; ++i) {
            int noteIndex = melody[i] - 1;
            cout << notes[noteIndex] << " " << flush;
            dramaticPause(flashDelay);
            cout << "\r      \r" << flush;
            dramaticPause(eraseDelay);
        }
        cout << "\n\n";
    };

    playMelody();

    int replay = getValidatedInput<int>("Do you want to hear the melody again? (1 = Yes, 2 = No): ", 1, 2);
    if (replay == 1) {
        displaySpeakerDialogue("Fates", " '*Listen once more...*'");
        dramaticPause(500);
        playMelody();
        randomizedFatesTaunt(player);
    }

    cout << "Enter the melody using numbers (1=Do,2=Re,3=Mi,4=Fa,5=So,6=La,7=Ti), separated by spaces:\n> ";
    string inputLine;
    getline(cin >> ws, inputLine);

    istringstream iss(inputLine);
    vector<int> playerSequence;
    int n;

    while (iss >> n) {
        if (n >= 1 && n <= 7) {
            playerSequence.push_back(n);
        } else {
            displaySpeakerDialogue("Fates", " '*You played a forbidden note...*'");
            player.faith -= 5;
            player.trust -= 3;
            player.faith = max(0, player.faith);
            player.trust = max(0, player.trust);
            return false;
        }
    }

    if (playerSequence.size() != static_cast<size_t>(melodyLength)) {
        displaySpeakerDialogue("Fates", " '*The sequence is the wrong length. Are you guessing?*'");
        player.faith -= 5;
        player.trust -= 3;
        player.faith = max(0, player.faith);
        player.trust = max(0, player.trust);
        return false;
    }

    int correct = 0;
    for (int i = 0; i < melodyLength; ++i) {
        if (playerSequence[i] == melody[i]) {
            correct++;
        }
    }

    int mistakes = melodyLength - correct;

    if (mistakes == 0) {
        displaySpeakerDialogue("Hades", " 'Impressive. Your memory serves you well.'");
        player.faith += 10;
        player.trust += 10;
    } else if (mistakes <= 2) {
        displaySpeakerDialogue("Fates", " '*Close enough... the thread trembles but does not break.*'");
        player.faith += 5;
        player.trust += 5;
    } else {
        displaySpeakerDialogue("Fates", " '*You falter... the thread snaps.*'");
        player.faith -= 10;
        player.trust -= 5;
        player.faith = max(0, player.faith);
        player.trust = max(0, player.trust);
        return false;
    }

    player.faith = min(100, player.faith);
    player.trust = min(100, player.trust);

    cout << "Your current faith level: " << player.faith << "%\n";
    return true;
}


// --------------------------------
// Randomized Fate Taunt Function
// --------------------------------
void randomizedFatesTaunt(const Character& player) 
{
    vector<string> strongFaithTaunts = {
        "*Strong thread yet, little songbird... but can you hold it?*",
        "*A golden thread, spun tight... but even gold can snap.*",
        "*You shine still... will you survive the loom?*",
        "*So sure of your steps... pride makes a beautiful noose.*",
        "*Confidence suits you... until it doesn't.*",
        "*Your faith burns bright — don’t let it blind you.*",
        "*Even stars fall, boy. Will you?*",
        "*You walk the thread like a tightrope. One gust...*",
        "*Bold. Brash. Bound to fall harder.*",
        "*You think you’re winning? The Fates are always ahead.*"
    };
    

    vector<string> mediumFaithTaunts = {
        "*The thread frays... one wrong note and you're gone.*",
        "*Your fate hangs by a thread, boy.*",
        "*The loom trembles. Your song grows thin.*",
        "*So close... and yet the end still yawns before you.*",
        "*You waver, songbird. The wind picks up.*",
        "*Hope? Hope doesn't mend broken threads.*",
        "*Almost strong. Almost brave. Almost enough.*",
        "*The cracks show. We see them all.*",
        "*Balanced between ruin and resolve.*",
        "*Half a step from greatness... or the grave.*"
    };
    

    vector<string> weakFaithTaunts = {
        "*Ha! Barely a thread left! One pull and you fall apart.*",
        "*A breath could scatter you to dust.*",
        "*The song is almost over. One wrong note, and you're lost forever.*",
        "*We’ve seen stronger men crumble for less.*",
        "*Is this all the faith you’ve got left? Pathetic.*",
        "*Orpheus, even shadows pity you now.*",
        "*You should have stayed above.*",
        "*Why struggle? You're already unraveling.*",
        "*Torn. Tired. Tempted. It shows.*",
        "*We could cut the thread now and save us the boredom.*"
    };
    
    if (player.faith >= 70.0f) {
        int idx = rand() % strongFaithTaunts.size();
        displaySpeakerDialogue("Fates", strongFaithTaunts[idx]);
    } else if (player.faith >= 40.0f) {
        int idx = rand() % mediumFaithTaunts.size();
        displaySpeakerDialogue("Fates", mediumFaithTaunts[idx]);
    } else {
        int idx = rand() % weakFaithTaunts.size();
        displaySpeakerDialogue("Fates", weakFaithTaunts[idx]);
    }
}

// Function to ask faith-related questions and impact the player's faith level
void askFaithQuestions(Character& player) {
    std::vector<MCQuestion> questions = {
        {"Who is the god of wine, theatre, and revelry?", {"Hephaestus", "Apollo", "Dionysus"}, 2},
        {"What creature had the head of a lion, a goat’s body, and a serpent’s tail?", {"Chimera", "Cerberus", "Hydra"}, 0},
        {"Which mortal was allowed to live forever but continued aging?", {"Tithonus", "Orpheus", "Phaethon"}, 0},
        {"Which Greek hero killed the Gorgon Medusa?", {"Theseus", "Perseus", "Heracles"}, 1},
        {"Who drove the sun chariot across the sky?", {"Apollo", "Helios", "Zeus"}, 1},
        {"What monstrous dog guarded the entrance to the Underworld?", {"Cerberus", "Orthrus", "Hydra"}, 0},
        {"Which Titan was condemned to hold up the sky for eternity?", {"Atlas", "Cronus", "Hyperion"}, 0},
        {"Which goddess emerged fully grown from Zeus’s head?", {"Artemis", "Athena", "Hera"}, 1},
        {"Which king's hubris led him to feast on the gods and be cursed?", {"Sisyphus", "Tantalus", "Oedipus"}, 1},
        {"What winged horse was born from Medusa’s blood?", {"Pegasus", "Griffin", "Hippogriff"}, 0},
        {"Which mortal woman was the mother of Achilles?", {"Andromache", "Thetis", "Leda"}, 1},
        {"Which goddess cursed Echo to only repeat the words of others?", {"Aphrodite", "Hera", "Demeter"}, 1},
        {"What is the name of the labyrinth's architect?", {"Icarus", "Minos", "Daedalus"}, 2},
        {"Who was turned into a laurel tree to escape Apollo?", {"Daphne", "Calliope", "Andromeda"}, 0},
        {"Which Titan ruled during the Golden Age?", {"Cronus", "Prometheus", "Oceanus"}, 0},
        {"Which hero solved the riddle of the Sphinx?", {"Odysseus", "Oedipus", "Jason"}, 1},
        {"What sea monster did Perseus save Andromeda from?", {"Scylla", "Cetus", "Charybdis"}, 1},
        {"Who was the mother of the Minotaur?", {"Pasiphaë", "Ariadne", "Phaedra"}, 0},
        {"What river in the Underworld caused forgetfulness?", {"Lethe", "Styx", "Acheron"}, 0},
        {"Which goddess transformed Actaeon into a stag?", {"Artemis", "Hera", "Athena"}, 0}
    };

    // Ask 5 random questions
    for (int i = 0; i < 5 && !questions.empty(); ++i) {
        int index = rand() % questions.size();
        MCQuestion q = questions[index];
        questions.erase(questions.begin() + index);

        randomizedFatesTaunt(player);
        displaySpeakerDialogue("Fates", q.questionText);
        for (int j = 0; j < 3; ++j) {
            std::cout << j + 1 << ". " << q.options[j] << std::endl;
        }

        int answer = getValidatedInput<int>("Enter your answer (1-3): ", 1, 3);
        if (answer - 1 == q.correctIndex) {
            displaySpeakerDialogue("Fates", " 'Maybe you know a thing or two...'");
            player.faith += 5;
        } else {
            displaySpeakerDialogue("Fates", " 'Didn't think so. Little songbird lost.'");
            player.faith -= 5;
        }

        // Clamp faith between 0 and 100
        if (player.faith > 100.0f) player.faith = 100.0f;
        if (player.faith < 0.0f) player.faith = 0.0f;
    }
    cout << "Your current faith level: " << player.faith << "%\n";
}

