%{
#include<stdio.h>
#include "y.tab.h"
#include<math.h>
%}
%token INTCONST
%token FRACCONST
%token CHARCONST
%token OTHER
%%

START: S {
                if($$ == 4)
                  printf("INVALID\n");
                else if($$ == 3)
                  printf("VALID, TYPE IS FLOAT\n");
                else if($$ == 2)
                  printf("VALID, TYPE IS INT\n");
                else if($$ == 1)
                  printf("VALID, TYPE IS CHAR\n");
              }
      ;

S:  E '==' E  {
                if($1==4 || $3==4)
                  $$=4;
                else if($1==3 || $3==3)
                  $$=3;
                else if($1==2 || $3==2)
                  $$=2;
                else if($1==1 || $3==1)
                  $$=1;
              }
  | E         {$$=$1;}
;

E: E '+' T  {
              if($1==4 || $3==4)
                $$=4;
              else if($1==3 || $3==3)
                $$=3;
              else if($1==2 || $3==2)
                $$=2;
              else if($1==1 || $3==1)
                $$=1;
            }
  |E '-' T  {
              if($1==4 || $3==4)
                $$=4;
              else if($1==3 || $3==3)
                $$=3;
              else if($1==2 || $3==2)
                $$=2;
              else if($1==1 || $3==1)
                $$=1;
            }
  |T        {$$=$1;}
  ;

T: T '*' F  {
              if($1==4 || $3==4)
                $$=4;
              else if($1==3 || $3==3)
                $$=3;
              else if($1==2 || $3==2)
                $$=2;
              else if($1==1 || $3==1)
                $$=1;
            }
  |T '/' F  {
              if($1==4 || $3==4)
                $$=4;
              else if($1==3 || $3==3)
                $$=3;
              else if($1==2 || $3==2)
                $$=2;
              else if($1==1 || $3==1)
                $$=1;
            }
  |F        {$$=$1;}
  ;

F:  '(' E ')'   {$$=$2;}
   |INTCONST    {$$=$1;}
   |FRACCONST   {$$=$1;}
   |CHARCONST   {$$=$1;}
   |OTHER       {$$=$1;}
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