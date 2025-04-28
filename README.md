🎵 Hadestown: A C++ Text-Based RPG Adventure



📖 About the Project

Hadestown: The RPG is a cinematic, text-driven journey inspired by Hadestown, built entirely in C++.

You play as Orpheus, a dreamer, a musician, and a fool for love.
Navigate the underworld, challenge the gods, face the Fates, and see if your courage — and your memory — can save Eurydice.

🛠️ Features

🎭 Dynamic Narrative: Rich storytelling with player-driven dialogue choices.

🎶 Musical Memory Challenge: Follow and repeat randomized melodies to survive trials.

💀 Faith System: Dynamic stats (Faith, Trust) that react to your decisions.

🔮 Dynamic Fates AI: Randomized taunts based on your Faith level.

🎲 RNG Gameplay: Randomized challenges and outcomes.

📁 Binary Save System: Autosaves after every major scene to save.dat.

🛡️ Robust Input Validation: No crashing on bad input.

🎨 ASCII-styled Dialogue Effects: Dramatic timed pauses and text flow.

🔧 Technical Requirements Met

Requirement	Status
User-Defined Functions (4+)	✅
Overloaded Function	✅ (dramaticPause() variants)
Arrays & Strings	✅ (melodies, taunts, dialogues)
Control Structures	✅ (loops, if-else, switch)
File Handling	✅ (binary save/load)
Error Handling / Input Validation	✅
Modular Code & Headers	✅ (separate .h and .cpp files)
Structs & Vectors	✅ (Character struct, multiple vectors)
Randomization/Interactivity (AI)	✅
Optional Enhancements:	
Recursion	✅ (tiny utility use)
ASCII UI Effects	✅

📂 Project Structure
cpp-final-project/
├── include/
│   ├── game.h
│   ├── utils.h
│   ├── characters.h
│   └── scenes/
│       └── (all scene headers here)
├── src/
│   ├── main.cpp
│   ├── game.cpp
│   ├── utils.cpp
│   ├── characters.cpp
│   └── scenes/
│       └── (all scene implementations here)
├── build/
│   └── (object files generated here)
├── bin/
│   ├── game (normal build)
│   └── autosave_game (autosave build)
├── Makefile
├── README.md
├── LICENSE
└── save.dat (auto-created during gameplay)


🚀 How to Compile and Run (in GitHub CodeSpaces)
1. Open your CodeSpaces terminal.

2. Build the normal game:

make run

3. OR Build the autosave version:

make autosave
(Either way, it creates clean builds into /bin/)

If you want to clean up:

make clean

👏 Credits
Project Lead, Code Architect: [Nicki-Smith-814813]

Worldbuilding & Mythology: Inspired by Hadestown and Greek myth.


Fonts/Graphics: ASCII styled text only (terminal output).

📜 License
This project is licensed under the MIT License — see the LICENSE file for details.

⚡ Final Thoughts
"Some birds sing when they're broken hearted... but you have to sing even when you can't see the sky."
— Inspired by Hadestown

This game is about faith, trust, and fighting the darkness even when the odds are against you.

Thanks for playing — and good luck on your journey. 🌑🎵
