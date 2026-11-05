#ifndef DYV_H
#define DYV_H

#include <vector>
#include <iostream>

// --- BÚSQUEDA BINARIA ---
template <typename T>
int BusquedaBinaria(T x, const std::vector<T>& v, int ini, int fin) {
    if (ini > fin) {
        return -1; // No se encuentra en el vector
    }
    int medio = (ini + fin) / 2;
    if (v[medio] == x) {
        return medio;
    } else if (v[medio] > x) {
        return BusquedaBinaria(x, v, ini, medio - 1);
    } else {
        return BusquedaBinaria(x, v, medio + 1, fin);
    }
}

// --- QUICKSORT ---
template <typename T>
int Partition(std::vector<T>& v, int ini, int fin) {
    T x = v[fin];
    int i = ini;
    for (int j = ini; j < fin; j++) {
        if (v[j] <= x) {
            std::swap(v[i], v[j]);
            i++;
        }
    }
    std::swap(v[i], v[fin]);
    return i;
}

template <typename T>
void QuickSort(std::vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int pivot = Partition(v, ini, fin);
        QuickSort(v, ini, pivot - 1);
        QuickSort(v, pivot + 1, fin);
    }
}

#endif // DYV_H
