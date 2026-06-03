#ifndef PARSER_H
#define PARSER_H
#include <string>
#include "Lexer.hpp"
#include "Symbols.hpp"
using namespace std;

namespace C_1
{
  class Parser
  {

  private:
    Lexer *lexer;
    int token;
    
  public:
    Parser();
    Parser(Lexer *lexer);
    ~Parser();
    
    void programa(); //función del símbolo incial
    void declaraciones();
    void declaraciones_prima();
    void declaracion();
    void tipo();
    void lista_var();
    void lista_var_prima();
    void sentencias();
    void sentencias_prima();
    void sentencia();
    void expresion();
    void expresion_prima();
    void termino();
    void termino_prima();
    void factor();

    Token eat();
    void error(string msg);
    void parse();
    void match(Token expected); // Función para avanzar tokens
  };    
    
}


#endif
