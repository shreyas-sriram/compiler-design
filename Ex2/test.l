%{
#include <stdio.h>
%}
%%
if|else|while|int|switch|for|char    {printf("keyword");}
[a-z]([a-z]|[0-9])*    {printf("identifier");}
[0-9]*        {printf("number");}
.*    {printf("invalid");}
%%
int main(int argc, char **argv)
{
	FILE *fp;
	fp=fopen(argv[1],"r");
	yyin=fp;
	yylex();
	return 0;
}
int yywrap()
{
	return 1;
}