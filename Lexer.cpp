#include "Lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& src) : source(src), pos(0) {}

void Lexer::SkipWhitespace() {
    while (pos < source.size() && isspace(source[pos])) pos++;
}

Token Lexer::NextToken() {
    SkipWhitespace();
    if (pos >= source.size()) return {TokenType::End, ""};

    char c = source[pos];
    if (isalpha(c) || c=='_') {
        std::string id;
        while (isalnum(source[pos]) || source[pos]=='_' || source[pos]=='.')
            id += source[pos++];
        return {TokenType::Identifier, id};
    }

    if (isdigit(c) || c=='-') {
        std::string num;
        while (isdigit(source[pos]) || source[pos]=='.' || source[pos]=='-')
            num += source[pos++];
        return {TokenType::Number, num};
    }

    if (c == '"') {
        pos++;
        std::string str;
        while (pos < source.size() && source[pos]!='"') str += source[pos++];
        pos++;
        return {TokenType::String, str};
    }

    if (c == '(') { pos++; return {TokenType::LParen, "("}; }
    if (c == ')') { pos++; return {TokenType::RParen, ")"}; }
    if (c == ',') { pos++; return {TokenType::Comma, ","}; }

    pos++; // невідомий символ
    return NextToken();
}