#ifndef LIG4_HPP
#define LIG4_HPP

#include "Jogo.hpp"
#include <vector>

using namespace std;

class Lig4 : public Jogo {
public:
    Lig4(Jogador* jogador1, Jogador* jogador2, int linhas, int colunas);

    void inicializarTabuleiro() override; // ja tem
    void fazerJogada(int linha, int coluna) override; // dentro da logic
    bool testarVitoria() override;
    // funcao verificar se o tabuleiro esta cheio (se tem zero em alguma casa)

protected:
    vector<pair<int, int>> calcularPosicoesPossiveis() override;

};

#endif /* LIG4_HPP */