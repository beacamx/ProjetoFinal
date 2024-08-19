#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "Jogo.hpp"
#include <vector>
#include <utility>

using namespace std;

class Reversi : public Jogo {
public:
    Reversi(cadastro& cadastro_jogadores, string nomeJogador1, string nomeJogador2, int linhas, int colunas);

    void inicializarTabuleiro() override;
    vector<pair<int, int>> calcularPosicoesPossiveis() override;
    void fazerJogada(int linha, int coluna) override;
    void testarVitoria() override;

    bool testarCapturaPorDirecao(int linha, int coluna, int dx, int dy);
    bool testarCapturasTotais(int linha, int coluna);
    void fazerCaptura(int linha, int coluna);    
};

#endif /* REVERSI_HPP */