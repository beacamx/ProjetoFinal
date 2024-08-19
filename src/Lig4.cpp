#include "Lig4.hpp"
#include <iostream>

using namespace std;

// Construtor Lig4 que recebe uma referência para o cadastro de jogadores e os nomes dos jogadores

Lig4::Lig4(cadastro& cadastro_jogadores, string nomeJogador1, string nomeJogador2, int linhas, int colunas)
    : Jogo(cadastro_jogadores.find_by_name(nomeJogador1), cadastro_jogadores.find_by_name(nomeJogador2), linhas, colunas) {
    if (!jogadorA || !jogadorB) {
        throw std::runtime_error("Um ou ambos os jogadores não foram encontrados no cadastro.");
    }
    inicializarTabuleiro();
}

void Lig4::inicializarTabuleiro() {
    for (int i = 0; i < numLinhas; i++) {
        for (int j = 0; j < numColunas; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

int Lig4::calcularLinhaDisponivel(int coluna) {
    for (int i = numLinhas - 1; i >= 0; --i) {
        if (tabuleiro[i][coluna] == 0) {
            return i;
        }
    }
    return -1; // Coluna cheia
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
    // Implementação da lógica de jogo para uma jogada em Lig4
    if (linha >= 0 && linha < numLinhas && coluna >= 0 && coluna < numColunas && tabuleiro[linha][coluna] == 0) {
        tabuleiro[linha][coluna] = jogadorAtual->getPeca();  // Marca a jogada com a peça do jogador atual
    } else {
        std::cout << "Jogada inválida, tente novamente." << std::endl;
    }
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