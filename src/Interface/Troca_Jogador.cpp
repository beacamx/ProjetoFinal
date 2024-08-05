#include "Troca_Jogador.hpp"

Troca_Jogador::Troca_Jogador() {
    numero_jogador = 1;
}

Troca_Jogador::~Troca_Jogador() {}

void Troca_Jogador::Troca_Definicao_Jogador() {
    numero_jogador = 2;
    jogador2 = make_unique<Interface_Definicao_Entrada_Jogador2>();
    jogador2->Run_Menu();
}

