#include "Troca_Jogador.hpp"

std::unique_ptr<Interface_Definicao_Entrada_Jogador2> Troca_Jogador::jogador2 = nullptr;

void Troca_Jogador::Troca_Definicao_Jogador() {
    numero_jogador = 2;
    jogador2 = std::make_unique<Interface_Definicao_Entrada_Jogador2>();
    jogador2->Run_Menu();
}

Troca_Jogador::Troca_Jogador() {
    // Inicialização, se necessário
}

Troca_Jogador::~Troca_Jogador() {
    // Limpeza, se necessário
}
