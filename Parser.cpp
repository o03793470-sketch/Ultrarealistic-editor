#include "Parser.h"
#include <stdexcept>

Parser::Parser(Lexer& lex) : lexer(lex) { NextToken(); }

void Parser::NextToken() { current = lexer.NextToken(); }

ASTNode Parser::ParseCommand() {
    ASTNode node;
    if (current.type != TokenType::Identifier)
        throw std::runtime_error("Expected command identifier");
    node.commandName = current.value;
    NextToken();

    if (current.type != TokenType::LParen)
        throw std::runtime_error("Expected '(' after command");
    NextToken();

    while (current.type != TokenType::RParen && current.type != TokenType::End) {
        if (current.type == TokenType::Number || current.type == TokenType::String || current.type == TokenType::Identifier) {
            node.args.push_back(current.value);
            NextToken();
        } else if (current.type == TokenType::Comma) {
            NextToken();
        } else {
            throw std::runtime_error("Unexpected token in arguments");
        }
    }

    if (current.type != TokenType::RParen)
        throw std::runtime_error("Expected ')' at end of command");

    NextToken();
    return node;
}

std::vector<ASTNode> Parser::Parse() {
    std::vector<ASTNode> nodes;
    while (current.type != TokenType::End) {
        nodes.push_back(ParseCommand());
    }
    return nodes;
}