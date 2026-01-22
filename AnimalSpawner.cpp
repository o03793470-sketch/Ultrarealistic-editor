#pragma once
#include <iostream>
#include <string>

struct AnimalSpawner {
    void SpawnAnimal(const std::string& animalName, float x, float y) {
        std::cout << "Spawning animal " << animalName << " at (" << x << ", " << y << ")" << std::endl;
    }
};