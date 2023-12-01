#include "AVL.hpp"
#include <cmath>

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

AVL::AVL(Nodo *raiz)
{
    this->raiz = raiz;
}

AVL::~AVL()
{
    delete raiz;
}

int AVL::nElem()
{
    if (raiz == NULL)
        return 0;
    return 1 + raiz->izq->nElem() + raiz->der->nElem();
}

int AVL::altura(AVL *objetivo)
{
    if (objetivo == NULL || objetivo->raiz == NULL)
        return -1;
    return objetivo->raiz->alt;
}

void AVL::vaciar()
{
    delete raiz->izq;
    delete raiz->der;

    // Reinicialización de la raíz de manera explícita (Por si acaso)
    raiz->clave = "";
    raiz->izq = NULL;
    raiz->der = NULL;
    raiz->alt = 0;
}

void AVL::RSD(AVL *objetivo)
{
    AVL *B = objetivo->raiz->der;
    objetivo->raiz->der = B->raiz->izq;
    B->raiz->izq->raiz = objetivo->raiz;
    objetivo->raiz->alt = 1 + max(altura(objetivo->raiz->izq), altura(objetivo->raiz->der));
    B->raiz->alt = 1 + max(objetivo->raiz->alt, altura(B->raiz->der));
    objetivo->raiz = B->raiz;
}

void AVL::RSI(AVL *objetivo)
{
    AVL *B = objetivo->raiz->izq;
    objetivo->raiz->izq = B->raiz->der;
    B->raiz->der->raiz = objetivo->raiz;
    objetivo->raiz->alt = 1 + max(altura(objetivo->raiz->izq), altura(objetivo->raiz->der));
    B->raiz->alt = 1 + max(objetivo->raiz->alt, altura(B->raiz->izq));
    objetivo->raiz = B->raiz;
}

void AVL::reestructurar(AVL *objetivo, string clave)
{
    if (clave < objetivo->raiz->clave) // Inserción en el subárbol izquierdo
    {
        objetivo->raiz->izq->insertar(clave);
        if (altura(objetivo->raiz->izq) - altura(objetivo->raiz->der) > 1)
        {
            if (clave < objetivo->raiz->izq->raiz->clave)
                RSI(this);
            else
                RDI(this);
        }
        else
            objetivo->raiz->alt = 1 + max(altura(objetivo->raiz->izq), altura(objetivo->raiz->der));
    }
    else if (clave > objetivo->raiz->clave) // Inserción en el subárbol derecho (simetrico al anterior)
    {
        objetivo->raiz->der->insertar(clave);
        if (altura(objetivo->raiz->der) - altura(objetivo->raiz->izq) > 1)
        {
            if (clave > objetivo->raiz->der->raiz->clave)
                RSD(this);
            else
                RDD(this);
        }
        else
            objetivo->raiz->alt = 1 + max(altura(objetivo->raiz->izq), altura(objetivo->raiz->der));
    }
}

void AVL::insertar(string clave)
{
    // Caso árbol vacío -> fin recursividad
    if (raiz == NULL)
    {
        raiz = new Nodo(clave);
        raiz->izq = NULL;
        raiz->der = NULL;
        raiz->alt = 0;
    }
    else if (clave == raiz->clave)
        return;
    else
        reestructurar(this, clave);
}

bool AVL::consultar(string clave)
{
    if (raiz != NULL) // Caso árbol vacío
    {
        if (clave == raiz->clave)
            return true;
        if (clave < raiz->clave)
            return raiz->izq->consultar(clave);
        if (clave > raiz->clave)
            return raiz->der->consultar(clave);
    }
    return false;
}
