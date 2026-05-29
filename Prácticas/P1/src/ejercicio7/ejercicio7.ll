%{
  #include <iostream>
%}

%option c++
%option noyywrap

/* Macros para facilitarnos la vida */
espacio         [ ]+
hexadecimal     0[xX][0-9a-fA-F]+
identificador   [a-zA-Z_][a-zA-Z0-9_]{0,31}

%%

{espacio} { std::cout << "Espacio" << std::endl; }

"int"|"float"|"if"|"else"|"while" { 
    std::cout << "Palabra reservada: " << yytext << std::endl; 
}

{hexadecimal} { 
    std::cout << "Hexadecimal: " << yytext << std::endl; 
}

{identificador} { 
    std::cout << "Identificador: " << yytext << std::endl; 
}

. { 
    /* El punto hace match con cualquier caracter no reconocido por las reglas de arriba */
    std::cout << "Caracter no reconocido: " << yytext << std::endl; 
}

%%

int main() {
  FlexLexer* lexer = new yyFlexLexer;
  lexer->yylex();
  return 0;
}