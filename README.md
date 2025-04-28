🎵 Hadestown: A C++ Text-Based RPG Adventure

<div align="center">





</div>

📖 About the Project

Hadestown: The RPG is a cinematic, text-driven journey inspired by Hadestown, built entirely in C++.

You play as Orpheus — a dreamer, a musician, and a fool for love.

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

Requirement                                          	Status

User-Defined Functions (4+)	                              ✅

Overloaded Function                                      	✅ (dramaticPause() variants)

Arrays & Strings	                                        ✅ (melodies, taunts, dialogues)

Control Structures	                                      ✅ (loops, if-else, switch)

File Handling	                                            ✅ (binary save/load)

Error Handling / Input Validation	                        ✅

Modular Code & Headers	                                  ✅ (separate .h and .cpp files)

Structs & Vectors	                                        ✅ (Character struct, multiple vectors)

Randomization/Interactivity (AI)	                        ✅

Optional Enhancements: Recursion	                        ✅ (small utility use)

ASCII UI Effects	                                        ✅


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

├── .vscode/

│   └── extensions.json

├── Makefile

├── README.md

├── LICENSE

└── save.dat (auto-created during gameplay)


📦 Requirements
Before running the project, make sure you have the following installed:

Software
C++ Compiler (such as g++ or clang++)

Git (to clone the repository)

Visual Studio Code Extensions

Extension                                  	ID                  	                          Purpose

C/C++	                              ms-vscode.cpptools	                      IntelliSense, debugging, and basic C++ support

C/C++ Extension Pack	              ms-vscode.cpptools-extension-pack	        Bundled utilities for C++ development

C/C++ Themes	                      ms-vscode.cpptools-themes	                Optional themes for C++ projects

CMake Tools	                        ms-vscode.cmake-tools	(Optional)          Extended CMake project management

Makefile Tools        	            ms-vscode.makefile-tools	                Makefile support and build task integration


✅ Note: When opening this project in VS Code, you will be prompted to install recommended extensions automatically. See .vscode/extensions.json for details.

🚀 How to Compile and Run (in GitHub CodeSpaces)

Open your CodeSpaces terminal.

To build the normal game:


make run


To build the autosave version:


make autosave

(Either way, clean builds are placed inside /bin/.)

To clean the project:


make clean

👏 Credits

Project Lead, Code Architect: [Nicki-Smith-814813]

Worldbuilding & Mythology: Inspired by Hadestown and Greek mythology

Fonts/Graphics: ASCII-styled text only (terminal output)

📜 License

This project is licensed under the MIT License — see the LICENSE file for details.

⚡ Final Thoughts

"Some birds sing when they're broken hearted... but you have to sing even when you can't see the sky." — Inspired by Hadestown

This game is about faith, trust, and fighting the darkness even when the odds are against you.

Thanks for playing — and good luck on your journey. 🌑

