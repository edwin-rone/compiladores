#include <iostream>

int main() {
    
    int var = 7;      /* declaración de variable */
    int *ap;          /* declaración de variable apuntador */
    
    ap = &var;        /*asignación de dirección de memoria de var en apuntador */
    
    std::cout << "Dirección de memoria de la variable var: " << &var << std::endl;
    
    /* Valor de la variable apuntador */
    std::cout << "Valor de la variable apuntador ap: " << ap << std::endl;
    
    /* Acceso al valor de la dirección de memoria alojada en el apuntador */
    std::cout << "Valor de *ap: " << *ap << std::endl;
    
    /* Acceso al valor de la variable var*/
    std::cout << "Valor de var: " << var << std::endl;
    
    return 0;
}