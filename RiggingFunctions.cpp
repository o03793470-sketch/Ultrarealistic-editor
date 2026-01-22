#pragma once
#include <iostream>
#include <string>

// Функції рігінгу для персонажів
struct RiggingFunctions {

    void SetupSkeleton(const std::string& characterName) {
        std::cout << "Setting up skeleton for: " << characterName << std::endl;
        // Тут можна ініціалізувати кістки, ріги, constraints
    }

    void ApplyRigAnimation(const std::string& animName) {
        std::cout << "Applying rig animation: " << animName << std::endl;
        // Тут можна застосувати анімацію до ріга
    }
};