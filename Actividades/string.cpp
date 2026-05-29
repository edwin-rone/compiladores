#include <iostream>
#include <string>

int main() {
    char arreglo[10] = {'t', 'a', 'n', 'g', 'a', 'n', 'a', 'n', 'a', '\0'};
    char cadena[] = "tanganana";
    std::string nuevo = "tanganana";

    std::cout << arreglo << std::endl;
    std::cout << cadena << std::endl;
    std::cout << nuevo << std::endl;

    return 0;
}