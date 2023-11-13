#include "DicPalabrasLista.h"
using namespace std;

DicPalabrasLista::DicPalabrasLista()
{
  contador = 0;
}

void DicPalabrasLista::vaciar()
{
  contador = 0;
  lista.clear();
}

void DicPalabrasLista::insertar(string palabra)
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

bool DicPalabrasLista::consultar(string palabra)
{
  list<string>::iterator iterador;
  iterador = lista.begin();

  while (iterador != lista.end() && *iterador != palabra)
    iterador++;

  return iterador != lista.end();
}
