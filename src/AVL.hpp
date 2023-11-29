#ifndef _AVL_HPP
#define _AVL_HPP

#include <iostream>

using namespace std;

class AVL {
private:
    class Nodo {
    public:
        string clave;
        int altura;
        Nodo *izq, *der;

        Nodo(string clave);
        ~Nodo();
    };
    Nodo *raiz;
    int numElem;
public:
    AVL();
    ~AVL();
    void insertar(string clave);
    int nElem() { return numElem; }
    bool consultar(string palabra);
    void vaciar();
};

#endif // _AVL_HPP