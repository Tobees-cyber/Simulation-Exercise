#include <iostream>
#include "calculator.hpp"


void update_simulation(std::vector<State>& state_list) {
    for (int i = 0; i < state_list.size(); i++) {
        // Wirtschaftswachstum für staaten berechnen
        state_list[i].economic_strength *= 1.0f + (0.015f * state_list[i].political_stability); 
    }

    // Konflikt Logik
    for (size_t attacker_idx = 0; attacker_idx < state_list.size(); ++attacker_idx) {
        for (size_t defender_idx = 0; defender_idx < state_list.size(); ++defender_idx) {

            if (attacker_idx == defender_idx) continue;

            float power_attacker = state_list[attacker_idx].get_effective_military();
            float power_defender = state_list[defender_idx].get_effective_military();

            if (power_attacker > power_defender * 1.3f) {
                long long land_transfer = 5000LL;

                if (state_list[defender_idx].territory > land_transfer) {
                    state_list[defender_idx].territory -= land_transfer;
                    state_list[attacker_idx].territory += land_transfer;

                    state_list[defender_idx].political_stability -= 0.02f;

                    state_list[defender_idx].economic_strength -= 0.5f;

                    if (state_list[defender_idx].political_stability < 0.0f) {
                        state_list[defender_idx].political_stability = 0.0f;
                    }

                    if (state_list[defender_idx].economic_strength < 0.0f) {
                        state_list[defender_idx].economic_strength = 0.0f;
                    }

                    std::cout << "[Einfluss] " << state_list[attacker_idx].name 
                              << " dominiert " << state_list[defender_idx].name 
                              << " (Stärke: " << power_attacker << " vs " << power_defender << ")\n";
                }
            }
        }
    }
}