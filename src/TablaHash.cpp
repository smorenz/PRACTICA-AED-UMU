#include "TablaHash.h"
#include <cmath>
#include <string>

#define TAM_TABLA_DEF 5000

using namespace std;

// Función de dispersión
int TablaHash::hash(string &palabra, int indice) {
    unsigned int h = 0;
    int i = (int)exp2(indice) % B - 1;

    for (char car : palabra)
        h = (h * 256 + car) % B;

    return (int)((h + i) % B);
}

int TablaHash::buscar(string palabra) {
    int i = 1;
    int h = hash(palabra, i);

    while (i < B && !tabla[(h + i) % B].empty() && tabla[(h + i) % B] != palabra) {
        h = hash(palabra, i);
        i++;
    }

    return h;
}

TablaHash::TablaHash(int entradas) {
    B = entradas;
    nElem = 0;
    tabla = new string[B];
}

TablaHash::TablaHash() {
    B = TAM_TABLA_DEF;
    nElem = 0;
    tabla = new string[TAM_TABLA_DEF];
}

TablaHash::~TablaHash() {
    delete[] tabla;
}

void TablaHash::insertar(string palabra) {
    int h = buscar(palabra);

    if (tabla[h].empty()) {
        tabla[h] = palabra;
        nElem++;
    }

    // Restructuración de la tabla
    if (nElem > B / 2) {
        int antiguoB = B;
        B = B * 2;
        string *tablaAux = new string[B];
        for (int i = 0; i < antiguoB; i++) {
            if (!tabla[i].empty()) {
          int h = buscar(tabla[i]);
              // ¿Tiene sentido la comprobación?
          if (h != -1 && h < B)
                    tablaAux[h] = tabla[i];
            }
        }
        delete[] tabla;
        tabla = tablaAux;
    }
}

void TablaHash::vaciar(void) {
    for (int i = 0; i < B; i++)
        tabla[i].clear();
    nElem = 0;
}

bool TablaHash::consultar(string palabra) {
    int h = buscar(palabra);

    if (tabla[h] == palabra && h != -1)
        return true;

    return false;
}
