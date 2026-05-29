#include <stdio.h>

// 1. Primera directiva: #ifndef (If Not Defined)
#ifndef ARCH_RP2040
#define ARCH_RP2040 1
#endif

// 2. Segunda directiva: #warning
#warning "Atencion: Compilando firmware con configuraciones por defecto."

// Definimos una macro temporal
#define MODO_PRUEBA 1

// 3. Tercera directiva: #undef (Undefine)
#undef MODO_PRUEBA

// 4. Cuarta directiva: #error
#ifdef MODO_PRUEBA
#error "Peligro: El modo de prueba sigue activo. Deteniendo compilacion."
#endif

int main(void) {
    printf("Iniciando sistema...\n");
    printf("Arquitectura configurada (1=RP2040, 0=Otra): %d\n", ARCH_RP2040);
    return 0;
}