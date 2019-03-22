%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "y.tab.h"
  int c;
  extern int yylval;
%}

digit [0-9]
letter [a-zA-Z]
intConst [0-9]+
fracConst ({digit})*\.{intConst}
charConst '{letter}'

%%

" "       ;

{charConst}   {
                yylval = 1;
                return(CHARCONST);
              }

{intConst}	{
    	        yylval = 2;
    	        return(INTCONST);
      	     }

{fracConst} {
  			        yylval = 3;
  	            return(FRACCONST);
  		       }

\+|\-|\/|\*|\=\=|\(|\) {return *yytext;}

\n {return *yytext;}

. {
    yylval = 4;
    return(OTHER);
  }

%%