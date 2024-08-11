#include "Troca_Definicao_Entrada_Jogador.hpp"

Troca_Definicao_Entrada_Jogador::Troca_Definicao_Entrada_Jogador() : jogador2(nullptr) {}

Troca_Definicao_Entrada_Jogador::~Troca_Definicao_Entrada_Jogador() {}

void Troca_Definicao_Entrada_Jogador::Troca_Definicao_Jogador() {
    jogador2 = make_unique<Interface_Definicao_Entrada_Jogador2>();
    jogador2->Run_Menu();
}

