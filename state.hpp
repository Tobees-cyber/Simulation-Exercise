// state.hpp
#pragma once

#include <string>

struct State {
    std::string name;
    int base_military;
    float political_stability;
    float foreign_support;
    float ressources;
    float economic_strength;
    long long population; 
    long long territory;

    // Struct-Methode 
    float get_effective_military() const {
        return base_military * (political_stability + foreign_support);
    }
};
