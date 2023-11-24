#ifndef _DIC_PALABRAS
#define _DIC_PALABRAS

#include <list>
#include <string>
#include <iostream>
using namespace std;

class DicPalabras
{
private:
  TablaHash tabla;
  int contador;

public:
  DicPalabras();
  void vaciar();
  void insertar(string palabra);
  bool consultar(string palabra);
  int numElem()
  {
    return contador;
  }
};

#endif // ! _DIC_PALABRAS
