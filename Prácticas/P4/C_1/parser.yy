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
%define api.namespace {c1}
%parse-param {Lexer* lexer}

%code requires {
    namespace c1 { class Lexer; }
}

%code {
    #include "Lexer.hpp"
    #define yylex(x) lexer->lex(x)
}

%token INT FLOAT IF ELSE WHILE
%token MAS MENOS MUL DIV ASIG PYC COMA
%token PARIZQ PARDER LLAVEIZQ LLAVEDER
%token IDENTIFICADOR NUMERO

%left MAS MENOS
%left MUL DIV

%start programa

%%

programa: declaraciones sentencias { cout << "Analisis concluido: Programa valido segun la gramatica C_1." << endl; };

declaraciones: declaraciones declaracion
             | declaracion
             ;

declaracion: tipo lista_var PYC
           ;

tipo: INT
    | FLOAT
    ;

lista_var: lista_var COMA IDENTIFICADOR
         | IDENTIFICADOR
         ;

sentencias: sentencias sentencia
          | sentencia
          ;

sentencia: IDENTIFICADOR ASIG expresion PYC
         | IF PARIZQ expresion PARDER LLAVEIZQ sentencias LLAVEDER ELSE LLAVEIZQ sentencias LLAVEDER
         | WHILE PARIZQ expresion PARDER LLAVEIZQ sentencias LLAVEDER
         ;

expresion: expresion MAS expresion
         | expresion MENOS expresion
         | expresion MUL expresion
         | expresion DIV expresion
         | IDENTIFICADOR
         | NUMERO
         | PARIZQ expresion PARDER
         ;

%%

void c1::Parser::error(const std::string& msg) {
    std::cerr << "\n>>> ERROR SINTACTICO DETECTADO <<<" << '\n';
    std::cerr << "Motivo reportado por Bison: " << msg << '\n';
    std::cerr << "El analizador no pudo reducir la expresion con las reglas definidas en la gramatica." << '\n';
}

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[]){
    if(argc < 2){
        cout<<"Uso: ./compiler archivo_prueba"<<endl;
        return EXIT_FAILURE;
    }
    filebuf fb;
    fb.open(string(argv[1]), ios::in);
    istream in(&fb);
    c1::Lexer lexer(&in);
    c1::Parser parser(&lexer);
    parser.parse();
    fb.close();
    return 0;
}