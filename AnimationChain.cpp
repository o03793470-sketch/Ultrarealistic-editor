#pragma once
#include <string>
#include <vector>
#include <iostream>

// Простий каркас для ланцюгів анімацій
struct AnimationChain {
    std::vector<std::string> animations;

    void AddAnimation(const std::string& name) {
        animations.push_back(name);
        std::cout << "Added animation: " << name << std::endl;
    }

    void PlayChain() {
        for (auto& anim : animations) {
            std::cout << "Playing animation: " << anim << std::endl;
            // Тут можна підключити реальне відтворення через DX12 або Rigging
        }
    }
};