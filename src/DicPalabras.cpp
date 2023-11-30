#include "DicPalabras.hpp"
#include "TablaHash.hpp"

using namespace std;


void DicPalabras::vaciar()
{
    arbol.vaciar();
}

void DicPalabras::insertar(string palabra)
{
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