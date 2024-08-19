#ifndef JOGO_HPP
#define JOGO_HPP

#include "jogador.hpp"
#include "Cadastro_Jogadores.hpp"
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

class Jogo {

    public:
    Jogo();
    Jogo(cadastro& cadastro_jogadores, string nickJogador1, string nickJogador2, int linhas, int colunas);
    virtual ~Jogo();

    void iniciarJogo();
    void imprimirTabuleiro() const;
    vector<vector<int>> receberJogada();  // Outra mudança
    void testarJogada(int linha, int coluna);
    void encerrarJogada();
    void trocarJogador();
    void encerrarJogo();
    bool isJogoAtivo() const;  // Verifica se o jogo está ativo
    
    virtual vector<vector<int>> fazerJogada(int linha, int coluna) = 0;  // Mudança para retornar o tabuleiro
    virtual bool testarVitoria() = 0;
    virtual void inicializarTabuleiro() = 0;
    virtual vector<pair<int, int>> calcularPosicoesPossiveis() = 0;
    
    protected:
    Jogador* jogadorA;
    Jogador* jogadorB;
    Jogador* jogadorAtual;
    Jogador* jogadorAdversario;
    int numLinhas;
    int numColunas;
    vector<vector<int>> tabuleiro;
    bool jogoAtivo;
    cadastro registro_geral;
};

#endif /* JOGO_HPP */
