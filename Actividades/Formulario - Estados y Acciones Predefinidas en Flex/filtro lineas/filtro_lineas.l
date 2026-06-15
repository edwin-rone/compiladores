%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int suma_actual = 0;
char buffer[2048] = "";
%}

%%
[0-9]+      { 
                suma_actual += atoi(yytext); 
                strcat(buffer, yytext); 
            }
[ \t]+      { strcat(buffer, yytext); }
A\n         { 
                printf("Suma de la línea: %d\n", suma_actual); 
                suma_actual = 0; 
                buffer[0] = '\0'; 
            }
B\n         { 
                printf("%sB\n", buffer); 
                suma_actual = 0; 
                buffer[0] = '\0'; 
            }
.|\n        { /* Ignorar cualquier otra cosa extraña */ }
%%

int main() {
    yylex();
    return 0;
}