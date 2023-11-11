#include "DicPalabras.h"
using namespace std;

DicPalabras::DicPalabras()
{
  contador = 0;
}

void DicPalabras::vaciar()
{
  contador = 0;
  lista.clear();
}

void DicPalabras::insertar(string palabra)
{
  list<string>::iterator iterador;
  iterador = lista.begin();

  while (iterador != lista.end() && *iterador != palabra)
    iterador++;

  if (*iterador == palabra)
    return;

  contador++;
  lista.insert(iterador, palabra);
}

bool DicPalabras::consultar(string palabra)
{
  list<string>::iterator iterador;
  iterador = lista.begin();

  while (iterador != lista.end() && *iterador != palabra)
    iterador++;

  return iterador != lista.end();
}