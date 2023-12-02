#ifndef TABLA_HASH_HPP
#define TABLA_HASH_HPP

#define TAM_TABLA_DEF 200029 

#include <iostream>

using namespace std;

class TablaHash
{
private:
    //
    int B;     // tamaño de la lista
    int numElem; // Elementos en lista
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
    int nElem(void) { return numElem; }
};

#endif // TABLA_HASH