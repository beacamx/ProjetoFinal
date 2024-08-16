#include "Jogo.hpp"
#include <iostream>

using namespace std;

Jogo::Jogo(Jogador* jogador1, Jogador* jogador2, int linhas, int colunas)
        : jogadorA(jogador1), jogadorB(jogador2), jogadorAtual(jogador1), numLinhas(linhas), numColunas(colunas), jogoAtivo(true) {
        tabuleiro.resize(numLinhas, vector<int>(numColunas));
        jogadorA->setPeca(1);
        jogadorB->setPeca(2);
    }

Jogo::~Jogo() {
    delete jogadorA;
    delete jogadorB;
}

void Jogo::iniciarJogo() {
    jogadorAtual = jogadorA;
    jogadorAdversario = jogadorB;
    while (jogoAtivo) {
        receberJogada();
        if (!jogoAtivo) break;
        trocarJogador();
    }
    encerrarJogo();
}

void Jogo::imprimirTabuleiro() const {
    for (int i = 0; i < numLinhas; ++i) {
        for (int j = 0; j < numColunas; ++j) {
            cout << tabuleiro[i][j] << 0;
        }
        cout << endl;
    }
}

void Jogo::receberJogada() {
    imprimirTabuleiro();
    cout << "Posições possíveis para " << jogadorAtual->get_name() << ":" << endl;
    auto posicoesPossiveis = calcularPosicoesPossiveis();
    for (const auto& pos : posicoesPossiveis) {
        cout << "(" << pos.first << ", " << pos.second << ") ";
    }
    cout << endl;

    cout << "Digite a linha e coluna desejada (ex: 1 2): ";
    int linha, coluna;
    cin >> linha >> coluna;

    testarJogada(linha, coluna);
}

void Jogo::testarJogada(int linha, int coluna) {
    auto posicoesPossiveis = calcularPosicoesPossiveis();
    if (calcularPosicoesPossiveis().empty()) {
        encerrarJogada();
    return;
    }
    for (const auto& pos : posicoesPossiveis) {
        if (pos.first == linha && pos.second == coluna) {
            fazerJogada(linha, coluna);
            return;
        }
    }
    cout << "Jogada inválida, tente novamente." << endl;
    receberJogada();
}

void Jogo::encerrarJogada() {
    testarVitoria();
}

void Jogo::trocarJogador() {
    swap(jogadorAtual, jogadorAdversario);
    cout << "Vez do jogador " << jogadorAtual->get_name() << endl;
}

void Jogo::encerrarJogo() {
    cout << "Jogo encerrado." << endl;
}