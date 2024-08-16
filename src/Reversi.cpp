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
    int pecaAdversaria = (jogadorAtual == jogadorA) ? 2 : 1;
    int pecaAtual = (jogadorAtual == jogadorA) ? 1 : 2;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (tabuleiro[i][j] != 0) continue; //checa se a posição está vazia

            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) continue;
                    int x = i + dx, y = j + dy;
                    bool encontrouAdversario = false;

                    while (x >= 0 && x < 8 && y >= 0 && y < 8 && tabuleiro[x][y] == pecaAdversaria) {
                        x += dx;
                        y += dy;
                        encontrouAdversario = true;
                    }

                    if (encontrouAdversario && x >= 0 && x < 8 && y >= 0 && y < 8 && tabuleiro[x][y] == pecaAtual) {
                        posicoesPossiveis.push_back({i, j});
                        break;  // Não precisa checar outras direções para esta célula
                    }
                }
            }
        }
    }

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
            cout << (pecasA > pecasB ? jogadorA->get_name() : jogadorB->get_name()) << " venceu!" << endl;
        }
        jogoAtivo = false;
        return true;
    }*/
    return false;
}