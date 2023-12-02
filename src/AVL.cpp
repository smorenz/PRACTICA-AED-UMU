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
    // Gestionado por destructor de AVL (Se presupone que los Nodos son solo elementos de un AVL, no se usan por separado)
}

// Implementaciones para árboles

AVL::AVL()
{
    raiz = NULL;
    numElem = 0;
}

AVL::~AVL()
{
    vaciar();
}

int AVL::altura(Nodo *objetivo)
{
    if (objetivo == NULL)
        return -1;
    return objetivo->alt;
}

void AVL::vaciar()
{
    if (raiz != NULL)
    {
        if (raiz->der != NULL)
            delete this->raiz->der;
        if (raiz->izq != NULL)
            delete this->raiz->izq;

        delete this->raiz;
        raiz = NULL;
    }

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

int AVL::getTamPalabra(string palabra) {
    int tam = 0;
    for (int i = 0; i < palabra.size(); i++) {
        if (palabra[i] != ' ')
            tam += (int) palabra[i];
        else if (palabra[i] == (char)0xC3)
        {
            switch (palabra[i+1])
            {
            case (char)0x91: // Ñ
                tam += 165;
                ++i;
                break;
            case (char)0x9C: // Ü
                tam += 154;
                ++i;
                break;
            }
        }
    }
    return tam;
}

string AVL::alargaPalabrasAux(Nodo* nodo, string prefijo) {
    if (nodo == NULL)
        return "";

    string palabraIzq = alargaPalabrasAux(nodo->izq, prefijo);
    string palabraDer = alargaPalabrasAux(nodo->der, prefijo);
    string palabraActual = "";

    // substr sirve para obtener de un conjunto de caracteres (string en c++) un subconjunto de este
    // el cual va de una posición inicial (en este caso la posición 0, el inicio de la palabra) hasta
    // una posición final indicada en la cantidad de caracteres que se quieren obtener (en este caso
    // la longitud del prefijo) -> EJ: "hola".substr(0, 2) -> "ho"
    if (nodo->clave.substr(0, prefijo.size()) == prefijo)
        palabraActual = nodo->clave;

    if (palabraActual.size() > palabraIzq.size() && palabraActual.size() > palabraDer.size())
        return palabraActual;
    else if (palabraIzq.size() > palabraActual.size() && palabraIzq.size() > palabraDer.size())
        return palabraIzq;
    else if (palabraDer.size() > palabraActual.size() && palabraDer.size() > palabraIzq.size())
        return palabraDer;
    else
        return palabraActual;
}