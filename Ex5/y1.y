%{
#include<stdio.h>
#include "y.tab.h"
#include<math.h>
%}
%token KEYWORD
%token CONSTANT
%token IDENTIFIER
%token RELOP
%token ARITHOP
%%


S: KEYWORD E '\n' S
  | A '\n' S
  | C '\n' S
  | LOOP '\n' S
  | END
  ;

END: '\n' {printf("Correct syntax");}

//Declaration
E: IDENTIFIER
  | IDENTIFIER ',' E
  | IDENTIFIER '=' CONSTANT
  | IDENTIFIER '=' CONSTANT ',' E
  ;

//Assignment
A: IDENTIFIER '=' EXPR1
  ;

//Conditional Statement
C: 'if' '(' EXPR ')' '\n' S
    ;

EXPR: EXPR0
    | EXPR1
    ;

EXPR0: EXPR0 RELOP IDENTIFIER 
      | EXPR0 RELOP CONSTANT
      | IDENTIFIER 
      | CONSTANT
      | 
      ;

EXPR1: IDENTIFIER ARITHOP EXPR1
      | IDENTIFIER
      | CONSTANT
      ;

//Looping Statement
LOOP: 'for' '(' A ';' EXPR0 ';' A ')' '\n' STATEMENT
      ;

STATEMENT: A
          | C
          | LOOP
          ;

%%
int main()
{
    yyparse();
    //return 0;
}
int yyerror(char *s)
{
    //printf("error:%s",s);
}
int yywrap()
{
  return(1);
}