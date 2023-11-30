#include "AVL.hpp"

// Implementaciones para nodos

AVL::Nodo::Nodo(string clave)
{
    this->clave = clave;
    izq = NULL;
    der = NULL;
    altura = 0;
}

AVL::Nodo::~Nodo()
{
    delete izq;
    delete der;
}


// Implementaciones para árboles


AVL::AVL(Nodo *raiz)
{
    this->raiz = raiz;
    numElem = 0;
}

AVL::~AVL()
{
    delete raiz;
}

int AVL::altura()
{
    if (this == NULL)
        return -1;
    else
        return raiz->altura;
}

void AVL::vaciar()
{
    delete raiz->izq;
    delete raiz->der;
}

void AVL::insertar(string clave)
{
    // Caso árbol vacío
    if (raiz == NULL)
    {
        raiz = new Nodo(clave);
        raiz->izq = NULL;
        raiz->der = NULL;
        raiz->altura = 0;
    }

    
}
