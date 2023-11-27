#include "DicPalabras.h"
#include "TablaHash.h"

using namespace std;

DicPalabras::DicPalabras(void) {
  tabla = TablaHash();
  contador = 0;
}

void DicPalabras::vaciar() {
  tabla.vaciar();
  contador = 0;
}

void DicPalabras::insertar(string palabra) {
  tabla.insertar(palabra);
  contador++;
}

bool DicPalabras::consultar(string palabra) {
  return tabla.consultar(palabra);
}
