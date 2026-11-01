# Compilador — C++, Flex y Bison

Construcción incremental de las fases de análisis de un compilador, desde el analizador léxico hasta el análisis semántico de declaraciones. Prácticas de laboratorio del curso de Compiladores (Facultad de Ciencias, UNAM, 2026-2).

## Tecnologías

- C++
- Flex (analizador léxico)
- Bison / Yacc (analizador sintáctico)
- Make

## Prácticas

| Práctica | Tema | Qué se implementó |
| --- | --- | --- |
| P0 | Sistema de procesamiento de lenguaje | Análisis del proceso preprocesador → compilador → ensamblador → enlazador |
| P1 | Análisis léxico con Flex | Analizador léxico del lenguaje C_1 |
| P2 | Análisis sintáctico descendente recursivo | Transformación de la gramática (ambigüedad, recursividad izquierda, factorización) y parser recursivo |
| P3 | Análisis sintáctico predictivo LL(1) | Conjuntos FIRST y FOLLOW y tabla de análisis predictivo |
| P4 | Análisis sintáctico con Bison | Gramática LALR(1) integrada con el analizador de Flex |
| P5 | Tabla de tipos y tabla de símbolos | Análisis semántico con esquemas de traducción dirigidos por la sintaxis |

## Destacado: análisis semántico (P5)

- **Tabla de tipos** con tipos primitivos (`int`, `float`), **arreglos** y **registros** (`struct`).
- **Pila de tablas de símbolos** para manejar alcances de funciones y registros.
- Cálculo de **direcciones de memoria** de cada variable.
- Detección de errores como **variables duplicadas**.

## Cómo ejecutarlo

```bash
cd Prácticas/P5/src
make
./comp prueba
```

## Autor

Edwin Rodríguez Nevárez · edrodnev@gmail.com
