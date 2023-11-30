#include "AVL.hpp"

AVL::Nodo::Nodo(string clave) {
    this->clave = clave;
    izq = NULL;
    der = NULL;
    altura = 0;
}

AVL::Nodo::~Nodo() {
    delete izq;
    delete der;
}
