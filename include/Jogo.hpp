#ifndef JOGO_HPP
#define JOGO_HPP

#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Jogo {
    public:
    // Jogo(Jogador* jogador1, Jogador* jogador2, int linhas, int colunas); inicializador utilizado sem parâmetros na main
    virtual ~Jogo();

    int iniciarJogo(); //a main usa como retorno inteiro, salvo engano, é obrigatório em c++
    void imprimirTabuleiro() const;
    void receberJogada();
    void testarJogada(int linha, int coluna);
    void trocarJogador();
    void encerrarJogo();
    
    virtual void fazerJogada(int linha, int coluna) = 0;
    virtual bool testarVitoria() = 0;
    virtual void inicializarTabuleiro() = 0;
    virtual vector<pair<int, int>> calcularPosicoesPossiveis() = 0;
    
    protected:
    Jogador* jogadorA;
    Jogador* jogadorB;
    Jogador* jogadorAtual;
    int numLinhas;
    int numColunas;
    vector<vector<char>> tabuleiro;
    bool jogoAtivo;
};

#endif /* JOGO_HPP */
