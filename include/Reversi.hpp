#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "Jogo.hpp"
#include <vector>
#include <utility>

using namespace std;

class Reversi : public Jogo {
public:
    Reversi(){};
    Reversi(cadastro& cadastro_jogadores, string nickJogador1, string nickJogador2, int linhas, int colunas);

    ~Reversi() = default;

    void inicializarTabuleiro() override;
    vector<pair<int, int>> calcularPosicoesPossiveis() override;
    vector<vector<int>> fazerJogada(int linha, int coluna) override;
    void testarVitoria() override;

    bool testarCapturaPorDirecao(int linha, int coluna, int dx, int dy);
    bool testarCapturasTotais(int linha, int coluna);
    void fazerCaptura(int linha, int coluna);    
};

#endif /* REVERSI_HPP */