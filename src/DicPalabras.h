#ifndef DIC_PALABRAS
#define DIC_PALABRAS

#include "TablaHash.h"

using namespace std;

class DicPalabras {
private:
    TablaHash tabla;
    int contador;
public:
    DicPalabras(void);

    void vaciar();

    void insertar(string palabra);

    bool consultar(string palabra);

    int numElem() { return contador; }
};

#endif // DIC_PALABRAS
