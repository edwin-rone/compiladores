%{
#include <stdio.h>
char t[9];
int c = 0;

void evaluar_gato() {
    int wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int winX = 0, winO = 0, vacias = 0;
    
    for(int i=0; i<9; i++) { if(t[i] == '_') vacias++; }
    for(int i=0; i<8; i++) {
        if(t[wins[i][0]] == 'X' && t[wins[i][1]] == 'X' && t[wins[i][2]] == 'X') winX = 1;
        if(t[wins[i][0]] == 'O' && t[wins[i][1]] == 'O' && t[wins[i][2]] == 'O') winO = 1;
    }
    
    if(winX) printf(" -> gana X\n");
    else if(winO) printf(" -> gana 0\n"); /* Usa '0' como dice tu ejercicio */
    else if(vacias == 0) printf(" -> empate\n");
    else printf(" -> sin ganador\n");
}
%}

%%
[XO_]   { 
            printf("%s", yytext); /* Imprimir la letra */
            t[c++] = yytext[0]; 
            if(c == 9) { 
                evaluar_gato(); 
                c = 0; 
            } 
        }
\n      { printf("\n"); /* Mantener el formato del tablero */ }
.       { ECHO; }
%%

int main() {
    yylex();
    return 0;
}