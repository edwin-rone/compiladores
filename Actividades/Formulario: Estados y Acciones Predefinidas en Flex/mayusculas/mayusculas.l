%{
#include <stdio.h>
#include <ctype.h>
%}

%%
[a-z]+      {
                for(int i = 0; i < yyleng; i++) {
                    printf("%c", toupper(yytext[i]));
                }
            }
.|\n        { ECHO; /* Deja espacios y símbolos tal cual */ }
%%

int main() {
    yylex();
    return 0;
}