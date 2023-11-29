#include "DicPalabras.hpp"
#include "TablaHash.hpp"

using namespace std;

DicPalabras::DicPalabras(void) {
    tabla = TablaHash();
}

void DicPalabras::vaciar() {
    tabla.vaciar();
}

void DicPalabras::insertar(string palabra) {
    tabla.insertar(palabra);
}

bool DicPalabras::consultar(string palabra) {
    return tabla.consultar(palabra);
}

int DicPalabras::numElem() {
    return tabla.numElem();
}