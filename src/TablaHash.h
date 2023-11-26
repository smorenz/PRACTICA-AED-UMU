#ifndef _TABLA_HASH
#define _TABLA_HASH

#include <iostream>
#include <list>
using namespace std;

class TablaHash {
private:
  string *T;
  int B; // tamaño de la lista
  int nElem; // Elementos en lista
public:
  TablaHash(int entradas);
  ~TablaHash();
  void insertar(string palabra);
  void vaciar(void);
  bool consultar(string palabra); 
  int numElem(void) { return nElem; }
};

#endif // ! _TABLA_HASH
