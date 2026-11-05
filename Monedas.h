#ifndef MONEDAS_H
#define MONEDAS_H

#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>

inline int cambio(const std::vector<int>& v, int m, std::vector<int>& sol) {
    int n = v.size();
    int inf = std::numeric_limits<int>::max();
    
    // Tabla n x (m + 1) inicializada a inf
    std::vector<std::vector<int>> t(n, std::vector<int>(m + 1, inf));
    
    for (int i = 0; i < n; i++) {
        t[i][0] = 0;
    }
    
    // Primera fila
    for (int j = 1; j <= m; j++) {
        if (j >= v[0] && t[0][j - v[0]] != inf) {
            t[0][j] = 1 + t[0][j - v[0]];
        }
    }
    
    // Resto de filas
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j < v[i] || t[i][j - v[i]] == inf) {
                t[i][j] = t[i - 1][j];
            } else if (t[i - 1][j] != inf) {
                t[i][j] = std::min(t[i - 1][j], 1 + t[i][j - v[i]]);
            } else {
                t[i][j] = 1 + t[i][j - v[i]];
            }
        }
    }
    
    // Recuperar la solución elegida
    sol.assign(n, 0);
    int i = n - 1;
    int j = m;
    while (i >= 0 && j > 0) {
        if (i == 0) {
            sol[i] += j / v[0];
            break;
        } else if (t[i][j] != t[i - 1][j]) {
            sol[i]++;
            j -= v[i];
        } else {
            i--;
        }
    }
    
    return t[n - 1][m];
}

#endif // MONEDAS_H
