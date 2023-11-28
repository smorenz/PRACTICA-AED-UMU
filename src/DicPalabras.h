#ifndef DIC_PALABRAS
#define DIC_PALABRAS

#include "TablaHash.h"

using namespace std;

class DicPalabras {
private:
    TablaHash tabla;
public:
    DicPalabras(void);

    void vaciar();

    void insertar(string palabra);

    bool consultar(string palabra);

    int numElem();
};

#endif // DIC_PALABRAS
