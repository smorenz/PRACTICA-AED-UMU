#include "TablaHash.h"
using namespace std;

int TablaHash::hash(string palabra) {
    int h = 0;
    for (int i = 0; i < palabra.length(); i++) {
        h = (h * 256 + palabra[i]) % B;
    }
    return h;
}

TablaHash::TablaHash(int entradas) {
    B = entradas;
    nElem = 0;
    tabla = new string[B];
}

TablaHash::~TablaHash() {
    delete[] tabla;
}

void TablaHash::insertar(string palabra) {
    int h = hash(palabra);
    if (tabla[h].empty()) {
        tabla[h] = palabra;
        nElem++;
    } else {
        if (tabla[h] != palabra) {
            int i = 1;
            while (i < B && !tabla[(h + i) % B].empty() && tabla[(h + i) % B] != palabra)
                i++;

            if (tabla[(h + i) % B].empty() && tabla[(h + i) % B] != palabra) {
                tabla[(h + i) % B] = palabra;
                nElem++;
            }
        }
    }
}

void TablaHash::vaciar(void) {
    for (int i = 0; i < B; i++) {
        tabla[i].clear();
    }
    nElem = 0;
}

bool TablaHash::consultar(string palabra) {
    int h = hash(palabra);
    if (tabla[h].empty())
        return false;

    if (tabla[h] == palabra)
        return true;

    // Redispersión
    int i = 1; // Secuencia de búsqueda
    while (i < B && !tabla[(h + i) % B].empty() && tabla[(h + i) % B] != palabra)
        i++;

    if (tabla[(h + i) % B].empty())
        return false;

    return true;
}



