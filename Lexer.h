#pragma once
#include <string>

enum class TokenType {
    Identifier,
    Number,
    String,
    Comma,
    LParen,
    RParen,
    End
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
public:
    Lexer(const std::string& source);
    Token NextToken();
private:
    std::string source;
    size_t pos;
    void SkipWhitespace();
};