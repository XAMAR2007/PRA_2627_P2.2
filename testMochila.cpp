#include <iostream>
#include <vector>
#include "Mochila.h"

int main() {
    std::vector<int> p = {9, 6, 5};
    std::vector<int> b = {38, 40, 24};
    int m = 15;
    std::vector<int> sol;

    int beneficio_max = mochila(p, b, m, sol);

    std::cout << "Capacidad de la mochila: " << m << std::endl;
    std::cout << "Beneficio maximo obtenido: " << beneficio_max << std::endl;

    std::cout << "Elementos seleccionados (1 = elegido, 0 = no elegido):" << std::endl;
    for (size_t i = 0; i < p.size(); i++) {
        std::cout << "  - Elemento " << i + 1 << " (Peso: " << p[i] 
                  << ", Beneficio: " << b[i] << ") -> " << sol[i] << std::endl;
    }

    return 0;
}
