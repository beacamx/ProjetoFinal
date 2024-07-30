#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "Interface/Interface_Jogo.hpp"
#include "Interface/Interface_Lig4.hpp"
#include "Interface/Interface_Reversi.hpp"

using namespace std;

int main(int argc, char **argv) {
    unsigned int operador;

    cout << "Escolha um jogo: " << endl << "1 - Lig4" << endl << "2 - Reversi" << endl;
    cin >> operador;

    unique_ptr<Interface_Jogo> jogo;
    /* proposta de looping que admite nova tentativa ante erro de entrada do usuário a partir da linha 12
    while(1){
        cout << "Escolha um jogo: " << endl << "1 - Lig4" << endl << "2 - Reversi" << endl << "0 - Sair" << endl;
        cin >> operador;
        switch(operador){
            case 1:
                jogo = make_unique<Interface_Lig4>();
                return jogo->iniciarJogo();
                break;
            case 2:
                jogo = make_unique<Interface_Reversi()>;
                return jogo->IniciarJogo;
            case 0:
                mensagem de saida
                return 0;
            default:
                mensagem de erro de entrada;
        }
    }
    */
    if (operador == 1) {
        jogo = make_unique<Interface_Lig4>();
    } else if (operador == 2) {
        jogo = make_unique<Interface_Reversi>();
    } else {
        cerr << "Opção inválida" << endl;
        return 1;
    }

    return jogo->iniciarJogo();
}
