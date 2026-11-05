#ifndef MOCHILA_H
#define MOCHILA_H

#include <vector>
#include <algorithm>
#include <iostream>

inline int mochila(const std::vector<int>& p, const std::vector<int>& b, int m, std::vector<int>& sol) {
    int n = p.size();
    
    // Tabla g de dimensiones (n + 1) x (m + 1) inicializada a 0
    std::vector<std::vector<int>> g(n + 1, std::vector<int>(m + 1, 0));
    
    // Construcción iterativa de la tabla mediante programación dinámica
    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= m; c++) {
            if (p[i - 1] > c) {
                g[i][c] = g[i - 1][c];
            } else {
                g[i][c] = std::max(g[i - 1][c], g[i - 1][c - p[i - 1]] + b[i - 1]);
            }
        }
    }
    
    // Reconstrucción de los elementos seleccionados
    sol.assign(n, 0);
    int c = m;
    for (int i = n; i > 0; i--) {
        if (g[i][c] != g[i - 1][c]) {
            sol[i - 1] = 1; // Elemento i-1 seleccionado
            c -= p[i - 1];
        }
    }
    
    return g[n][m]; // Devuelve el beneficio máximo alcanzado
}

#endif // MOCHILA_H
