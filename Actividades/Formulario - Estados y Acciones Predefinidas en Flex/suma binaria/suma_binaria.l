%{
#include <stdio.h>
#include <stdlib.h>
int suma_total = 0;
%}

%%
0b[0-1]+    { 
                /* yytext+2 salta el "0b", strtol convierte base 2 a base 10 */
                suma_total += strtol(yytext + 2, NULL, 2); 
            }
.|\n        { /* Ignorar lo demás */ }
<<EOF>>     { printf("Suma total en base 10: %d\n", suma_total); yyterminate(); }
%%

int main() {
    yylex();
    return 0;
}