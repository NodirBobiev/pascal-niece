%{
#include "parser.hpp"
#include <string>
using namespace std;
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
"integer"        { return INTEGER; }
"real"           { return REAL; }
"boolean"        { return BOOLEAN; }
{integer}        { yylval.value = yytext; return INTEGER_LITERAL; }
{real}           { yylval.value = yytext; return REAL_LITERAL; }
{identifier}     { yylval.value = yytext; return IDENTIFIER; }
"("              { yylval.value = yytext; return LBRACKET; }
")"              { yylval.value = yytext; return RBRACKET; }
"."              { yylval.value = yytext; return DOT; }
"["              { yylval.value = yytext; return LPAREN; }
"]"              { yylval.value = yytext; return RPAREN; }
","              { yylval.value = yytext; return COMMA; }
[\t\f\r ]+        /* ignore whitespace */
\n                /* ignore newlines */
.                { return INVALID_CHARACTER; }

%%