#ifndef JOGO_HPP
#define JOGO_HPP
#include "jogador.hpp"
#include <vector>
#include <iostream>
#include <utility>
using namespace std;
class Jogo {
    public:
    Jogo(Jogador* jogador1, Jogador* jogador2, int linhas, int colunas);
    virtual ~Jogo();

    void iniciarJogo();
    void imprimirTabuleiro() const;
    void receberJogada();
    void testarJogada(int linha, int coluna);
    void encerrarJogada();
    void trocarJogador();
    void encerrarJogo();
    
    virtual void fazerJogada(int linha, int coluna) = 0;
    virtual void testarVitoria() = 0;
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
};

#endif /* JOGO_HPP */
