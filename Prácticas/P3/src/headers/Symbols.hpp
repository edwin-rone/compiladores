#ifndef __SYMBOLS_HPP__
#define __SYMBOLS_HPP__

/** 
 * 1. Definir en un comentario la gramática G'(N', T, P', S)
 *
 * S = programa
 * * N' = {programa, declaraciones, declaraciones_prima, declaracion, tipo, 
 * lista_var, lista_var_prima, sentencias, sentencias_prima, sentencia, 
 * expresion, expresion_prima, termino, termino_prima, factor}
 * * T = {int, float, if, else, while, identificador, numero, ;, ,, =, +, -, *, /, (, ), $}
 * * P' = {
 * programa -> declaraciones sentencias
 * declaraciones -> declaracion declaraciones_prima
 * declaraciones_prima -> declaracion declaraciones_prima | epsilon
 * declaracion -> tipo lista_var ;
 * tipo -> int | float
 * lista_var -> identificador lista_var_prima
 * lista_var_prima -> , identificador lista_var_prima | epsilon
 * sentencias -> sentencia sentencias_prima
 * sentencias_prima -> sentencia sentencias_prima | epsilon
 * sentencia -> identificador = expresion ; | if ( expresion ) sentencias else sentencias | while ( expresion ) sentencias
 * expresion -> termino expresion_prima
 * expresion_prima -> + termino expresion_prima | - termino expresion_prima | epsilon
 * termino -> factor termino_prima
 * termino_prima -> * factor termino_prima | / factor termino_prima | epsilon
 * factor -> ( expresion ) | identificador | numero
 * }
 */


/**
 * 2. Determinar la enumeración para el conjunto T
 */
enum Token { 
    t_eof = 0, primero, 
    INT, FLOAT, IF, ELSE, WHILE,
    PYC, COMA, ASIG, 
    MAS, MENOS, MUL, DIV, 
    LPAR, RPAR, 
    IDENTIFICADOR, NUMERO,
    EPSILON
};

/**
 * 3. Determinar la enumeración para el conjunto N
 */
enum NoTerm { 
    strEmpty, 
    nt_programa, nt_declaraciones, nt_declaraciones_prima, 
    nt_declaracion, nt_tipo, nt_lista_var, nt_lista_var_prima, 
    nt_sentencias, nt_sentencias_prima, nt_sentencia, 
    nt_expresion, nt_expresion_prima, 
    nt_termino, nt_termino_prima, nt_factor
};

#endif // !__SYMBOLS_HPP__
