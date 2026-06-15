%{
#include <sstream>
#include <cstdlib>

#include "Parser.hpp"
#include "Lexer.hpp"

using namespace std;

#undef YY_DECL // Buena práctica
#define YY_DECL int calc::Lexer::lex(calc::Parser::semantic_type *yylval) // Referencia a 1 en Lexer.hpp
%}

%option c++
%option noyywrap
%option outfile="Lexer.cpp"
%option yyclass="Lexer"


DIG [0-9]
WSPC [ \t]+

%%


"+"	{
	 cout << "Terminal + detectado" << endl;	
	 return Parser::token::MAS;
	}

"*"	{
	 cout << "Terminal * detectado" << endl;	
	 return Parser::token::MUL;
	}

"("	{
	 cout << "Terminal ( detectado" << endl;	
	 return Parser::token::PARIZQ;
	}

")"	{
	 cout << "Terminal ) detectado" << endl;	
	 return Parser::token::PARDER;
	}

" \ n " { 
	cout << "Salto de línea detectado" << endl;
	return Parser :: token :: EOL ; }

{DIG}+	{
	 cout << "Terminal numérico " << yytext << " detectado" << endl;
	 yylval->numero.fval = atof(yytext);
	 yylval->numero.tipo = 1; /* 1: Entero, 2: Flotante */
	 return Parser::token::NUM;
	}

{ DIG }+\.{ DIG }+ {
	yylval->numero.fval = atof(yytext);
	yylval->numero.tipo = 2;
	return Parser::token::NUM ;
}

{WSPC}  { /* Ignoramos espacios en blanco */ }

.	{
	  cout << "Error léxico en la línea: " << yylineno << endl;
	}


<<EOF>> {	
         yyterminate();
        }


%%

