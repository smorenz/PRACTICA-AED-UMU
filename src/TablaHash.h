#ifndef _TABLA_HASH
#define _TABLA_HASH

#include <iostream>
using namespace std;

class TablaHash {
private:
  int B; // tamaño de la lista
  int nElem; // Elementos en lista
  string *tabla;
  int hash(string palabra);
public:
  TablaHash(int entradas);
  ~TablaHash();
  void insertar(string palabra);
  void vaciar(void);
  bool consultar(string palabra); 
  int numElem(void) { return nElem; }
};

#endif // ! _TABLA_HASH
