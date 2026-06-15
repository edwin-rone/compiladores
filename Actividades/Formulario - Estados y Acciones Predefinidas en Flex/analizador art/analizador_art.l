%{
#include <stdio.h>
#include <string.h>
/* Habilitamos el conteo de líneas para los errores */
%}

%option yylineno
%option noyywrap

/* Estado exclusivo para comentarios multilínea */
%x COMENTARIO_MULTILINEA

%%

 /* e. Palabras reservadas (Van primero para no confundirse con Identificadores) */
"if"|"then"|"else"|"while"|"do"|"case"|"is"|"void"|"true"|"false"|"begin"|"end"|"not" { 
    fprintf(yyout, "<Palabra Reservada, %s>\n", yytext); 
}

 /* a. Números enteros */
[0-9]+ { 
    fprintf(yyout, "<Numero Entero, %s>\n", yytext); 
}

 /* b. Números reales */
[0-9]+\.[0-9]+ { 
    fprintf(yyout, "<Numero Real, %s>\n", yytext); 
}

 /* c. Identificadores estilo C */
[a-zA-Z_][a-zA-Z0-9_]* { 
    fprintf(yyout, "<Identificador, %s>\n", yytext); 
}

 /* d. Cadenas de caracteres ("...") */
\"[^\"\n]*\" { 
    fprintf(yyout, "<Cadena, %s>\n", yytext); 
}

 /* g. Comentarios de una sola línea */
"--".* { 
    fprintf(yyout, "<Comentario Una Linea, %s>\n", yytext); 
}

 /* h. Comentarios multilínea (<* ... *>) */
"<*"                        { BEGIN(COMENTARIO_MULTILINEA); }
<COMENTARIO_MULTILINEA>"*>" { BEGIN(INITIAL); fprintf(yyout, "<Comentario Multilinea, ...>\n"); }
<COMENTARIO_MULTILINEA>.|\n { /* Ignorar el contenido dentro del comentario */ }

 /* i. Operadores aritméticos */
[\+\-\*/%] { 
    fprintf(yyout, "<Operador Aritmetico, %s>\n", yytext); 
}

 /* j. Operadores relacionales */
">"|"<"|"<>"|"=" { 
    fprintf(yyout, "<Operador Relacional, %s>\n", yytext); 
}

 /* k. Operador de asignación */
":=" { 
    fprintf(yyout, "<Asignacion, %s>\n", yytext); 
}

 /* l. Símbolos especiales */
[\(\)\{\}\;\,\.] { 
    fprintf(yyout, "<Simbolo Especial, %s>\n", yytext); 
}

 /* f. Espacios en blanco (Ignorarlos) */
[ \t\n\r]+ { /* No hacer nada */ }

 /* m. Errores léxicos (Cualquier cosa que no haya hecho match) */
. { 
    fprintf(yyout, "ERROR LEXICO: Caracter no reconocido '%s' en la linea %d\n", yytext, yylineno); 
}

%%

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Uso: %s archivo.art\n", argv[0]);
        return 1;
    }

    /* Validar extensión .art */
    char *ext = strrchr(argv[1], '.');
    if (!ext || strcmp(ext, ".art") != 0) {
        printf("Error: El archivo debe tener la extension .art\n");
        return 1;
    }

    /* Crear nombre del archivo de salida reemplazando .art por .tokens */
    char archivo_salida[256];
    strncpy(archivo_salida, argv[1], ext - argv[1]);
    archivo_salida[ext - argv[1]] = '\0';
    strcat(archivo_salida, ".tokens");

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        printf("Error al abrir %s\n", argv[1]);
        return 1;
    }

    yyout = fopen(archivo_salida, "w");
    if (!yyout) {
        printf("Error al crear %s\n", archivo_salida);
        return 1;
    }

    yylex();

    fclose(yyin);
    fclose(yyout);
    printf("Analisis terminado. Resultados en: %s\n", archivo_salida);

    return 0;
}