#pragma once
#include "../AST/ASTNode.h"
#include <vector>

class Interpreter {
public:
    void Execute(const std::vector<ASTNode>& nodes);
private:
    void ExecuteCommand(const ASTNode& node);
};