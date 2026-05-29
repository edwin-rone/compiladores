%{
int lineas = 0;
int palabras = 0;
int bytes = 0;
%}

%%
\n              { lineas++; bytes++; }
[^ \t\n\r]+     { palabras++; bytes += yyleng; }
.               { bytes++; }
<<EOF>>         { printf("\t%d\t%d\t%d\n", lineas, palabras, bytes); yyterminate(); }
%%

int main() {
    yylex();
    return 0;
}