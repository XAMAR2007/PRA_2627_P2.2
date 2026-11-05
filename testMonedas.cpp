#include <iostream>
#include <vector>
#include "Monedas.h"

int main() {
    std::vector<int> v = {1, 4, 6};
    int m = 8;
    std::vector<int> sol;

    int num_monedas = cambio(v, m, sol);

    std::cout << "Monedas disponibles: ";
    for (int coin : v) {
        std::cout << coin << " ";
    }
    std::cout << "\nCantidad a devolver: " << m << std::endl;
    std::cout << "Minimo de monedas devueltas: " << num_monedas << std::endl;

    std::cout << "Desglose del cambio:" << std::endl;
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << "  - " << sol[i] << " moneda(s) de valor " << v[i] << std::endl;
    }

    return 0;
}
