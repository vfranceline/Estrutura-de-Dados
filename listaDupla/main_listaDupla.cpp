// main.cpp
#include <iostream>
#include "listaDupla.h"

int main() {
    listaDupla L;

    // 1) isEmpty / isFull
    std::cout << "isEmpty(): " << (L.isEmpty() ? "true" : "false") << std::endl;
    std::cout << "isFull():  " << (L.isFull()  ? "true" : "false") << std::endl;

    // 2) Inserções
    int valores[] = {5, 2, 9, 4, 7};
    for (int v : valores) {
        std::cout << "push(" << v << ")\n";
        L.push(v);
    }

    // 3) Impressões
    std::cout << "\nLista crescente:   ";  L.printCrescente();
    std::cout << "Lista decrescente: ";  L.printDecrescente();
    std::cout << "Sublista pares:    ";  L.printPares();
    std::cout << "Sublista ímpares:  ";  L.printImpares();

    // 4) Remoções
    std::cout << "\npop(9)\n";  L.pop(9);
    std::cout << "Após pop(9):       ";  L.printCrescente();

    std::cout << "pop(2)\n";  L.pop(2);
    std::cout << "Após pop(2):       ";  L.printCrescente();
    std::cout << "Sublista pares:    ";  L.printPares();
    std::cout << "Sublista ímpares:  ";  L.printImpares();

    std::cout << "pop(7)\n";  L.pop(7);
    std::cout << "Após pop(7):       ";  L.printCrescente();
    std::cout << "Sublista pares:    ";  L.printPares();
    std::cout << "Sublista ímpares:  ";  L.printImpares();

    // 5) Estado final
    std::cout << "\nisEmpty(): " << (L.isEmpty() ? "true" : "false") << std::endl;

    return 0;
}
