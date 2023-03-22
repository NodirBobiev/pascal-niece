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

"+"              { yylval.value = yytext; return PLUS; }
"-"              { yylval.value = yytext; return MINUS; }
"*"              { yylval.value = yytext; return MULTIPLY; }
"/"              { yylval.value = yytext; return DIVIDE; }
"%"              { yylval.value = yytext; return MODULO; }
":="             { yylval.value = yytext; return ASSIGN; }
":"              { yylval.value = yytext; return COLON; }
";"              { yylval.value = yytext; return SEMICOLON; }
"=="             { yylval.value = yytext; return EQUALS; }
"/="             { yylval.value = yytext; return NOT_EQUAL; }
"<"              { yylval.value = yytext; return LESS_THAN; }
"<="             { yylval.value = yytext; return LESS_THAN_EQUAL; }
">"              { yylval.value = yytext; return GREATER_THAN; }
">="             { yylval.value = yytext; return GREATER_THAN_EQUAL; }
"and"            { yylval.value = yytext; return AND; }
"or"             { yylval.value = yytext; return OR; }
"xor"            { yylval.value = yytext; return XOR; }
"not"            { yylval.value = yytext; return NOT; }
"var"            { yylval.value = yytext; return VAR; }
"is"             { yylval.value = yytext; return IS; }
"then"           { yylval.value = yytext; return THEN; }
"type"           { yylval.value = yytext; return TYPE; }
"routine"        { yylval.value = yytext; return ROUTINE; }
"end"            { yylval.value = yytext; return END; }
"record"         { yylval.value = yytext; return RECORD; }
"array"          { yylval.value = yytext; return ARRAY; }
"in"             { yylval.value = yytext; return IN; }
"reverse"        { yylval.value = yytext; return REVERSE; }
"loop"           { yylval.value = yytext; return LOOP; }
"for"            { yylval.value = yytext; return FOR; }
"while"          { yylval.value = yytext; return WHILE; }
"if"             { yylval.value = yytext; return IF; }
"true"           { yylval.value = yytext; return BOOLEAN_LITERAL; }
"false"          { yylval.value = yytext; return BOOLEAN_LITERAL; }
"return"         { yylval.value = yytext; return RETURN; }
"integer"        { yylval.value = yytext; return INTEGER; }
"real"           { yylval.value = yytext; return REAL; }
"boolean"        { yylval.value = yytext; return BOOLEAN; }
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