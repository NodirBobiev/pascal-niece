#include <iostream>
#include <string>
#include <cctype>
#include <fstream>



using namespace std;

enum TokenType {
    VAR, TYPE, IS,  
    INTEGER_TYPE, BOOLEAN_TYPE, REAL_TYPE, 
    WHILE, FOR, LOOP, REVERSE,
    ROUTINE, RECORD, ARRAY,

    COLON, SEMICOLON, COMMA,

    IF, THEN, ELSE, END, AND, OR, XOR, LT, LTE, GT, GTE, EQ, NEQ,
    PLUS, MINUS, TIMES, DIVIDE, MOD, LPAREN, RPAREN, LBRACKET, RBRACKET,
    DOT, INTEGER, REAL, TRUE, FALSE, IDENTIFIER, ERROR, END_OF_FILE, STRING
};

struct Token {
    TokenType type;
    string lexeme;
    int line;
};

class LexicalAnalyzer {
public:
    LexicalAnalyzer(string input) : input(input), line(1), pos(0) {}
    Token getNextToken();
private:
    string input;
    int line, pos;
    char currentChar();
    char nextChar();
    void skipWhitespace();
    void skipComment();
    Token scanIdentifier();
    Token scanNumber();
    Token scanString();
    Token scanOperator();
};

char LexicalAnalyzer::currentChar() {
    if (pos >= input.length())
        return '\0';
    return input[pos];
}

char LexicalAnalyzer::nextChar() {
    pos++;
    return currentChar();
}

void LexicalAnalyzer::skipWhitespace() {
    while (isspace(currentChar())) {
        if (currentChar() == '\n')
            line++;
        nextChar();
    }
}

void LexicalAnalyzer::skipComment() {
    if (currentChar() == '-') {
        nextChar();
        if (currentChar() == '-') {
            nextChar();
            while (currentChar() != '\n')
                nextChar();
            line++;
        } else {
            pos--;
        }
    }
}

Token LexicalAnalyzer::scanIdentifier() {
    string lexeme;
    while (isalnum(currentChar()) || currentChar() == '_') {
        lexeme += currentChar();
        nextChar();
    }
    if (lexeme == "if")
        return Token{IF, lexeme, line};
    else if (lexeme == "then")
        return Token{THEN, lexeme, line};
    else if (lexeme == "else")
        return Token{ELSE, lexeme, line};
    else if (lexeme == "end")
        return Token{END, lexeme, line};
    else if (lexeme == "and")
        return Token{AND, lexeme, line};
    else if (lexeme == "or")
        return Token{OR, lexeme, line};
    else if (lexeme == "xor")
        return Token{XOR, lexeme, line};
    else if (lexeme == "true")
        return Token{TRUE, lexeme, line};
    else if (lexeme == "false")
        return Token{FALSE, lexeme, line};

    else if (lexeme == "var")
        return Token{VAR, lexeme, line};
    else if (lexeme == "type")
        return Token{TYPE, lexeme, line};
    else if (lexeme == "is")
        return Token{IS, lexeme, line};
    else if (lexeme == "integer")
        return Token{INTEGER_TYPE, lexeme, line};
    else if (lexeme == "boolean")
        return Token{BOOLEAN_TYPE, lexeme, line};
    else if (lexeme == "real")
        return Token{REAL_TYPE, lexeme, line};
    else if (lexeme == "while")
        return Token{WHILE, lexeme, line};
    else if (lexeme == "for")
        return Token{FOR, lexeme, line};
    else if (lexeme == "loop")
        return Token{LOOP, lexeme, line};
    else if (lexeme == "reverse")
        return Token{REVERSE, lexeme, line};
    else if (lexeme == "routine")
        return Token{ROUTINE, lexeme, line};
    else if (lexeme == "record")
        return Token{RECORD, lexeme, line};
    else if (lexeme == "array")
        return Token{ARRAY, lexeme, line};

    else
        return Token{IDENTIFIER, lexeme, line};
}

Token LexicalAnalyzer::scanNumber() {
    string lexeme;
    while (isdigit(currentChar())) {
        lexeme += currentChar();
        nextChar();
    }
    if (currentChar() == '.') {
        lexeme += currentChar();
        nextChar();
        while (isdigit(currentChar())) {
            lexeme += currentChar();
            nextChar();
        }
        return Token{REAL, lexeme, line};
    } else {
        return Token{INTEGER, lexeme, line};
    }
}

Token LexicalAnalyzer::scanString() {
    string lexeme;
    char delim = currentChar();
    nextChar();
    while (currentChar() != delim) {
        if (currentChar() == '\n' || currentChar() == '\r') {
            return Token{ERROR, "Unterminated string", line};
        } else if (currentChar() == '\\') {
            lexeme += currentChar();
            nextChar();
            if (currentChar() == 'n')
                lexeme += '\n';
            else if (currentChar() == 't')
                lexeme += '\t';
            else if (currentChar() == 'r')
                lexeme += '\r';
            else if (currentChar() == delim)
                lexeme += delim;
            else {
                return Token{ERROR, "Invalid escape sequence", line};
            }
            nextChar();
        } else {
            lexeme += currentChar();
            nextChar();
        }
    }
    nextChar();
    return Token{STRING, lexeme, line};
}

Token LexicalAnalyzer::scanOperator() {
    switch (currentChar()) {
        case '+':
            nextChar();
            return Token{PLUS, "+", line};
        case '-':
            nextChar();
            return Token{MINUS, "-", line};
        case '*':
            nextChar();
            return Token{TIMES, "", line};
        case '/':
            nextChar();
            if (currentChar() == '/') {
                skipComment();
                return getNextToken();
            } else {
                return Token{DIVIDE, "/", line};
            }
        case '%':
            nextChar();
            return Token{MOD, "%", line};
        case '(':
            nextChar();
            return Token{LPAREN, "(", line};
        case ')':
            nextChar();
            return Token{RPAREN, ")", line};
        case '[':
            nextChar();
            return Token{LBRACKET, "[", line};
        case ']':
            nextChar();
            return Token{RBRACKET, "]", line};
        case '.':
            nextChar();
            return Token{DOT, ".", line};
        case ',':
            nextChar();
            return Token{COMMA, ",", line};
        case ':':
            nextChar();
            return Token{COLON, ":", line};
        case ';':
            nextChar();
            return Token{SEMICOLON, ";", line};
        case '<':
            nextChar();
            if (currentChar() == '=') {
                nextChar();
                return Token{LTE, "<=", line};
            } else {
                return Token{LT, "<", line};
            }
        case '>':
            nextChar();
            if (currentChar() == '=') {
                nextChar();
                return Token{GTE, ">=", line};
            } else {
                return Token{GT, ">", line};
            }
        case '=':
            nextChar();
            if (currentChar() == '/') {
                nextChar();
                return Token{NEQ, "/=", line};
            } else {
                return Token{EQ, "=", line};
            }
        default:
            return Token{ERROR, "Invalid character", line};
    }
}

Token LexicalAnalyzer::getNextToken() {
    skipWhitespace();
    if (currentChar() == '\0') {
        return Token{END_OF_FILE, "", line};
    } else if (isalpha(currentChar()) || currentChar() == '_') {
        return scanIdentifier();
    } else if (isdigit(currentChar())) {
        return scanNumber();
    } else if (currentChar() == '"' || currentChar() == '\'') {
        return scanString();
    } else {
        return scanOperator();
    }
}


string getInput(string filename){
    ifstream file;
    file.open(filename);
    string input;

    while(file){
        string newLine;
        getline(file, newLine);
        input += newLine + "\n";
    }
    
    file.close();
    return input;
}

int main() {
    string input = R"(if x < 10 
    then y = 2 * x - 1 
    end )";

    // string input = getInput("./examples/fib.nice");
    // cout << input << endl;

    LexicalAnalyzer lexer(input);
    Token token;
    do {
        token = lexer.getNextToken();
        cout << "Token: " << token.type << " Lexeme: " << token.lexeme << " Line: " << token.line << endl;
        
        if (token.type == ERROR){
            throw invalid_argument("source input has syntax errors");
        }
    } while (token.type != END_OF_FILE);
    return 0;
}
