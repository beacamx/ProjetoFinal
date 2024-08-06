#include "Troca_Definicao_Entrada_Jogador.hpp"

Troca_Definicao_Entrada_Jogador::Troca_Definicao_Entrada_Jogador() {
    numero_jogador = 1;
}

Troca_Definicao_Entrada_Jogador::~Troca_Definicao_Entrada_Jogador() {}

void Troca_Definicao_Entrada_Jogador::Troca_Definicao_Jogador() {
    numero_jogador = 2;
    jogador2 = make_unique<Interface_Definicao_Entrada_Jogador2>();
    jogador2->Run_Menu();
}

