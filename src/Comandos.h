#ifndef _COMANDOS
#define _COMANDOS

#include "DicPalabras.h"
using namespace std;

// Intérprete de comandos

int evaluarComando(string &comando);
string normalizar(string &cadena);
void interprete(string &comando);

// Comandos con funciones

void INSERTAR();
void VACIAR();
void BUSCAR();
void EXIT();
void PARTIDAS();
void ALOCADO();
void CESAR();
void JUANAGRAMA();
void SACO();
void CONSOME();
void ALARGA();

#endif // !_COMANDOS
