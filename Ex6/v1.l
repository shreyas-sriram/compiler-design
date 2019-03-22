%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "y.tab.h"
  int c;
  extern int yylval;
%}

%%

" "       ;
[0-9]+    {
            yylval = atoi(yytext);
            return(NUMBER);
          }
\+|\-|\*|\/|\(|\)|\^|% {return *yytext;}

\n { return *yytext;}

%%