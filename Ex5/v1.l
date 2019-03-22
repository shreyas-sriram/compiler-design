%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "y.tab.h"
  int c;
  extern int yylval;
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

%%

" "       ;

if|else|for {return *yytext;}

{KW}	{
	        yylval = atoi(yytext);
	        return(KEYWORD);
      	}

{identifier} {
				        yylval = atoi(yytext);
		            return(IDENTIFIER);
			       }

{const}   {
            yylval = atoi(yytext);
            return(CONSTANT);
          }

\=\=|\>\=|\<\=|\!\=|\>|\< {
                            yylval = atoi(yytext);
                            return(RELOP);
                          }

\+|\-|\/|\* {
              yylval = atoi(yytext);
              return(ARITHOP);
            }

=|\,|\;|\(|\) {return *yytext;}

\n {return *yytext;}

%%