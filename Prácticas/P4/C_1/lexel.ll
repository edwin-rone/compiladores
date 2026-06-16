%{
#include <iostream>
#include <string>
#include "Parser.hpp"
#include "Lexer.hpp"

using namespace std;

#undef YY_DECL
#define YY_DECL int c1::Lexer::lex(c1::Parser::semantic_type *yylval)
%}

%option c++
%option noyywrap
%option outfile="Lexer.cpp"
%option yyclass="Lexer"
%option yylineno

DIG [0-9]
ID  [a-zA-Z_][a-zA-Z0-9_]*
WSPC [ \t\r]+

%%

"int"       { return Parser::token::INT; }
"float"     { return Parser::token::FLOAT; }
"if"        { return Parser::token::IF; }
"else"      { return Parser::token::ELSE; }
"while"     { return Parser::token::WHILE; }

"+"         { return Parser::token::MAS; }
"-"         { return Parser::token::MENOS; }
"*"         { return Parser::token::MUL; }
"/"         { return Parser::token::DIV; }
"="         { return Parser::token::ASIG; }
";"         { return Parser::token::PYC; }
","         { return Parser::token::COMA; }
"("         { return Parser::token::PARIZQ; }
")"         { return Parser::token::PARDER; }
"{"         { return Parser::token::LLAVEIZQ; }
"}"         { return Parser::token::LLAVEDER; }

{DIG}+         { return Parser::token::NUMERO; }
{DIG}+\.{DIG}+ { return Parser::token::NUMERO; }

{ID}        { return Parser::token::IDENTIFICADOR; }

\n          { /* yylineno cuenta las lineas automaticamente */ }
{WSPC}      { /* Ignoramos espacios en blanco */ }

.           { cout << "Error lexico en la linea: " << yylineno << " Token no reconocido: " << yytext << endl; }

<<EOF>>     { yyterminate(); }

%%