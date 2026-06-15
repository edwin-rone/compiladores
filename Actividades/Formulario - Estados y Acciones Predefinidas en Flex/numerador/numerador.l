%{
#include <stdio.h>
int num_linea = 1;
%}

%%
.*\n    { printf("%d: %s", num_linea++, yytext); }
.* { printf("%d: %s\n", num_linea++, yytext); } /* Por si la última línea no tiene salto */
%%

int main() {
    yylex();
    return 0;
}