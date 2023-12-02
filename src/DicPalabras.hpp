#ifndef DIC_PALABRAS_HPP
#define DIC_PALABRAS_HPP

#include "TablaHash.hpp"
#include "AVL.hpp"

using namespace std;

class DicPalabras
{
private:
    TablaHash tabla;
    AVL arbol;
public:
    void vaciar();
    void insertar(string palabra);
    bool consultar(string palabra);
    int numElem();
    string alarga(string prefijo);
};

#endif // DIC_PALABRAS