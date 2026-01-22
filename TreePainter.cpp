#pragma once
#include <iostream>
#include <string>

struct TreePainter {
    void AddTree(float x, float y, float scale) {
        std::cout << "Adding tree at (" << x << ", " << y << ") scale: " << scale << std::endl;
    }
};