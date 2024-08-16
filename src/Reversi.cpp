#include "Reversi.hpp"
#include <iostream>

using namespace std;

Reversi::Reversi(Jogador* jogador1, Jogador* jogador2)
    : Jogo(jogador1, jogador2, 8, 8) {
    inicializarTabuleiro();
}

void Reversi::inicializarTabuleiro() {
    for (int i = 0; i < numLinhas; ++i) {
        for (int j = 0; j < numColunas; ++j) {
            tabuleiro[i][j] = 0;
        }
    }
    tabuleiro[3][3] = tabuleiro[4][4] = jogadorB->getPeca();
    tabuleiro[3][4] = tabuleiro[4][3] = jogadorA->getPeca();
}

vector<pair<int, int>> Reversi::calcularPosicoesPossiveis() {
    vector<pair<int, int>> posicoesPossiveis;
    for (int i = 0; i < numLinhas; ++i) {
        for (int j = 0; j < numColunas; ++j) {
            if (tabuleiro[i][j] == 0 && testarCapturasTotais(i, j)) {
                posicoesPossiveis.push_back({i, j});
            }
        }
    }
    if(posicoesPossiveis.empty()) {
        cout << "Não há jogadas possíveis! " << jogadorAtual->get_name() << " perde a vez." << endl;
    }
    return posicoesPossiveis;
}

void Reversi::fazerJogada(int linha, int coluna) {
    tabuleiro[linha][coluna] = jogadorAtual->getPeca();
    fazerCaptura(linha, coluna);
    imprimirTabuleiro();
    encerrarJogada();
}

void Reversi::testarVitoria() {
    bool condicaoVitoria = false;
    if (calcularPosicoesPossiveis().empty()) {
        swap(jogadorAtual, jogadorAdversario);
        if (calcularPosicoesPossiveis().empty()) {
            condicaoVitoria = true;
            //se não há mais posições possíveis nem para o jogador atual nem para o adversário, então o jogo acaba.
        }
        swap(jogadorAtual, jogadorAdversario);
        // restaura o jogador atual original.
    }

    if (condicaoVitoria) {
        int pecasA = 0, pecasB = 0;
        for (const auto& linha : tabuleiro) {
            for (const auto& valorPosicao : linha) {
                if (valorPosicao == jogadorA->getPeca()) ++pecasA;
                else if (valorPosicao == jogadorB->getPeca()) ++pecasB;
            }
        }
        if (pecasA > pecasB) {
            cout << jogadorA->get_name() << " venceu!" << endl;
        } else if (pecasB > pecasA) {
            cout << jogadorB->get_name() << " venceu!" << endl;
        } else {
            cout << "Empate!" << endl;
        }
        jogoAtivo=false;
    }
}

bool Reversi::testarCapturaPorDirecao(int linha, int coluna, int dx, int dy) {
    //testa se é possível capturar alguma peça do adversário pela direção {dx, dy}
    int i = linha + dx;
    int j = coluna + dy;
    bool encontrouOponente = false;

    while (i >= 0 && i < numLinhas && j >= 0 && j < numColunas) {
        if (tabuleiro[i][j] == jogadorAdversario->getPeca()) {
            encontrouOponente = true;
        } else if (tabuleiro[i][j] == jogadorAtual->getPeca() && encontrouOponente) {
            return true;
        } else {
            break;
        }
        i += dx;
        j += dy;
    }
    return false;
}

bool Reversi::testarCapturasTotais(int linha, int coluna) {
    //chama testarCapturaPorDirecao para todas as direções
    const int direcoes[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    //8 direções possíveis: para cima {0,1}, baixo {0,-1}, esquerda{-1,0}, direita {1,0} e diagonais

    for (const auto& direcao : direcoes) {
        int dx = direcao[0], dy = direcao[1];
        if (testarCapturaPorDirecao(linha, coluna, dx, dy)) {
            return true;
        }
    }
    return false;
}

void Reversi::fazerCaptura(int linha, int coluna) {
    const int direcoes[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    //8 direções possíveis: para cima {0,1}, baixo {0,-1}, esquerda{-1,0}, direita {1,0} e diagonais

    for (const auto& direcao : direcoes) {
        int dx = direcao[0], dy = direcao[1];
        vector<pair<int, int>> capturas;
        //guarda as posições capturadas

        int i = linha + dx, j = coluna + dy;
        while (i >= 0 && i < numLinhas && j >= 0 && j < numColunas && tabuleiro[i][j] == jogadorAdversario->getPeca()) {
            capturas.push_back({i, j});
            //adiciona posiçao capturada ao vetor de capturas
            i += dx;
            j += dy;
        }

        if (!capturas.empty() && i >= 0 && i < numLinhas && j >= 0 && j < numColunas && tabuleiro[i][j] == jogadorAtual->getPeca()) {
            for (const auto& captura : capturas) {
                tabuleiro[captura.first][captura.second] = jogadorAtual->getPeca();
            }   //substitui as peças capturadas do adversários por peças do jogador atual
        }
    }
}