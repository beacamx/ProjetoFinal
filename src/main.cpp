#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "Interface/Interface_Jogo.hpp"
#include "Interface/Interface_Lig4.hpp"
#include "Interface/Interface_Reversi.hpp"

using namespace std;

int main(int argc, char **argv) {
    int operador;

    cout << "Escolha um jogo: " << endl << "1 - Lig4" << endl << "2 - Reversi" << endl;
    cin >> operador;

    unique_ptr<Interface_Jogo> jogo;

    if (operador == 1) {
        jogo = make_unique<Interface_Lig4>();
    } else if (operador == 2) {
        jogo = make_unique<Interface_Reversi>();
    } else {
        cerr << "Opção inválida" << endl;
        return 1;
    }

    return jogo->Inicia_Jogo(argc, argv);
}