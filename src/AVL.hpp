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
        AVL *izq, *der;

        Nodo(string clave);
        ~Nodo();
    };
    Nodo *raiz;

    // Funciones auxiliares
    int altura(AVL *objetivo);
    void equilibrar(AVL *objetivo, string clave);
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
    // Constructor por defecto -> árbol vacío
    AVL(Nodo *raiz = NULL);
    ~AVL();
    int nElem();
    void insertar(string clave);
    bool consultar(string palabra);
    void vaciar();
};

#endif // _AVL_HPP
