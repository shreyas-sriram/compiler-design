//Lex code to build a Symbol Table for C code
%{
	#include<string.h>
	
	char tempK[100];
	int i = 0;

	struct symbolTable
	{
		char name[100];
		char type[100];
		char value[100];
	}s[100];
	
%}

letter [a-zA-Z]
digit [0-9]
digits {digit}({digit})*
identifier {letter}({letter}|{digit})*
intConst ({digit})+
fracConst ({digit})*\.{intConst}
expConst {digits}E([\+|\-|])?{digits}
charConst '{letter}'
const {intConst}|{expConst}|{fracConst}|{charConst}
KW int|char|float
endLine [;]

%%

{KW} {strcpy(tempK,yytext);}

{const}	{
					strcpy(s[i].value, yytext);
				}

{identifier}	{
								strcpy(s[i].name, yytext);
								strcpy(s[i].type, tempK);
								if(strcmp(tempK,"int")==0)
									strcpy(s[i].value, "0");
								else if(strcmp(tempK,"float")==0)
									strcpy(s[i].value, "0.0");
								else if(strcmp(tempK,"char")==0)
									strcpy(s[i].value, "NULL");
						 	}
					 
, {i++;}
						 
{endLine}	{
						i++;
						printf("\tNAME\t|\tTYPE\t|\tVALUE\n");
						for(int k=0;k<i;k++)
						{
							printf("\t%s\t|\t%s\t|\t%s\n",s[k].name,s[k].type,s[k].value);
						}
					}

\+|\-|\*|\/|% {}

= {}


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
