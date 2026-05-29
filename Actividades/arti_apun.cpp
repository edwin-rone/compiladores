#include <iostream>

int main() {
    int arr[] = {6, 42, 919};
    int *ptr;
    ptr = arr;
    
    std::cout << *ptr << std::endl;   // Línea 8
    ptr += 1;
    std::cout << *ptr << std::endl;   // Línea 10
    std::cout << *++ptr << std::endl; // Línea 11
    std::cout << *ptr-- << std::endl; // Línea 12
    ptr += 1;
    std::cout << *ptr << std::endl;   // Línea 14
    
    return 0;
}