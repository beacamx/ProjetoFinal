#include "Reversi.hpp"
#include <iostream>

using namespace std;

Reversi::Reversi(Jogador* jogador1, Jogador* jogador2)
    : Jogo(jogador1, jogador2, 8, 8) {
    inicializarTabuleiro();
}

void Reversi::inicializarTabuleiro() {
    tabuleiro[3][3] = tabuleiro[4][4] = jogadorB->getPeca();
    tabuleiro[3][4] = tabuleiro[4][3] = jogadorA->getPeca();
}

vector<pair<int, int>> Reversi::calcularPosicoesPossiveis() {
    vector<pair<int, int>> posicoesPossiveis;
    // Implementar função para calcular posições possíveis no Reversi
    return posicoesPossiveis;
}

void Reversi::fazerJogada(int linha, int coluna) {
    tabuleiro[linha][coluna] = jogadorAtual->getPeca();
    // Implementar função para atualizar as peças do adversário cercadas
    imprimirTabuleiro();
    testarVitoria();
}

bool Reversi::testarVitoria() {
    /*Implementação para verificar a condição de vitória no Reversi
    if (condição de vitória no Reversi) {
        int pecasA = 0, pecasB = 0;
        for (const auto& linha : tabuleiro) {
            for (const auto& peca : linha) {
                if (peca == jogadorA->getPeca()) ++pecasA;
                else if (peca == jogadorB->getPeca()) ++pecasB;
            }
        }
        if (pecasA == pecasB) {
            cout << "Empate!" << endl;
        } else {
            cout << (pecasA > pecasB ? jogadorA->getNome() : jogadorB->getNome()) << " venceu!" << endl;
        }
        jogoAtivo = false;
        return true;
    }*/
    return false;
}