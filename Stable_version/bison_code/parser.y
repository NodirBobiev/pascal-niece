%{
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "lexer.hpp"
using namespace std;

void yyerror(const char* msg, ...) {
    std::cerr << "Syntax error at line " << yylineno << ": " << msg << std::endl;
}
%}

%union {
    struct ASTNode* node;
    char* value;
}

%define parse.error verbose

%token<value> RETURN VAR TYPE IS ROUTINE END BOOL_LITERAL INTEGER REAL BOOLEAN
%token<value> RECORD ARRAY IN REVERSE LOOP FOR WHILE IF THEN ELSE AND OR XOR NOT
%token<value> IDENTIFIER INTEGER_LITERAL REAL_LITERAL STRING_LITERAL
%token<value> RANGE COMMA COLON SEMICOLON LPAREN RPAREN LBRACKET RBRACKET
%token<value> ASSIGN EQUALS NOT_EQUAL LESS_THAN LESS_THAN_EQUAL GREATER_THAN GREATER_THAN_EQUAL
%token<value> MULTIPLY DIVIDE MODULO INVALID_CHARACTER
%token<value> BOOLEAN_LITERAL PLUS MINUS DOT

%type <value> Sign RelationOperand
%type <node> Program SimpleDeclaration VariableDeclaration TypeDeclaration RoutineDeclaration Parameters  
%type <node> Range IfStatement Expression Relation Simple Factor Summand Primary ModifiablePrimary PrimitiveType
%type <node> ParameterDeclaration Type Body Statement Assignment RoutineCall WhileLoop ForLoop
%type <node> RecordType ArrayType MultipleVariableDeclaration ExpressionList 

%start Program

%%

Program : SimpleDeclaration {ASTNODES.push_back($1);}
        | RoutineDeclaration {ASTNODES.push_back($1);}
        | Program SimpleDeclaration {ASTNODES.push_back($2);}
        | Program RoutineDeclaration {ASTNODES.push_back($2);}
        ;

SimpleDeclaration : VariableDeclaration SemicolonOrNothing { $$ =$1; }
                  | TypeDeclaration SemicolonOrNothing { $$ =$1; }
                  ;

SemicolonOrNothing : 
                   | SEMICOLON
                   ;

VariableDeclaration : VAR IDENTIFIER COLON Type { $$ = makeNode("VariableDeclaration",$2); $$->children.push_back($4); }
                    | VAR IDENTIFIER COLON Type IS Expression { $$ = makeNode("VariableDeclaration",$2); $$->children.push_back($4); $$->children.push_back($6); }
                    | VAR IDENTIFIER IS Expression { $$ = makeNode("VariableDeclaration",$2); $$->children.push_back($4); }
                    ;

TypeDeclaration : TYPE IDENTIFIER IS Type { $$ = makeNode("TypeDeclaration",$2); $$->children.push_back($4); }
                ;

RoutineDeclaration : ROUTINE IDENTIFIER LBRACKET Parameters RBRACKET IS Body END SemicolonOrNothing { $$ = makeNode("RoutineDeclaration",$2); $$->children.push_back($4); $$->children.push_back($7); }
                   | ROUTINE IDENTIFIER LBRACKET Parameters RBRACKET COLON Type IS Body RETURN Expression END SemicolonOrNothing { $$ = makeNode("RoutineDeclaration",$2); $$->children.push_back($4); $$->children.push_back($7); $$->children.push_back($9); }
                   ;

Parameters : ParameterDeclaration { $$ = makeNode("Parameters", ""); $$->children.push_back($1); }
           | Parameters COMMA ParameterDeclaration { $$ =$1; $$->children.push_back($3); }
           ;

ParameterDeclaration : IDENTIFIER COLON Type { $$ = makeNode("ParameterDeclaration",$1); $$->children.push_back($3); }
                     ;

PrimitiveType : INTEGER { $$ = makeNode("IntegerType",$1); }
              | REAL { $$ = makeNode("RealType",$1); }
              | BOOLEAN { $$ = makeNode("BooleanType",$1); }
              ;

Type : PrimitiveType { $$ = makeNode("PrimitiveType",$1->type); }
     | RecordType { $$ =$1; }
     | ArrayType { $$ =$1; }
     | IDENTIFIER { $$ = makeNode("Identifier",$1); }
     ;

RecordType : RECORD MultipleVariableDeclaration END
           { $$ = makeNode("RecordType", ""); $$->children.push_back($2); }
           ;

MultipleVariableDeclaration : VariableDeclaration
                            { $$ = makeNode("MultipleVariableDeclaration", ""); $$->children.push_back($1); }
                            | MultipleVariableDeclaration VariableDeclaration
                            { $$ =$1; $$->children.push_back($2); }
                            ;

ArrayType : ARRAY LPAREN RPAREN Type
          { $$ = makeNode("ArrayType", ""); $$->children.push_back(makeNode("Type",$4->value)); }
          | ARRAY LPAREN Expression RPAREN Type
          { $$ = makeNode("ArrayType", ""); $$->children.push_back(makeNode("Expression",$3->value)); $$->children.push_back(makeNode("Type",$5->value)); }
          ;

Body : Statement
     { $$ = makeNode("Body", ""); $$->children.push_back($1); }
     | SimpleDeclaration
     { $$ = makeNode("Body", ""); $$->children.push_back($1); }
     | RETURN Expression
     { $$ = makeNode("Body", ""); $$->children.push_back(makeNode("Return",$2->value)); }
     | Body Statement
     { $$ =$1; $$->children.push_back($2); }
     | Body SimpleDeclaration
     { $$ =$1; $$->children.push_back($2); }
     | Body Expression
     { $$ =$1; $$->children.push_back($2); }
     ;

Statement : Assignment
          { $$ = $1; }
          | RoutineCall
          { $$ = $1; }
          | WhileLoop
          { $$ = $1; }
          | ForLoop
          { $$ = $1; }
          | IfStatement
          { $$ = $1; }
          ;

Assignment : ModifiablePrimary ASSIGN Expression
           { $$ = makeNode("Assignment", ""); $$->children.push_back(makeNode("ModifiablePrimary",$1->value)); $$->children.push_back(makeNode("Expression",$3->value)); }
           ;

RoutineCall : IDENTIFIER
            { $$ = makeNode("RoutineCall", ""); $$->children.push_back(makeNode("Identifier",$1)); }
            | IDENTIFIER LBRACKET ExpressionList RBRACKET
            { $$ = makeNode("RoutineCall", ""); $$->children.push_back(makeNode("Identifier",$1)); $$->children.push_back(makeNode("ExpressionList", "")); $$->children.back()->children =$3->children; }
            ;

ExpressionList : Expression
               { $$ = makeNode("ExpressionList", ""); $$->children.push_back($1); }
               | ExpressionList COMMA Expression
               { $$ =$1; $$->children.push_back($3); }
               ;

WhileLoop : WHILE Expression LOOP Body END
          {
            $$ = makeNode("WhileLoop", "");
            $$->children.push_back($2);
            $$->children.push_back($4);
          }
          ;

ForLoop : FOR IDENTIFIER Range LOOP Body END
        {
          $$ = makeNode("ForLoop", "");
          $$->value =$2; // save identifier name as value
          $$->children.push_back($3);
          $$->children.push_back($5);
        }
        ;

Range : IN Expression RANGE Expression
      {
        $$ = makeNode("Range", "");
        $$->children.push_back($2);
        $$->children.push_back($4);
      }
      | IN REVERSE Expression RANGE Expression
      {
        $$ = makeNode("Range", "");
        $$->children.push_back($3);
        $$->children.push_back($5);
      }
      ;

IfStatement : IF Expression THEN Body END
            {
              $$ = makeNode("IfStatement", "");
              $$->children.push_back($2);
              $$->children.push_back($4);
            }
            | IF Expression THEN Body ELSE Body END
            {
              $$ = makeNode("IfStatement", "");
              $$->children.push_back($2);
              $$->children.push_back($4);
              $$->children.push_back($6);
            }
            ;

Expression : Relation {$$ = $1;}
           | Relation OR Expression
           {
             $$ = makeNode("OrExpression", "");
             $$->children.push_back($1);
             $$->children.push_back($3);
           }
           | Relation AND Expression
           {
             $$ = makeNode("AndExpression", "");
             $$->children.push_back($1);
             $$->children.push_back($3);
           }
           | Relation XOR Expression
           {
             $$ = makeNode("XorExpression", "");
             $$->children.push_back($1);
             $$->children.push_back($3);
           }
           ;

Relation : Simple {$$ = $1;}
         | Simple RelationOperand Simple
         {
           $$ = makeNode("Relation", "");
           $$->children.push_back($1);
           $$->children.push_back(makeNode("RelationOperand",$2));
           $$->children.push_back($3);
         }
         ;

RelationOperand : EQUALS {$$ = $1;}
                | NOT_EQUAL {$$ = $1;}
                | LESS_THAN {$$ = $1;}
                | LESS_THAN_EQUAL {$$ = $1;}
                | GREATER_THAN {$$ = $1;}
                | GREATER_THAN_EQUAL {$$ = $1;}
                ;

Simple : Factor                                      { $$ = $1; }
       | Factor MULTIPLY Simple                      { $$ = makeNode("MULTIPLY", ""); $$->children.push_back($1); $$->children.push_back($3); }
       | Factor DIVIDE Simple                        { $$ = makeNode("DIVIDE", ""); $$->children.push_back($1); $$->children.push_back($3); }
       | Factor MODULO Simple                        { $$ = makeNode("MODULO", ""); $$->children.push_back($1); $$->children.push_back($3); }
       ;

Factor : Summand                                     { $$ = $1; }
       | Summand Sign Factor                         { $$ = makeNode("SIGN",$2); $$->children.push_back($1); $$->children.push_back($3); }
       ;

Summand : Primary                                    { $$ = $1; }
        | LBRACKET Expression RBRACKET               { $$ = makeNode("BRACKETS", ""); $$->children.push_back($2); }
        ;

Primary : INTEGER_LITERAL                           { $$ = makeNode("INTEGER_LITERAL",$1); }
        | Sign INTEGER_LITERAL                      { $$ = makeNode("INTEGER_LITERAL","-" + std::string($2)); }
        | NOT INTEGER_LITERAL                       { $$ = makeNode("INTEGER_LITERAL", "NOT(" + std::string($2) + ")"); }
        | REAL_LITERAL                              { $$ = makeNode("REAL_LITERAL",$1); }
        | Sign REAL_LITERAL                         { $$ = makeNode("REAL_LITERAL","-" + std::string($2)); }
        | BOOLEAN_LITERAL                           { $$ = makeNode("BOOLEAN_LITERAL",$1); }
        | ModifiablePrimary                         { $$ =$1; }
        | RoutineCall                               { $$ =$1; }
        ;

Sign : PLUS                                         { $$ = "+"; }
     | MINUS                                        { $$ = "-"; }
     ;

ModifiablePrimary : IDENTIFIER                      { $$ = makeNode("IDENTIFIER",$1); }
                  | ModifiablePrimary DOT IDENTIFIER { $$ = makeNode("DOT", ""); $$->children.push_back($1); $$->children.push_back(makeNode("IDENTIFIER",$3)); }
                  | ModifiablePrimary LPAREN Expression RPAREN { $$ = makeNode("ROUTINE_CALL", ""); $$->children.push_back($1); $$->children.push_back($3); }
                  ;
%%

int main(int argc, char **argv) {
        
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL){
            printf("syntax error: %s filename\n", argv[1]);
            return 0;
        }//end if
    }//end if
    yyparse(); // Calls yylex() for tokens.
    for (int i = 0; i < ASTNODES.size(); ++i)
      printAST(ASTNODES[i]);
    return 0;
}