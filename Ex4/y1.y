%{
#include<stdio.h>
#include "y.tab.h"
#include<math.h>
%}
%token NUMBER
%%

S:E {printf("%d\n",$$);}
;

E: E '+' T  {$$=$1+$3;}
  |E '-' T  {$$=$1-$3;}
  |T        {$$=$1;}
  ;

T: T '*' F  {$$=$1*$3;}
  |T '/' F  {$$=$1/$3;}
  |F        {$$=$1;}
  ;

F: F '^' F {$$=pow($1,$3);}
  |M       {$$=$1;}
  ;

M:  '(' E ')' {$$=$2;}
   |NUMBER    {$$=$1;}
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