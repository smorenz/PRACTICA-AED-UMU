#ifndef TABLA_HASH
#define TABLA_HASH

#include <iostream>

using namespace std;

class TablaHash {
private:
    int B; // tamaño de la lista
    int nElem; // Elementos en lista
    string *tabla;

    int buscar(string palabra);

    int hash(string palabra, int indice);

public:
    TablaHash(int elementos);

    TablaHash();

    ~TablaHash();

    void insertar(string palabra);

    void vaciar(void);

    bool consultar(string palabra);

    int numElem(void) { return nElem; }
};

#endif // TABLA_HASH
