#ifndef TROCA_JOGADOR_HPP
#define TROCA_JOGADOR_HPP

#include <memory>
#include "Interface_Definicao_Entrada_Jogador2.hpp"

using namespace std;

class Troca_Jogador {
    public:
        void Troca_Definicao_Jogador();
        Troca_Jogador();
        ~Troca_Jogador();
        int numero_jogador;
        unique_ptr<Interface_Definicao_Entrada_Jogador2> jogador2;

};

#endif