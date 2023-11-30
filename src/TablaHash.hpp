#ifndef TABLA_HASH_HPP
#define TABLA_HASH_HPP

#define TAM_TABLA_DEF 1000000

#include <iostream>

using namespace std;

class TablaHash
{
private:
    //
    int B;     // tamaño de la lista
    int nElem; // Elementos en lista
    string *tabla;

    int buscar(string palabra);
    int hash(string &palabra, int indice);
    void reestructurar(void);

public:
    TablaHash(int elementos = TAM_TABLA_DEF);
    ~TablaHash();
    void insertar(string palabra);
    void vaciar(void);
    bool consultar(string palabra);
    int numElem(void) { return nElem; }
};

#endif // TABLA_HASH