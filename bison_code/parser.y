%{
#include <iostream>
#include "lexer.hpp"

void yyerror(const char* msg, ...) {
    std::cerr << "Syntax error at line " << yylineno << ": " << msg << std::endl;
}
%}

%define parse.error verbose


%token INVALID_CHARACTER INTEGER REAL RETURN THEN SEMICOLON NEWLINE INTEGER_LITERAL BOOLEAN_LITERAL REAL_LITERAL

%token IDENTIFIER BOOLEAN RANGE
%token WHILE FOR IF ELSE VAR TYPE ROUTINE END RECORD ARRAY IN REVERSE LOOP IS AND OR XOR NOT
%token ASSIGN COLON COMMA DOT LBRACKET RBRACKET LPAREN RPAREN EQUALS EQUAL NOT_EQUAL
%token LESS_THAN LESS_THAN_EQUAL GREATER_THAN GREATER_THAN_EQUAL PLUS MINUS MULTIPLY DIVIDE MODULO
%start Program

%%

Program : SimpleDeclaration
        | RoutineDeclaration
        | Program SimpleDeclaration
        | Program RoutineDeclaration
        ;

SimpleDeclaration : VariableDeclaration SemicolonOrNothing
                  | TypeDeclaration SemicolonOrNothing
                  ;

SemicolonOrNothing : 
                   | SEMICOLON
                   ;

VariableDeclaration : VAR IDENTIFIER COLON Type
                    | VAR IDENTIFIER COLON Type IS Expression
                    | VAR IDENTIFIER IS Expression
                    ;

TypeDeclaration : TYPE IDENTIFIER IS Type
                ;

RoutineDeclaration : ROUTINE IDENTIFIER LBRACKET Parameters RBRACKET IS Body END SemicolonOrNothing
                   | ROUTINE IDENTIFIER LBRACKET Parameters RBRACKET COLON Type IS Body RETURN Expression END SemicolonOrNothing
                   ;

Parameters : ParameterDeclaration
           | Parameters COMMA ParameterDeclaration
           ;

ParameterDeclaration : IDENTIFIER COLON Type
                     ;

Type : PrimitiveType
     | RecordType
     | ArrayType
     | IDENTIFIER
     ;

PrimitiveType : INTEGER
              | REAL
              | BOOLEAN
              ;

RecordType : RECORD MultipleVariableDeclaration END
           ;

MultipleVariableDeclaration : VariableDeclaration
                            | MultipleVariableDeclaration VariableDeclaration
                            ;

ArrayType : ARRAY LPAREN RPAREN Type
          | ARRAY LPAREN Expression RPAREN Type
          ;

Body : Statement
     | SimpleDeclaration
     | RETURN Expression
     | Body Statement
     | Body SimpleDeclaration
     | Body Expression
     ;

Statement : Assignment
          | RoutineCall
          | WhileLoop
          | ForLoop
          | IfStatement
          ;

Assignment : ModifiablePrimary ASSIGN Expression
           ;

RoutineCall : IDENTIFIER
            | IDENTIFIER LBRACKET ExpressionList RBRACKET
            ;

ExpressionList : Expression
               | ExpressionList COMMA Expression
               ;

WhileLoop : WHILE Expression LOOP Body END
          ;

ForLoop : FOR IDENTIFIER Range LOOP Body END
        ;

Range : IN Expression RANGE Expression
      | IN REVERSE Expression RANGE Expression
      ;

IfStatement : IF Expression THEN Body END
            | IF Expression THEN Body ELSE Body END
            ;

Expression : Relation
           | Relation OR Expression
           | Relation AND Expression
           | Relation XOR Expression
           ;

Relation : Simple
         | Simple RelationOperand Simple
         ;

RelationOperand : EQUALS
                | NOT_EQUAL
                | LESS_THAN
                | LESS_THAN_EQUAL
                | GREATER_THAN
                | GREATER_THAN_EQUAL
                ;

Simple : Factor
       | Factor MULTIPLY Simple
       | Factor DIVIDE Simple
       | Factor MODULO Simple
       ;

Factor : Summand
       | Summand Sign Factor
       ;

Summand : Primary
        | LBRACKET Expression RBRACKET
        ;

Primary : INTEGER_LITERAL
        | Sign INTEGER_LITERAL
        | NOT INTEGER_LITERAL
        | REAL_LITERAL
        | Sign REAL_LITERAL
        | BOOLEAN_LITERAL
        | ModifiablePrimary
        | RoutineCall
        ;

Sign : PLUS
     | MINUS
     ;

ModifiablePrimary : IDENTIFIER
                  | ModifiablePrimary DOT IDENTIFIER
                  | ModifiablePrimary LPAREN Expression RPAREN
                  ;
%%

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL){
            printf("syntax: %s filename\n", argv[0]);
            return 0;
        }//end if
    }//end if
    yyparse(); // Calls yylex() for tokens.
    printf("compilation went without any errors\n");
    return 0;
}