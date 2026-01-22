#pragma once
#include "../Lexer/Lexer.h"
#include "../AST/ASTNode.h"
#include <vector>

class Parser {
public:
    Parser(Lexer& lexer);
    std::vector<ASTNode> Parse();
private:
    Lexer& lexer;
    Token current;
    void NextToken();
    ASTNode ParseCommand();
};