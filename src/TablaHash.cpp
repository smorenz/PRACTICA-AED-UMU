#include "TablaHash.h"

#define TAM_TABLA_DEF 100

using namespace std;

// Función de dispersión test [TODO - implementar nueva]
int TablaHash::hash(string palabra) {
  unsigned int h = 0;
  for (int i = 0; i < palabra.length(); i++) {
    h = (h * 256 + palabra[i]) % B;
  }
  return h;
}

int TablaHash::buscar(string palabra) {
  int i = 1;
  int h = hash(palabra);
  // TODO - cambiar redistribución lineal
  while (i < B && !tabla[(h + i) % B].empty() && tabla[(h + i) % B] != palabra)
    i++;

  return h;
}

TablaHash::TablaHash(int entradas) {
  B = entradas;
  nElem = 0;
  tabla = new string[B];
}

TablaHash::TablaHash() {
  B = TAM_TABLA_DEF;
  nElem = 0;
  tabla = new string[TAM_TABLA_DEF];
}

TablaHash::~TablaHash() {
  delete[] tabla;
}

void TablaHash::insertar(string palabra) {
  int h = buscar(palabra);
  if (tabla[h].empty()) {
    tabla[h] = palabra;
    nElem++;
  }
  cerr << "Error, la tabla está llena" << endl;
}

void TablaHash::vaciar(void) {
  for (int i = 0; i < B; i++) {
    tabla[i].clear();
  }
  nElem = 0;
}

bool TablaHash::consultar(string palabra) {
  int h = buscar(palabra);

  if (tabla[h] == palabra)
    return true;

  return false;
}
