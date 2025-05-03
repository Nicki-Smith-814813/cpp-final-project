#include "settings.h"
#include "utils.h"
#include <iostream>

bool disableColor = false;
int textSpeed = 50;

void openSettingsMenu() {
    bool running = true;
    while (running) {
        std::cout << "\n--- Settings Menu ---\n";
        std::cout << "1. Toggle Colored Text (Currently: " << (disableColor ? "OFF" : "ON") << ")\n";
        std::cout << "2. Set Text Speed (Currently: " << textSpeed << " ms per character)\n";
        std::cout << "3. Exit Settings\n";

        int choice = getValidatedInput<int>("Choose an option (1–3): ", 1, 3);

        switch (choice) {
            case 1:
                disableColor = !disableColor;
                std::cout << "Colored text is now " << (disableColor ? "disabled." : "enabled.") << std::endl;
                break;
            case 2: {
                int newSpeed = getValidatedInput<int>("Enter new text speed in ms (e.g., 30–100): ", 10, 200);
                textSpeed = newSpeed;
                std::cout << "Text speed updated.\n";
                break;
            }
            case 3:
                running = false;
                break;
        }
    }
}
