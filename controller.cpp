#include <iostream>
#include <string>
#include "controller.hpp"

bool handle_input(bool& auto_mode) {
    std::cout << "\n[Enter] Next Round | [a] Automatic-Mode | [q] Beenden: ";
    std::string input;
    std::getline(std::cin, input);

    if (input == "q" || input == "Q") {
        return false;
    }
    else if (input == "a" || input == "A") {
            auto_mode = true;
            std::cout << "automatische durchlauf aktiviert!\n";
    }
    return true;
}