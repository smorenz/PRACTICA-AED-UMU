#include "Comandos.hpp"
#include "DicPalabras.hpp"

using namespace std;

DicPalabras diccionario;

int evaluarComando(string &comando)
{
    if (comando == "<insertar>")
        return 1;
    if (comando == "<vaciar>")
        return 2;
    if (comando == "<buscar>")
        return 3;
    if (comando == "<exit>")
        return 4;
    if (comando == "<partidas>")
        return 5;
    if (comando == "<alocado>")
        return 6;
    if (comando == "<césar>")
        return 7;
    if (comando == "<juanagra>")
        return 8;
    if (comando == "<saco>")
        return 9;
    if (comando == "<consomé>")
        return 10;
    if (comando == "<alarga>")
        return 11;
    return -1;
}

string normalizar(string &cadena)
{
    string aux;
    for (unsigned int i = 0; i < cadena.length(); i++)
    {
        switch (cadena[i])
        {
        case (char)0xC3:
            switch (cadena[i + 1])
            {
            case (char)0xA1: // á
                aux += 'A';
                ++i;
                break;
            case (char)0xA9: // é
                aux += 'E';
                ++i;
                break;
            case (char)0xAD: // í
                aux += 'I';
                ++i;
                break;
            case (char)0xB3: // ó
                aux += 'O';
                ++i;
                break;
            case (char)0xBA: // ú
                aux += 'U';
                ++i;
                break;
            case (char)0x81: // Á
                aux += 'A';
                ++i;
                break;
            case (char)0x89: // É
                aux += 'E';
                ++i;
                break;
            case (char)0x8D: // Í
                aux += 'I';
                ++i;
                break;
            case (char)0x93: // Ó
                aux += 'O';
                ++i;
                break;
            case (char)0x9A: // Ú
                aux += 'U';
                ++i;
                break;
            case (char)0xB1:       // ñ
                aux += (char)0xC3; // Ñ es representada con 2 bytes ⇾ C3 91
                aux += (char)0x91;
                ++i;
                break;
            case (char)0xBC:       // ü
                aux += (char)0xC3; // Ü es representada con 2 bytes ⇾ C3 9C
                aux += (char)0x9C;
                ++i;
                break;
            default:
                aux += (char)0xC3;
                break;
            }
            break;
        default:
            aux += (char)toupper(cadena[i]);
            break;
        }
    }
    return aux;
}

void INSERTAR()
{
    string palabra;
    int contadorLocal = 0;
    while (cin >> palabra)
    {
        if (palabra == "</insertar>")
        {
            cout << "Insertando: " << contadorLocal << " palabras" << endl
                 << "Total diccionario: " << diccionario.numElem()
                 << " palabras" << endl;
            return;
        }
        //cerr << "Voy a: " << normalizar(palabra) << ": "; cerr.flush();
        diccionario.insertar(normalizar(palabra));
        //cerr << "\"" << normalizar(palabra) << "\"" << endl; cerr.flush();
        contadorLocal++;
    }
}

void VACIAR()
{
    diccionario.vaciar();
    cout << "Vaciando" << endl;
    cout << "Total diccionario: " << diccionario.numElem() << " palabras" << endl;
}

void BUSCAR()
{
    string palabra;
    cin >> palabra;
    if (diccionario.consultar(normalizar(palabra)))
        cout << "Buscando: " << normalizar(palabra) << " -> Encontrada" << endl;
    else
        cout << "Buscando: " << normalizar(palabra) << " -> No encontrada" << endl;
}

void EXIT()
{
    cout << "Saliendo..." << endl;
    exit(0);
}

void PARTIDAS()
{
    string palabra;
    string temp;
    while (cin >> palabra)
    {
        if (palabra == "</partidas>")
        {
            cout << "Partidas:" << temp << endl;
            cout << "No implementado" << endl;
            return;
        }
        palabra = normalizar(palabra);
        temp += " ";
        temp += palabra;
    }
}

void ALOCADO()
{
    string palabra;
    cin >> palabra;
    palabra = normalizar(palabra);
    cout << "Alocado: " << palabra << endl;
    cout << "No implementado" << endl;
}

void CESAR()
{
    string palabra;
    cin >> palabra;
    palabra = normalizar(palabra);
    cout << "César: " << palabra << endl;
    cout << "No implementado" << endl;
}

void JUANAGRA()
{
    string palabra;
    cin >> palabra;
    palabra = normalizar(palabra);
    cout << "Juanagrama: " << palabra << endl;
    cout << "No implementado" << endl;
}

void SACO()
{
    string palabra1, palabra2;
    cin >> palabra1 >> palabra2;
    palabra1 = normalizar(palabra1);
    palabra2 = normalizar(palabra2);
    cout << "Saco: " << palabra1 << " " << palabra2 << endl;
    cout << "No implementado" << endl;
}

void CONSOME()
{
    string palabra;
    cin >> palabra;
    palabra = normalizar(palabra);
    cout << "Consomé: " << palabra << endl;
    cout << "No implementado" << endl;
}

void ALARGA()
{
    string palabra;
    cin >> palabra;
    palabra = normalizar(palabra);
    cout << "Alarga: " << palabra << " -> " << diccionario.alarga(palabra) << endl;
}

void interprete(string &comando)
{
    switch (evaluarComando(comando))
    {
    case 1:
        INSERTAR();
        break;
    case 2:
        VACIAR();
        break;
    case 3:
        BUSCAR();
        break;
    case 4:
        EXIT();
        break;
    case 5:
        PARTIDAS();
        break;
    case 6:
        ALOCADO();
        break;
    case 7:
        CESAR();
        break;
    case 8:
        JUANAGRA();
        break;
    case 9:
        SACO();
        break;
    case 10:
        CONSOME();
        break;
    case 11:
        ALARGA();
        break;
    default:
        cout << "No contemplado" << endl;
        break;
    }
}