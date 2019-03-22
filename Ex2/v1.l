//Lex code to identify keywords, functions, special characters, identifiers, constants and comments in C code
%{
	#include <stdio.h>
%}

letter [a-zA-Z]
digit [0-9]
space [:space:]
identifier {letter}({letter}|{digit})*
intConst ({digit})+
digits {digit}({digit})*
optFrac ({digit})*\.{intConst}
optExp {digits}E([\+|\-|])?{digits}
charConst '{letter}'
strConst \"(.)*\"

relop <|<=|==|!=|>|>=
arithop \+|\-|\*|\/|%
logicalop &&|\|\||!
operator {relop}|{arithop}|{logicalop}

specialCharacters \;|\,|\{|\}|\[|\]|\(|\)|\:

function printf\(\"(.)*\);|scanf\(\"(.)*\);|main\(\)

SLC \/\/(.)*
MLC \/\*((.)|\n)*\*\/

assign [=]

%%

if|else|while|int|switch|for|char|float  {printf(" KW");}

{function} {printf(" FN");}

{identifier} {printf(" ID");}

{specialCharacters} {printf(" SP");}

{operator} {printf(" OP");}

{intConst} {printf(" INTCONST");}

{assign} {printf(" ASSIGN");}

{optFrac} {printf(" optFrac");}

{optExp} {printf(" optExp");}

{charConst} {printf(" charConst");}

{strConst} {printf(" strConst");}

{MLC} {printf(" Multiline Comment");}

{SLC} {printf(" Singleline Comment");}


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
