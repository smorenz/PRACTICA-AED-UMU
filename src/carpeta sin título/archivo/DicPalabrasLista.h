#ifndef _DIC_PALABRAS_LISTA
#define _DIC_PALABRAS_LISTA

#include <list>
#include <string>
#include <iostream>
using namespace std;

class DicPalabrasLista
{
private:
  list<string> lista;
  int contador;

public:
  DicPalabrasLista();
  void vaciar();
  void insertar(string palabra);
  bool consultar(string palabra);
  int numElem()
  {
    return contador;
  }
};

#endif // ! _DIC_PALABRAS_LISTA
