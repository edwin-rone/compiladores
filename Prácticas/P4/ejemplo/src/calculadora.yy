%{
#include <iostream>
#include <fstream>
#include <string>
#include <FlexLexer.h>
using namespace std;
%}

%language "C++"
%require "3.2"
%defines "Parser.hpp"
%output "Parser.cpp"
 
%define api.parser.class {Parser}
%define api.namespace {calc}
%parse-param {Lexer* lexer}

%code requires
{
    namespace calc {
        class Lexer;
    } // namespace calc
} // %code requires
 
%code
{
 #include "Lexer.hpp"
 #define yylex(x) lexer->lex(x) // Referencia a 1 en Lexer.hpp
}

%union {
  struct { //declarado para manejar los tipos de número posibles: 1.- entero, 2.- flotante.
    float fval; // Cambiado a float para soportar decimales 
    int tipo;
  } numero;
}

%token<numero> NUM
%token EOL

%left MAS MENOS
%left MUL DIV
%precedence UMINUS // Precedencia para el menos unario

%nonassoc PARIZQ
%nonassoc PARDER

%type<numero> expresion

%start lineas

%%

lineas: lineas linea 
    | linea 
    ;

line: expresion EOL { cout << "Análisis léxico y sintáctico terminado.\nEl valor de la expresión ya evaluada es: " << $1.fval << endl; }
    | EOL { /* Ignorar lineas en blanco */ }
    ;

expresion : expresion MAS expresion { $$.fval = $1.fval + $3.fval; }
    | expresion MENOS expresion { $$.fval = $1.fval - $3.fval; }
	| expresion MUL expresion { $$.fval = $1.fval * $3.fval; }
    | expresion DIV expresion { 
        if($3.fval == 0) {
            cout << "Error matematico: Division por cero." << endl;
            $$.fval = 0;
        } else {
            $$.fval = $1.fval / $3.fval; 
        }
    }
    | MENOS expresion %prec UMINUS { $$.fval = -$2.fval; } // Menos unario
	| PARIZQ expresion PARDER { $$ = $2; };
	| NUM { $$ = $1; }
    ;


%%

void calc::Parser::error(const std::string& msg) {
    std::cerr << "Error de sintaxis: " << msg << '\n';
}


#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[]){
    if(argc < 2){
        cout<<"Faltan argumentos "<<endl;
        return EXIT_FAILURE;
    }
    filebuf fb;
    fb.open(string(argv[1]), ios::in);
    istream in(&fb);
    calc::Lexer lexer(&in);
    calc::Parser parser(&lexer);
    parser.parse();
    fb.close();
    return 0;
    /*
    calc::Lexer scanner{ std::cin, std::cerr };
    calc::Parser parser{ &scanner };
    //std::cout.precision(10);
    parser.parse();*/
}
