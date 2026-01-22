#include "Interpreter.h"
#include <iostream>

void Interpreter::Execute(const std::vector<ASTNode>& nodes) {
    for (auto& node : nodes)
        ExecuteCommand(node);
}

void Interpreter::ExecuteCommand(const ASTNode& node) {
    if (node.commandName == "Character.Create") {
        std::cout << "Created character: " << node.args[0] << std::endl;
    }
    else if (node.commandName == "Character.SetPosition") {
        std::cout << "Set position: (" << node.args[0] << "," << node.args[1] << "," << node.args[2] << ")" << std::endl;
    }
    else if (node.commandName == "World.Generate") {
        std::cout << "Generating world with seed " << node.args[0] << std::endl;
    }
    else if (node.commandName == "Animal.Spawn") {
        std::cout << "Spawning animal: " << node.args[0] << " at (" << node.args[1] << "," << node.args[2] << ")" << std::endl;
    }
    else {
        std::cout << "Unknown command: " << node.commandName << std::endl;
    }
}