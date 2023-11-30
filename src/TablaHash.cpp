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

    int resultado = (h + i) % B;

    assert(resultado >= 0 && resultado < B);

    return resultado;
}

int TablaHash::buscar(string palabra)
{
    int i = 1;
    int h = hash(palabra, i);

    assert (h >= 0 && h< B);
    while (i < B && !tabla[h].empty() && tabla[h] != palabra)
    {
        h = hash(palabra, i);
        i++;
        assert(h >= 0 && h < B);
    }

    assert(h < B);

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

void TablaHash::insertar(string palabra)
{
    int h = buscar(palabra);

    if (tabla[h].empty())
    {
        tabla[h] = palabra;
        nElem++;
    }

    // Restructuración de la tabla
    if (nElem > B / 2)
    {
        int antiguoB = B;
        B = B * 2;
        string *tablaAux = new string[B];
        for (int i = 0; i < antiguoB; i++)
        {
            if (!tabla[i].empty())
            {
                int h = buscar(tabla[i]);
                // ¿Tiene sentido la comprobación?
                if (h != -1 && h < B)
                    tablaAux[h] = tabla[i];
            }
        }
        delete[] tabla;
        tabla = tablaAux;
    }
}

void TablaHash::vaciar(void)
{
    for (int i = 0; i < B; i++)
        tabla[i].clear();
    nElem = 0;
}

bool TablaHash::consultar(string palabra)
{
    int h = buscar(palabra);

    if (tabla[h] == palabra && h != -1)
        return true;

    return false;
}
