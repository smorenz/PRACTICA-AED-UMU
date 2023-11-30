#include "TablaHash.hpp"
#include <cmath>
#include <assert.h>

using namespace std;

// Función de dispersión
int TablaHash::hash(string &palabra, int indice)
{
    unsigned int h = 0;
    int i = (int)exp2(indice) % B - 1;

    for (char car : palabra)
    {
        h = (h * 256 + car) % B;
    }

    return (h + i) % B;
}

int TablaHash::buscar(string palabra)
{
    int i = 1;
    int h = hash(palabra, i);

    while (i < B && !tabla[h].empty() && tabla[h] != palabra)
    {
        i++;
        h = hash(palabra, i);
    }

    return h;
}

TablaHash::TablaHash(int entradas)
{
    B = entradas;
    nElem = 0;
    tabla = new string[B];
}

TablaHash::~TablaHash()
{
    delete[] tabla;
}

// Parece no funcionar correctamente (Segmentation fault)
// Solución temporal -> aumentar tamaño de la tabla
void TablaHash::reestructurar(void)
{
    {
        int antiguoB = B;
        B = B * 2;
        string *tablaAux = new string[B];
        for (int i = 0; i < antiguoB; i++)
        {
            if (!tabla[i].empty())
            {
                int h = buscar(tabla[i]);
                tablaAux[h] = tabla[i];
            }
        }
        delete[] tabla;
        tabla = tablaAux;
    }
}

void TablaHash::insertar(string palabra)
{
    int h = buscar(palabra);

    if (tabla[h].empty())
    {
        tabla[h] = palabra;
        nElem++;
    }

    if (nElem > B / 2)
        reestructurar();
}

void TablaHash::vaciar(void)
{
    for (int i = 0; i < B; i++)
        tabla[i] = "";
    nElem = 0;
}

bool TablaHash::consultar(string palabra)
{
    int h = buscar(palabra);

    if (tabla[h] == palabra && h < B)
        return true;

    return false;
}
