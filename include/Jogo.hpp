#ifndef JOGO_HPP
#define JOGO_HPP

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Jogador {
public:
    Jogador(const string& nome, char peca) : nome(nome), peca(peca) {}
    string getNome() const { return nome; }
    char getPeca() const { return peca; }
private:
    string nome;
    char peca;
};

class Jogo {
public:
    Jogo(Jogador* jogador1, Jogador* jogador2, int linhas, int colunas);
    virtual ~Jogo();

    void iniciarJogo();
    void imprimirTabuleiro() const;
    void receberJogada();
    bool testarJogada(int linha, int coluna);
    void trocarJogador();
    void encerrarJogo();
    
    virtual void inicializarTabuleiro() = 0;
    virtual void fazerJogada(int linha, int coluna) = 0;
    virtual bool testarVitoria() = 0;

protected:
    Jogador* jogadorA;
    Jogador* jogadorB;
    Jogador* jogadorAtual;
    int numLinhas;
    int numColunas;
    vector<vector<char>> tabuleiro;

    virtual vector<pair<int, int>> calcularPosicoesPossiveis() = 0;
};

#endif /* JOGO_HPP */