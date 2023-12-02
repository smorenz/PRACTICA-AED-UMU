#include "AVL.hpp"
#include <cmath>
#include <algorithm>

// Implementaciones para nodos

AVL::Nodo::Nodo(string clave)
{
    this->clave = clave;
    izq = NULL;
    der = NULL;
    alt = 0;
}

AVL::Nodo::~Nodo()
{
    delete izq;
    delete der;
}

// Implementaciones para árboles

AVL::AVL()
{
    raiz = NULL;
    numElem = 0;
}

AVL::~AVL()
{
    delete raiz;
}

int AVL::altura(Nodo *objetivo)
{
    if (objetivo == NULL)
        return -1;
    return objetivo->alt;
}

void AVL::vaciar()
{
    delete this->raiz->der;
    delete this->raiz->izq;
    delete this->raiz;
    numElem = 0;
}

void AVL::RSD(Nodo *&A)
{
    Nodo *B = A->der;
    A->der = B->izq;
    B->izq = A;
    A->alt = 1 + max(altura(A->izq), altura(A->der));
    B->alt = 1 + max(altura(A), altura(B->der));
    A = B;
}

void AVL::RSI(Nodo *&A)
{
    Nodo *B = A->izq;
    A->izq = B->der;
    B->der = A;
    A->alt = 1 + max(altura(A->izq), altura(A->der));
    B->alt = 1 + max(altura(A), altura(B->izq));
    A = B;
}

void AVL::insertarAux(Nodo *&A, string clave)
{
    if (A == NULL)
    {
        A = new Nodo(clave);
        numElem++;
    }
    else
    {
        if (clave < A->clave) // Inserción en subárbol izquierdo
        {
            insertarAux(A->izq, clave);
            if (altura(A->izq) - altura(A->der) > 1)
            {
                if (A->izq != NULL && clave < A->izq->clave)
                    RSI(A);
                else
                    RDI(A);
            }
            A->alt = 1 + max(altura(A->izq), altura(A->der));
        }
        else if (clave > A->clave) // Inserción en subárbol derecho (simétrico a caso anterior)
        {
            insertarAux(A->der, clave);
            if (altura(A->der) - altura(A->izq) > 1)
            {
                if (A->der != NULL && clave > A->der->clave)
                    RSD(A);
                else
                    RDD(A);
            }
            A->alt = 1 + max(altura(A->izq), altura(A->der));
        }
    }
}

bool AVL::consultarAux(Nodo *A, string clave)
{
    if (A != NULL)
    {
        if (A->clave == clave)
            return true;
        else if (clave < A->clave)
            return consultarAux(A->izq, clave);
        else if (clave > A->clave)
            return consultarAux(A->der, clave);
        else
            return false;
    }
    return false;
}