#ifndef DIC_PALABRAS_HPP
#define DIC_PALABRAS_HPP

#include "TablaHash.hpp"

using namespace std;

class DicPalabras
{
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