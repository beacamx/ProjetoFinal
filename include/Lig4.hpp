#ifndef LIG4_HPP
#define LIG4_HPP

#include "Jogo.hpp"
#include "Cadastro_Jogadores.hpp" // Incluisão do cabeçalho do cadastro de jogadores
#include <vector>

using namespace std;

class Lig4 : public Jogo {
public:

    //Mudança no construtror
    Lig4(){};
    Lig4(cadastro& cadastro_jogadores, string nomeJogador1, string nomeJogador2, int linhas, int colunas);

    void inicializarTabuleiro() override; 
    void fazerJogada(int linha, int coluna) override; 
    void testarVitoria() override;
    int calcularLinhaDisponivel(int coluna);

    // funcao verificar se o tabuleiro esta cheio (se tem zero em alguma casa)

protected:
    vector<pair<int, int>> calcularPosicoesPossiveis() override;

};

#endif /* LIG4_HPP */
