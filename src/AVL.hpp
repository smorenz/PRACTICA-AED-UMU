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
        int altura;
        AVL *izq, *der;

        Nodo(string clave);
        ~Nodo();
        int checkAltura(Nodo objetivo);
    };
    Nodo *raiz;
    int numElem;

    // Funciones auxiliares
    void RSD(AVL *objetivo);
    void RSI(AVL *objetivo);
    void RDD(AVL *objetivo)
    {
        RSI(objetivo->raiz->der);
        RSD(objetivo);
    };
    void RDI(AVL *objetivo)
    {
        RSD(objetivo->raiz->izq);
        RSI(objetivo);
    };

public:
    AVL(Nodo *raiz);
    ~AVL();
    void insertar(string clave);
    int nElem() { return numElem; }
    bool consultar(string palabra);
    void vaciar();
};

#endif // _AVL_HPP
