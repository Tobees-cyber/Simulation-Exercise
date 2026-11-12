// simulation_main.cpp
#include <iostream>
#include <string>
#include <vector>
#include "state.hpp"
#include "calculator.hpp"
#include "controller.hpp"


int main() {
    
    std::vector<State> state;
    
    // direkt erstellen und anhängen
    State germany = {
        "Deutschland", 
        75,
        0.80f, 
        0.1f, 
        0.9f,
        90.0f, 
        84000000LL,
        357588LL
        };
    state.push_back(germany);

    State united_states_amerika = {
        "USA", 
        95, 
        0.90f,
        0.0f, 
        0.85f,
        95.0f, 
        335000000LL,
        9834000LL
        };
    state.push_back(united_states_amerika);
    
    // direkt im vector erzeugen 
    state.push_back({
        "China",
        90,
        0.85f,
        0.0f,
        0.80f,
        92.0f,
        1411000000LL,    // population (LL signalisiert dem Compiler ein long long)
        9597000LL,
    });

    state.push_back({
        "Russland",
        85,
        0.65f,
        0.0f,
        0.95f,
        60.0f,
        144000000LL,
        17098246LL
    });

    int round = 1;
    bool simul_run = true;
    bool auto_mode = false;

    while (simul_run) {
        std::cout << "\n=== ROUND " << round << " ===\n";

        update_simulation(state);
        
        // Werte zur Kontorlle ausgeben
        for (int i = 0; i < state.size(); i++) {
            std::cout << state[i].name << " | Wirtschaft: " << state[i].economic_strength 
                      << " | Territorium: " << state[i].territory 
                      << " | Stabilität: " << state[i].political_stability
                      << " | Militär: " << state[i].get_effective_military() << "\n";
        }

        if (!auto_mode) {
            // Contorller aufrufen
            simul_run = handle_input(auto_mode);
        }

        round++;

        if (auto_mode && round > 20) {
            simul_run = false;
        }
    }

    std::cout << "\nSimulation beendet!\n";
    return 0;
    
}