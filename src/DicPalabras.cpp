#include "DicPalabras.hpp"

using namespace std;


void DicPalabras::vaciar()
{
    tabla.vaciar();
    arbol.vaciar();
}

void DicPalabras::insertar(string palabra)
{
    tabla.insertar(palabra);
    arbol.insertar(palabra);
}

bool DicPalabras::consultar(string palabra)
{
    return arbol.consultar(palabra);
}

int DicPalabras::numElem()
{
    return arbol.nElem();
}

string DicPalabras::alarga(string prefijo)
{
    return arbol.alargaPalabras(prefijo);
}