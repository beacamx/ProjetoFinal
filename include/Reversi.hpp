#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "Jogo.hpp"
#include <vector>

using namespace std;

class Reversi : public Jogo {
public:
    Reversi(Jogador* jogador1, Jogador* jogador2);

    void inicializarTabuleiro() override;
    vector<pair<int, int>> calcularPosicoesPossiveis() override;
    void fazerJogada(int linha, int coluna) override;
    bool testarVitoria() override;
};

#endif /* REVERSI_HPP */