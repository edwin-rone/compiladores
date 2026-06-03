%{
#include <iostream>
#include <string>
using namespace std;

#include "headers/Symbols.hpp"
#include "headers/Lexer.hpp"

int line=1;
%}

%option c++
%option outfile="Lexer.cpp"
%option yyclass="Lexer"

/* Definición de macros */
ID      [a-zA-Z_][a-zA-Z0-9_]*
NUMERO  [0-9]+(\.[0-9]+)?([eE][+-]?[0-9]+)?

%%

[ \t\r]+ { /* Ignoramos espacios */ }
"\n"     { line++; }

"int"    { return INT; }
"float"  { return FLOAT; }
"if"     { return IF; }
"else"   { return ELSE; }
"while"  { return WHILE; }

";"      { return PYC; }
","      { return COMA; }
"="      { return ASIG; }
"+"      { return MAS; }
"-"      { return MENOS; }
"*"      { return MUL; }
"/"      { return DIV; }
"("      { return LPAR; }
")"      { return RPAR; }

{ID}     { return IDENTIFICADOR; }
{NUMERO} { return NUMERO; }

.        { cout << "ERROR LEXICO en linea " << line << ": " << yytext << endl; }

%%

int yyFlexLexer::yywrap(){
    return 1;
}

int Lexer::getLine()
{
    return line;
}
