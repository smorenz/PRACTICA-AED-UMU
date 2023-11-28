#include "TablaHash.h"

#define TAM_TABLA_DEF 100

using namespace std;

// Función de dispersión test TODO - implementar nueva
int TablaHash::hash(string palabra) {
    unsigned int h = 0;
    for (int i = 0; i < palabra.length(); i++)
        h = (h * 256 + palabra[i]) % B;

    return h;
}

int TablaHash::buscar(string palabra) {
    int i = 1;
    int h = hash(palabra);

    while (i < B && !tabla[(h + i) % B].empty() && tabla[(h + i) % B] != palabra)
        i++;

    // Caso tabla llena
    if (i == B || !tabla[(h + i) % B].empty())
        return -1;

    return (h + i) % B;
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

    if (h != -1) {
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
                if (h != -1)
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
