#include "headers/Parser.hpp"
#include <iostream>
#include <cstdlib> // Para usar exit()

namespace C_1
{
  Parser::Parser(/* args */)
  {
  }

  Parser::Parser(Lexer *lexer)
  {
    this->lexer = lexer;
  }
    
  Parser::~Parser()
  {
  }

  void Parser::programa(){
    declaraciones();
    sentencias();
  }

  /************************************************************************/
  /**                                                                    **/
  /**                       Funciones por cada NT                        **/
  /**                                                                    **/
  /************************************************************************/

  void Parser::declaraciones(){
    declaracion();
    declaraciones_prima();
  }

  void Parser::declaraciones_prima(){
    if (token == INT || token == FLOAT) {
        declaracion();
        declaraciones_prima();
    } else {
        // Epsilon: no hacemos nada, salimos de la funcion
    }
  }

  void Parser::declaracion(){
    tipo();
    lista_var();
    match(PYC); // Esperamos un punto y coma ';'
  }

  void Parser::tipo(){
    if (token == INT) {
        match(INT);
    } else if (token == FLOAT) {
        match(FLOAT);
    } else {
        error("Se esperaba un tipo de dato (int o float)");
    }
  }

  void Parser::lista_var(){
    match(IDENTIFICADOR);
    lista_var_prima();
  }

  void Parser::lista_var_prima(){
    if (token == COMA) {
        match(COMA);
        match(IDENTIFICADOR);
        lista_var_prima();
    } else {
        // Epsilon
    }
  }

  void Parser::sentencias(){
    sentencia();
    sentencias_prima();
  }

  void Parser::sentencias_prima(){
    // FIRST(sentencia) = {identificador, if, while}
    if (token == IDENTIFICADOR || token == IF || token == WHILE) {
        sentencia();
        sentencias_prima();
    } else {
        // Epsilon
    }
  }

  void Parser::sentencia(){
    if (token == IDENTIFICADOR) {
        match(IDENTIFICADOR);
        match(ASIG); // Esperamos '='
        expresion();
        match(PYC);  // Esperamos ';'
    } else if (token == IF) {
        match(IF);
        match(LPAR); // Esperamos '('
        expresion();
        match(RPAR); // Esperamos ')'
        sentencias();
        match(ELSE);
        sentencias();
    } else if (token == WHILE) {
        match(WHILE);
        match(LPAR);
        expresion();
        match(RPAR);
        sentencias();
    } else {
        error("Se esperaba una sentencia valida");
    }
  }

  void Parser::expresion(){
    termino();
    expresion_prima();
  }

  void Parser::expresion_prima(){
    if (token == MAS) {
        match(MAS);
        termino();
        expresion_prima();
    } else if (token == MENOS) {
        match(MENOS);
        termino();
        expresion_prima();
    } else {
        // Epsilon
    }
  }

  void Parser::termino(){
    factor();
    termino_prima();
  }

  void Parser::termino_prima(){
    // FIRST(termino_prima) = {*, /}
    if (token == MUL) {
        match(MUL);
        factor();
        termino_prima();
    } else if (token == DIV) {
        match(DIV);
        factor();
        termino_prima();
    } else {
        // Epsilon
    }
  }

  void Parser::factor(){
    if (token == LPAR) {
        match(LPAR);
        expresion();
        match(RPAR);
    } else if (token == IDENTIFICADOR) {
        match(IDENTIFICADOR);
    } else if (token == NUMERO) {
        match(NUMERO);
    } else {
        error("Se esperaba un factor (numero, identificador o '(')");
    }
  }


  Token Parser::eat(){
    return (Token) lexer->yylex();
  }

  void Parser::error(string msg){
    cout << "ERROR DE SINTAXIS " << msg << " en la línea "<< lexer->getLine() <<endl;
    exit(1); // Detenemos el parser al primer error para evitar ciclos infinitos
  }   

  void Parser::match(Token expected){
    if (token == expected) {
        token = eat(); // Consumimos el token y leemos el siguiente
    } else {
        error("Se encontro un token inesperado");
    }
  }

  void Parser::parse(){
    token = eat();
    programa();
    if(token == t_eof)
      cout << "La cadena es aceptada" << endl;
    else 
      cout << "La cadena no pertenece al lenguaje generado por la gramática" << endl;
  }

}
