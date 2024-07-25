#include <SFML/Graphics.hpp>
#include <iostream>

#include "Interface/Interface_Lig4.hpp"
#include "Interface/Interfaces.hpp"

using namespace std;

int main(int argc, char **argv) {
    int operador;
    cout << "Escolha um jogo: " << endl << "1 - Lig4" << endl << "2 - Reversi" << endl;
    cin >> operador;
    if(operador == 1)
        inicia_Lig4(argc, argv);
    else if(operador == 2)
        inicia_Reversi(argc, argv);
}