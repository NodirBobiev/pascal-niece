%{
#include "parser.hpp"
%}

%option noyywrap
%option yylineno
%option outfile="lexer.cpp" header-file="lexer.hpp"

digit      [0-9]
letter     [a-zA-Z]
identifier {letter}({letter}|{digit})*
integer    {digit}+
real       {integer}("."{integer})?("E"("+"|"-")?{integer})?

%%

"+"              { return PLUS; }
"-"              { return MINUS; }
"*"              { return MULTIPLY; }
"/"              { return DIVIDE; }
"%"              { return MODULO; }
":="             { return ASSIGN; }
":"              { return COLON; }
";"              { return SEMICOLON; }
"=="             { return EQUALS; }
"="              { return EQUAL; }
"/="             { return NOT_EQUAL; }
"<"              { return LESS_THAN; }
"<="             { return LESS_THAN_EQUAL; }
">"              { return GREATER_THAN; }
">="             { return GREATER_THAN_EQUAL; }
"and"            { return AND; }
"or"             { return OR; }
"xor"            { return XOR; }
"not"            { return NOT; }
"var"            { return VAR; }
"is"             { return IS; }
"then"           { return THEN; }
"type"           { return TYPE; }
"routine"        { return ROUTINE; }
"end"            { return END; }
"record"         { return RECORD; }
"array"          { return ARRAY; }
"in"             { return IN; }
"reverse"        { return REVERSE; }
"loop"           { return LOOP; }
"for"            { return FOR; }
"while"          { return WHILE; }
"if"             { return IF; }
"true"           { return BOOLEAN_LITERAL; }
"false"          { return BOOLEAN_LITERAL; }
"return"         { return RETURN; }
{integer}        { return INTEGER_LITERAL; }
{real}           { return REAL_LITERAL; }
{identifier}     { return IDENTIFIER; }
"("              { return LBRACKET; }
")"              { return RBRACKET; }
"."              { return DOT; }
"["              { return LPAREN; }
"]"              { return RPAREN; }
","              { return COMMA; }
[\t\f\r ]+        /* ignore whitespace */
\n                /* ignore newlines */
.                { return INVALID_CHARACTER; }

%%