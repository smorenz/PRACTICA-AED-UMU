#ifndef _AVL_HPP
#define _AVL_HPP

#include <iostream>

using namespace std;

class AVL
{
private:
    // Atributos
    class Nodo
    {
    public:
        string clave;
        int alt;
        Nodo *izq, *der;

        Nodo(string clave);
        ~Nodo();
    };
    Nodo *raiz;
    int numElem;

    // Funciones auxiliares

    // Altura de un árbol
    void insertarAux(Nodo *&raiz, string clave);
    bool consultarAux(Nodo * raiz, string clave);
    int altura(Nodo *objetivo);
    void RSD(Nodo *&objetivo);
    void RSI(Nodo *&objetivo);
    void RDD(Nodo *&A)
    {
        RSI(A->der);
        RSD(A);
    };
    void RDI(Nodo *&A)
    {
        RSD(A->izq);
        RSI(A);
    };

public:
    // Constructor por defecto -> árbol vacío
    AVL();
    ~AVL();
    bool consultar(string palabra) { return this->consultarAux(this->raiz, palabra); }
    void vaciar();
    void insertar(string palabra) { this->insertarAux(this->raiz, palabra); }
    int nElem() { return this->numElem; } 
};

#endif // _AVL_HPP
