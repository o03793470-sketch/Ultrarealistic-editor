#pragma once
#include <iostream>
#include <string>

struct GameRules {
    void AddRule(const std::string& rule) {
        std::cout << "Adding game rule: " << rule << std::endl;
    }
};