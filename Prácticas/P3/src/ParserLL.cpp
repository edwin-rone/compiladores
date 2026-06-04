#include "headers/ParserLL.hpp"
#include <iostream>
#include <cstdlib>

// Usaremos un offset de 100 para diferenciar los ID de No-Terminales de los Terminales
// ya que ambos inician en 0 dentro de sus respectivos enum.
const int NT_OFFSET = 100;


ParserLL::ParserLL(Lexer *lexer)
{
    this->lexer = lexer;
    loadSyms();
    loadProds();
    loadTable();
}

ParserLL::~ParserLL()
{
}


void ParserLL::loadSyms()
{
  /*********************************************
   * 4. Agregar todos los símbolos (N'∪T) de G'*
   *********************************************/
    // Terminales (T)
    grammar.addSymbol(t_eof, Symbol(t_eof));
    grammar.addSymbol(INT, Symbol(INT));
    grammar.addSymbol(FLOAT, Symbol(FLOAT));
    grammar.addSymbol(IF, Symbol(IF));
    grammar.addSymbol(ELSE, Symbol(ELSE));
    grammar.addSymbol(WHILE, Symbol(WHILE));
    grammar.addSymbol(PYC, Symbol(PYC));
    grammar.addSymbol(COMA, Symbol(COMA));
    grammar.addSymbol(ASIG, Symbol(ASIG));
    grammar.addSymbol(MAS, Symbol(MAS));
    grammar.addSymbol(MENOS, Symbol(MENOS));
    grammar.addSymbol(MUL, Symbol(MUL));
    grammar.addSymbol(DIV, Symbol(DIV));
    grammar.addSymbol(LPAR, Symbol(LPAR));
    grammar.addSymbol(RPAR, Symbol(RPAR));
    grammar.addSymbol(IDENTIFICADOR, Symbol(IDENTIFICADOR));
    grammar.addSymbol(NUMERO, Symbol(NUMERO));
    grammar.addSymbol(EPSILON, Symbol(EPSILON));

    // No-Terminales (N') - Les sumamos el NT_OFFSET para no chocar con los IDs de Terminales
    grammar.addSymbol(NT_OFFSET + nt_programa, Symbol(nt_programa));
    grammar.addSymbol(NT_OFFSET + nt_declaraciones, Symbol(nt_declaraciones));
    grammar.addSymbol(NT_OFFSET + nt_declaraciones_prima, Symbol(nt_declaraciones_prima));
    grammar.addSymbol(NT_OFFSET + nt_declaracion, Symbol(nt_declaracion));
    grammar.addSymbol(NT_OFFSET + nt_tipo, Symbol(nt_tipo));
    grammar.addSymbol(NT_OFFSET + nt_lista_var, Symbol(nt_lista_var));
    grammar.addSymbol(NT_OFFSET + nt_lista_var_prima, Symbol(nt_lista_var_prima));
    grammar.addSymbol(NT_OFFSET + nt_sentencias, Symbol(nt_sentencias));
    grammar.addSymbol(NT_OFFSET + nt_sentencias_prima, Symbol(nt_sentencias_prima));
    grammar.addSymbol(NT_OFFSET + nt_sentencia, Symbol(nt_sentencia));
    grammar.addSymbol(NT_OFFSET + nt_expresion, Symbol(nt_expresion));
    grammar.addSymbol(NT_OFFSET + nt_expresion_prima, Symbol(nt_expresion_prima));
    grammar.addSymbol(NT_OFFSET + nt_termino, Symbol(nt_termino));
    grammar.addSymbol(NT_OFFSET + nt_termino_prima, Symbol(nt_termino_prima));
    grammar.addSymbol(NT_OFFSET + nt_factor, Symbol(nt_factor));
    
    // Indicamos a la gramática cuál es el símbolo inicial
    grammar.start = NT_OFFSET + nt_programa;
   
}

void ParserLL::loadProds()
{
  /************************************************
   * 5. Agregar todas las producciones (P') de G' *
   ************************************************/ 
    grammar.addProd(1, Production(NT_OFFSET + nt_programa, {NT_OFFSET + nt_declaraciones, NT_OFFSET + nt_sentencias}));
    grammar.addProd(2, Production(NT_OFFSET + nt_declaraciones, {NT_OFFSET + nt_declaracion, NT_OFFSET + nt_declaraciones_prima}));
    grammar.addProd(3, Production(NT_OFFSET + nt_declaraciones_prima, {NT_OFFSET + nt_declaracion, NT_OFFSET + nt_declaraciones_prima}));
    grammar.addProd(4, Production(NT_OFFSET + nt_declaraciones_prima, {EPSILON}));
    grammar.addProd(5, Production(NT_OFFSET + nt_declaracion, {NT_OFFSET + nt_tipo, NT_OFFSET + nt_lista_var, PYC}));
    grammar.addProd(6, Production(NT_OFFSET + nt_tipo, {INT}));
    grammar.addProd(7, Production(NT_OFFSET + nt_tipo, {FLOAT}));
    grammar.addProd(8, Production(NT_OFFSET + nt_lista_var, {IDENTIFICADOR, NT_OFFSET + nt_lista_var_prima}));
    grammar.addProd(9, Production(NT_OFFSET + nt_lista_var_prima, {COMA, IDENTIFICADOR, NT_OFFSET + nt_lista_var_prima}));
    grammar.addProd(10, Production(NT_OFFSET + nt_lista_var_prima, {EPSILON}));
    grammar.addProd(11, Production(NT_OFFSET + nt_sentencias, {NT_OFFSET + nt_sentencia, NT_OFFSET + nt_sentencias_prima}));
    grammar.addProd(12, Production(NT_OFFSET + nt_sentencias_prima, {NT_OFFSET + nt_sentencia, NT_OFFSET + nt_sentencias_prima}));
    grammar.addProd(13, Production(NT_OFFSET + nt_sentencias_prima, {EPSILON}));
    grammar.addProd(14, Production(NT_OFFSET + nt_sentencia, {IDENTIFICADOR, ASIG, NT_OFFSET + nt_expresion, PYC}));
    grammar.addProd(15, Production(NT_OFFSET + nt_sentencia, {IF, LPAR, NT_OFFSET + nt_expresion, RPAR, NT_OFFSET + nt_sentencias, ELSE, NT_OFFSET + nt_sentencias}));
    grammar.addProd(16, Production(NT_OFFSET + nt_sentencia, {WHILE, LPAR, NT_OFFSET + nt_expresion, RPAR, NT_OFFSET + nt_sentencias}));
    grammar.addProd(17, Production(NT_OFFSET + nt_expresion, {NT_OFFSET + nt_termino, NT_OFFSET + nt_expresion_prima}));
    grammar.addProd(18, Production(NT_OFFSET + nt_expresion_prima, {MAS, NT_OFFSET + nt_termino, NT_OFFSET + nt_expresion_prima}));
    grammar.addProd(19, Production(NT_OFFSET + nt_expresion_prima, {MENOS, NT_OFFSET + nt_termino, NT_OFFSET + nt_expresion_prima}));
    grammar.addProd(20, Production(NT_OFFSET + nt_expresion_prima, {EPSILON}));
    grammar.addProd(21, Production(NT_OFFSET + nt_termino, {NT_OFFSET + nt_factor, NT_OFFSET + nt_termino_prima}));
    grammar.addProd(22, Production(NT_OFFSET + nt_termino_prima, {MUL, NT_OFFSET + nt_factor, NT_OFFSET + nt_termino_prima}));
    grammar.addProd(23, Production(NT_OFFSET + nt_termino_prima, {DIV, NT_OFFSET + nt_factor, NT_OFFSET + nt_termino_prima}));
    grammar.addProd(24, Production(NT_OFFSET + nt_termino_prima, {EPSILON}));
    grammar.addProd(25, Production(NT_OFFSET + nt_factor, {LPAR, NT_OFFSET + nt_expresion, RPAR}));
    grammar.addProd(26, Production(NT_OFFSET + nt_factor, {IDENTIFICADOR}));
    grammar.addProd(27, Production(NT_OFFSET + nt_factor, {NUMERO}));
    
}

void ParserLL::loadTable()
{

  /*************************************************
   **     6.Cargar la tabla de AS predictivo      **
   *************************************************/
    table[nt_programa][INT] = 1; table[nt_programa][FLOAT] = 1;
    table[nt_declaraciones][INT] = 2; table[nt_declaraciones][FLOAT] = 2;
    table[nt_declaraciones_prima][INT] = 3; table[nt_declaraciones_prima][FLOAT] = 3;
    table[nt_declaraciones_prima][IDENTIFICADOR] = 4; table[nt_declaraciones_prima][IF] = 4; table[nt_declaraciones_prima][WHILE] = 4;
    table[nt_declaracion][INT] = 5; table[nt_declaracion][FLOAT] = 5;
    table[nt_tipo][INT] = 6; table[nt_tipo][FLOAT] = 7;
    table[nt_lista_var][IDENTIFICADOR] = 8;
    table[nt_lista_var_prima][COMA] = 9; table[nt_lista_var_prima][PYC] = 10;
    table[nt_sentencias][IDENTIFICADOR] = 11; table[nt_sentencias][IF] = 11; table[nt_sentencias][WHILE] = 11;
    table[nt_sentencias_prima][IDENTIFICADOR] = 12; table[nt_sentencias_prima][IF] = 12; table[nt_sentencias_prima][WHILE] = 12;
    table[nt_sentencias_prima][ELSE] = 13; table[nt_sentencias_prima][t_eof] = 13;
    table[nt_sentencia][IDENTIFICADOR] = 14; table[nt_sentencia][IF] = 15; table[nt_sentencia][WHILE] = 16;
    table[nt_expresion][IDENTIFICADOR] = 17; table[nt_expresion][NUMERO] = 17; table[nt_expresion][LPAR] = 17;
    table[nt_expresion_prima][MAS] = 18; table[nt_expresion_prima][MENOS] = 19; table[nt_expresion_prima][PYC] = 20; table[nt_expresion_prima][RPAR] = 20;
    table[nt_termino][IDENTIFICADOR] = 21; table[nt_termino][NUMERO] = 21; table[nt_termino][LPAR] = 21;
    table[nt_termino_prima][MUL] = 22; table[nt_termino_prima][DIV] = 23; table[nt_termino_prima][MAS] = 24;
    table[nt_termino_prima][MENOS] = 24; table[nt_termino_prima][PYC] = 24; table[nt_termino_prima][RPAR] = 24;
    table[nt_factor][LPAR] = 25; table[nt_factor][IDENTIFICADOR] = 26; table[nt_factor][NUMERO] = 27;
  
}

int ParserLL::parse()
{
  /**************************************************
   ** 7. Implementar el algoritmo de AS predictivo **
   **************************************************/

    //Auxiliares
    stack<Symbol> pila;    
    map<Token, int>::iterator accion;    
    vector<int> body;    
    Symbol X;

    token = eat();
    
    // Apilamos el fin de archivo y el símbolo inicial
    pila.push(grammar.getSym(t_eof));
    pila.push(grammar.getSym(grammar.start));

    while (!pila.empty()) {
        X = pila.top();
        pila.pop();

        // Caso 1: El tope de la pila es un terminal
        if (X.getType() == terminal) {
            if (X.getToken() == EPSILON) {
                continue; // Las transiciones vacías simplemente se desapilan
            } else if (X.getToken() == token) {
                if (token == t_eof) break; // Fin exitoso
                token = eat(); // Match correcto, avanzamos la entrada
            } else {
                error("Error de sintaxis: Se esperaba otro token");
            }
        } 
        // Caso 2: El tope de la pila es un No-Terminal
        else {
            NoTerm nt = X.getNoTerm();
            accion = table[nt].find(token);
            
            // Verificamos si existe una regla en la tabla predictiva
            if (accion != table[nt].end()) {
                int prodId = accion->second;
                Production p = grammar.getProd(prodId);
                body = p.getBody();
                
                // Apilamos los símbolos del cuerpo de la producción de forma inversa
                for (int i = body.size() - 1; i >= 0; --i) {
                    pila.push(grammar.getSym(body[i]));
                }
            } else {
                error("Error de sintaxis: Token inesperado");
            }
        }
    }

    aceptar("¡Análisis sintáctico exitoso! La cadena es aceptada.");
    return 0;
}

void ParserLL::error(string msg)
{
    cout << msg << " en la línea " << lexer->getLine() << endl;
    exit(EXIT_FAILURE);
}

Token ParserLL::eat()
{
    return (Token) lexer->yylex();    
}

void ParserLL::aceptar(string msg)
{
    cout<<msg<<endl;
}
