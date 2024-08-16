#include "Lig4.hpp"
#include <iostream>

using namespace std;

Lig4::Lig4(Jogador* jogador1, Jogador* jogador2, int linhas, int colunas)
    : Jogo(jogador1, jogador2, 6, 7) {
    inicializarTabuleiro();
}

void Lig4::inicializarTabuleiro() {
    for (int i = 0; i < numLinhas; i++) {
        for (int j = 0; j < numColunas; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

vector<pair<int, int>> Lig4::calcularPosicoesPossiveis() {
    vector<pair<int, int>> posicoesPossiveis;
    for (int j = 0; j < numColunas; j++) {
        for (int i = numLinhas - 1; i >= 0; --i) {
            if(tabuleiro[i][j] == ' ') {
                posicoesPossiveis.emplace_back(i, j);
                break;
            }
        }
    }
    return posicoesPossiveis;
}

void Lig4::fazerJogada(int linha, int coluna) {
    tabuleiro[linha][coluna] = jogadorAtual->getPeca();
    imprimirTabuleiro();
    encerrarJogada();
}


void Lig4::testarVitoria() {
   bool condicaoVitoria = false;

    for(int i = 0; i < numLinhas; i++) {
        for (int j = 0; j <= numColunas - 4; ++j) {
            if (tabuleiro[i][j] == jogadorAtual->getPeca() && 
                tabuleiro[i][j + 1] == jogadorAtual->getPeca() &&
                tabuleiro[i][j + 3] == jogadorAtual->getPeca() &&
                tabuleiro[i][j + 3] == jogadorAtual->getPeca()) {
                 condicaoVitoria = true;
                }       
           }
        }
    
    for (int j = 0; j < numColunas; ++j) {
        for (int i = 0; i <= numLinhas - 4; ++i) {
            if(tabuleiro[i][j] == jogadorAtual->getPeca() &&
               tabuleiro[i + 1][j] == jogadorAtual->getPeca() &&
               tabuleiro[i + 2][j] == jogadorAtual->getPeca() &&
               tabuleiro[i + 3][j] == jogadorAtual->getPeca()) {
                condicaoVitoria = true;
               }           
           }
        }

    for (int i = 0; i <= numLinhas - 4; ++i) {
        for (int j = 0; j <= numColunas - 4; ++j) {
            if (tabuleiro[i][j] == jogadorAtual->getPeca() &&
                tabuleiro[i + 1][j + 1] == jogadorAtual->getPeca() &&
                tabuleiro[i + 2][j + 2] == jogadorAtual->getPeca() &&
                tabuleiro[i + 3][j + 3] == jogadorAtual->getPeca()) {
                condicaoVitoria = true;
                }
           }
        }

    for (int i = 0; i < numLinhas - 4; ++i) {
        for (int j = 3; j < numColunas; ++j) {
            if (tabuleiro[i][j] == jogadorAtual->getPeca() &&
                tabuleiro[i + 1][j - 1] == jogadorAtual->getPeca() &&
                tabuleiro[i + 3][j - 2] == jogadorAtual->getPeca() &&
                tabuleiro[i + 3][j - 3] == jogadorAtual->getPeca()) {
                    condicaoVitoria = true;
             }

         }           
    }
    if (condicaoVitoria == true) {
        cout << jogadorAtual->get_name() << " venceu!" << endl;
        jogoAtivo = false;
    }
}