#include "Jogo.hpp"
#include <iostream>

using namespace std;

Jogo::Jogo(Jogador* jogador1, Jogador* jogador2, int linhas, int colunas)
    : jogadorA(jogador1), jogadorB(jogador2), jogadorAtual(jogador1), numLinhas(linhas), numColunas(colunas) {
    // Inicializar o tabuleiro conforme o tamanho passado
    tabuleiro.resize(numLinhas, vector<char>(numColunas, 'O')); // Inicializa com peças vazias 'O'
}

Jogo::~Jogo() {
    delete jogadorA;
    delete jogadorB;
}

void Jogo::iniciarJogo() {
    jogadorAtual = jogadorA;
    while (!testarVitoria()) {
        receberJogada();
        trocarJogador(); // Troca para o próximo jogador após jogada finalizar
    }
    encerrarJogo();
}

void Jogo::imprimirTabuleiro() const {
    for (int i = 0; i < numLinhas; ++i) {
        for (int j = 0; j < numColunas; ++j) {
            cout << tabuleiro[i][j] << " ";
        }
        cout << endl;
    }
}

void Jogo::receberJogada() {
    imprimirTabuleiro();
    cout << "Posições possíveis para " << jogadorAtual->getNome() << ":" << endl;
    vector<pair<int, int>> posicoesPossiveis = calcularPosicoesPossiveis();
    for (const auto& pos : posicoesPossiveis) {
        cout << "(" << pos.first << ", " << pos.second << ") ";
    }
    cout << endl;

    cout << "Digite a linha e coluna desejada (ex: 1 2): ";
    int linha, coluna;
    cin >> linha >> coluna;

    if (!testarJogada(linha, coluna)) {
        cout << "Jogada inválida, tente novamente." << endl;
        receberJogada();
    }
}

bool Jogo::testarJogada(int linha, int coluna) {
    vector<pair<int, int>> posicoesPossiveis = calcularPosicoesPossiveis();
    for (const auto& pos : posicoesPossiveis) {
        if (pos.first == linha && pos.second == coluna) {
            fazerJogada(linha, coluna);
            return true;
        }
    }
    return false;
}

void Jogo::trocarJogador() {
    if (jogadorAtual == jogadorA) {
        jogadorAtual = jogadorB;
    } else {
        jogadorAtual = jogadorA;
    }
    cout << "Vez do jogador " << jogadorAtual->getNome() << endl;
}

void Jogo::encerrarJogo() {
    cout << "Jogo encerrado." << endl;
}