%{
#include <iostream>
#include <string>
using namespace std;

#include "tokens.hpp"
#include "Lexer.hpp"

%}

%option c++
%option outfile="Lexer.cpp"
%option yyclass="C_1::Lexer"
%option case-insensitive


    //DIG [0-9]
ESPACIO [ \t\n\r]+
NUMERO  [0-9]+(\.[0-9]+)?([eE][+-]?[0-9]+)?
ID      [a-zA-Z_][a-zA-Z0-9_]*

%%

{ESPACIO} { /* Ignoramos los espacios */ }

"int"   { cout << C_1::INT << ", " << yytext << endl; }
"float" { cout << C_1::FLOAT << ", " << yytext << endl; }
"if"    { cout << C_1::IF << ", " << yytext << endl; }
"else"  { cout << C_1::ELSE << ", " << yytext << endl; }
"while" { cout << C_1::WHILE << ", " << yytext << endl; }

"+"     { cout << C_1::MAS << ", " << yytext << endl; }
"-"     { cout << C_1::MENOS << ", " << yytext << endl; }
"*"     { cout << C_1::MUL << ", " << yytext << endl; }
"/"     { cout << C_1::DIV << ", " << yytext << endl; }
"="     { cout << C_1::ASIG << ", " << yytext << endl; }
"("     { cout << C_1::LPAR << ", " << yytext << endl; }
")"     { cout << C_1::RPAR << ", " << yytext << endl; }
","     { cout << C_1::COMA << ", " << yytext << endl; }
";"     { cout << C_1::PYC << ", " << yytext << endl; }

{ID}      { cout << C_1::ID << ", " << yytext << endl; }
{NUMERO}  { cout << C_1::NUMERO << ", " << yytext << endl; }

.   { cout << "ERROR LEXICO" << yytext << endl;}

%%

int yyFlexLexer::yywrap(){
    return 1;
}

