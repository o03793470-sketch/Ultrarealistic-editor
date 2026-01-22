#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <map>

// ==========================
// Токени
// ==========================
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

// ==========================
// Lexer
// ==========================
class Lexer {
public:
    Lexer(const std::string& src) : source(src), pos(0) {}

    Token NextToken() {
        SkipWhitespace();

        if (pos >= source.size())
            return {TokenType::End, ""};

        char c = source[pos];

        if (isalpha(c) || c == '_') {
            std::string id;
            while (isalnum(source[pos]) || source[pos] == '_' || source[pos]=='.')
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
            while (pos < source.size() && source[pos] != '"') str += source[pos++];
            pos++; // закриваємо "
            return {TokenType::String, str};
        }

        if (c == '(') { pos++; return {TokenType::LParen, "("}; }
        if (c == ')') { pos++; return {TokenType::RParen, ")"}; }
        if (c == ',') { pos++; return {TokenType::Comma, ","}; }

        pos++; // невідомий символ
        return NextToken();
    }

private:
    std::string source;
    size_t pos;

    void SkipWhitespace() {
        while (pos < source.size() && isspace(source[pos])) pos++;
    }
};

// ==========================
// AST команда
// ==========================
struct Command {
    std::string name;
    std::vector<std::string> args;
};

// ==========================
// Parser
// ==========================
class Parser {
public:
    Parser(Lexer& lex) : lexer(lex) {
        NextToken();
    }

    std::vector<Command> Parse() {
        std::vector<Command> commands;
        while (current.type != TokenType::End) {
            commands.push_back(ParseCommand());
        }
        return commands;
    }

private:
    Lexer& lexer;
    Token current;

    void NextToken() { current = lexer.NextToken(); }

    Command ParseCommand() {
        Command cmd;
        if (current.type != TokenType::Identifier)
            throw std::runtime_error("Expected identifier for command");
        cmd.name = current.value;
        NextToken();

        if (current.type != TokenType::LParen)
            throw std::runtime_error("Expected '(' after command");
        NextToken();

        while (current.type != TokenType::RParen && current.type != TokenType::End) {
            if (current.type == TokenType::Number || current.type == TokenType::String || current.type == TokenType::Identifier) {
                cmd.args.push_back(current.value);
                NextToken();
            } else if (current.type == TokenType::Comma) {
                NextToken();
            } else {
                throw std::runtime_error("Unexpected token in arguments");
            }
        }

        if (current.type != TokenType::RParen)
            throw std::runtime_error("Expected ')' at end of command");

        NextToken(); // пропустити ')'
        return cmd;
    }
};

// ==========================
// Interpreter
// ==========================
class Interpreter {
public:
    void Execute(const std::vector<Command>& commands) {
        for (auto& cmd : commands)
            ExecuteCommand(cmd);
    }

private:
    void ExecuteCommand(const Command& cmd) {
        if (cmd.name == "Character.Create") {
            std::cout << "Created character: " << cmd.args[0] << std::endl;
        }
        else if (cmd.name == "Character.SetPosition") {
            std::cout << "Set character position to (" 
                      << cmd.args[0] << "," << cmd.args[1] << "," << cmd.args[2] << ")" << std::endl;
        }
        else if (cmd.name == "World.Generate") {
            std::cout << "Generating world with seed " << cmd.args[0] << std::endl;
        }
        else if (cmd.name == "Animal.Spawn") {
            std::cout << "Spawning animal: " << cmd.args[0] 
                      << " at (" << cmd.args[1] << "," << cmd.args[2] << ")" << std::endl;
        }
        else {
            std::cout << "Unknown command: " << cmd.name << std::endl;
        }
    }
};

// ==========================
// Тест
// ==========================
int main() {
    std::ifstream file("Core.gsd++");
    if (!file.is_open()) {
        std::cerr << "Cannot open Core.gsd++" << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string code = buffer.str();

    Lexer lexer(code);
    Parser parser(lexer);
    std::vector<Command> commands;

    try {
        commands = parser.Parse();
    } catch (std::exception& e) {
        std::cerr << "Parse error: " << e.what() << std::endl;
        return 1;
    }

    Interpreter interpreter;
    interpreter.Execute(commands);

    return 0;
}