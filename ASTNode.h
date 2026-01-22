#pragma once
#include <string>
#include <vector>

struct ASTNode {
    std::string commandName;
    std::vector<std::string> args;
};