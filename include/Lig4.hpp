#ifndef LIG4_HPP
#define LIG4_HPP

#include "Jogo.hpp"
#include <vector>

using namespace std;

class Lig4 : public Jogo {
public:
    Lig4(Jogador* jogador1, Jogador* jogador2, int linhas, int colunas);

    void inicializarTabuleiro() override;
    void fazerJogada(int linha, int coluna) override;
    bool testarVitoria() override;

protected:
    vector<pair<int, int>> calcularPosicoesPossiveis() override;

};

#endif /* LIG4_HPP */