#include "Comandos.hpp"
using namespace std;

int main() {
    string comando;
    while (cin >> comando)
        interprete(comando);
    return 0;
}