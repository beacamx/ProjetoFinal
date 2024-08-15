#ifndef TROCA_DEFINICAO_ENTRADA_JOGADOR_HPP
#define TROCA_DEFINICAO_ENTRADA_JOGADOR_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "Interface_Definicao_Entrada_Jogador2.hpp"

using namespace std;

class Troca_Definicao_Entrada_Jogador {
    public:
        void Troca_Definicao_Jogador ();
        Troca_Definicao_Entrada_Jogador ();
        ~Troca_Definicao_Entrada_Jogador ();
        unique_ptr<Interface_Definicao_Entrada_Jogador2> jogador2;

};

#endif