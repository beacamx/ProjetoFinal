#include "Lig4.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

// Mudança nos parâmetros que o construtor recebe 

Lig4::Lig4(cadastro& cadastro_jogadores, string nickJogador1, string nickJogador2, int linhas, int colunas)
    : Jogo(cadastro_jogadores, nickJogador1, nickJogador2, linhas, colunas) {
    try {
        cout << "Inicializando Lig4: " << endl
             << "Jogador 1: " << nickJogador1 << endl
             << "Jogador 2: " << nickJogador2 << endl
             << "Linhas: " << linhas << endl
             << "Colunas: " << colunas << endl;
        inicializarTabuleiro();
        cout << "aqui" << endl;
    } catch (const std::exception& e) {
        cerr << "Erro ao inicializar o jogo: " << e.what() << endl;
    }
}


vector<vector<int>> Lig4::inicializarTabuleiro() {
    try {
        tabuleiro.resize(numLinhas, vector<int>(numColunas, 0));
    } catch (const std::exception& e) {
        cerr << "Erro ao inicializar o tabuleiro: " << e.what() << endl;
        throw;
    }

    return tabuleiro;
}

int Lig4::calcularLinhaDisponivel(int coluna) {
    try {
        if (coluna < 0 || coluna >= numColunas) {
            throw std::out_of_range("Coluna fora dos limites: " + to_string(coluna));
        }
        for (int i = numLinhas - 1; i >= 0; --i) {
            if (tabuleiro[i][coluna] == 0) {
                return i;
            }
        }
        return -1; // Coluna cheia
    } catch (const std::out_of_range& e) {
        cerr << "Erro: " << e.what() << endl;
    } catch (const std::exception& e) {
        cerr << "Erro desconhecido: " << e.what() << endl;
    } catch (...) {
        cerr << "Erro desconhecido." << endl;
    }
    return -1;
}


vector<pair<int, int>> Lig4::calcularPosicoesPossiveis() {
    vector<pair<int, int>> posicoesPossiveis;
    for (int j = 0; j < numColunas; j++) {
        for (int i = numLinhas - 1; i >= 0; --i) {
            if(tabuleiro[i][j] == 0) {
                posicoesPossiveis.emplace_back(i, j);
                break;
            }
        }
    }
    return posicoesPossiveis;
}

vector<vector<int>> Lig4::fazerJogada(int linha, int coluna) {
    // Implementação da lógica de jogo para uma jogada em Lig4
    try {
        if (linha >= 0 && linha < numLinhas && coluna >= 0 && coluna < numColunas && tabuleiro[linha][coluna] == 0) {
            tabuleiro[linha][coluna] = jogadorAtual->getPeca();  // Marca a jogada com a peça do jogador atual
        } else {
            cout << "Jogada inválida, tente novamente." << endl;
        }
        return tabuleiro;
    } catch (const std::out_of_range& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro desconhecido: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Erro desconhecido." << std::endl;
    }
}


bool Lig4::testarVitoria() {
   bool condicaoVitoria = false;

   // Verifica horizontalmente
    for (int i = 0; i < numLinhas; i++) {
        for (int j = 0; j <= numColunas - 4; ++j) {
            if (tabuleiro[i][j] == jogadorAtual->getPeca() && 
                tabuleiro[i][j + 1] == jogadorAtual->getPeca() &&
                tabuleiro[i][j + 2] == jogadorAtual->getPeca() &&
                tabuleiro[i][j + 3] == jogadorAtual->getPeca()) {
                condicaoVitoria = true;
            }       
        }
    }

    // Verifica verticalmente
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


    // Verifica diagonal (de cima-esquerda para baixo-direita)
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

    // Verifica diagonal (de cima-direita para baixo-esquerda)
    for (int i = 0; i <= numLinhas - 4; ++i) {
        for (int j = 3; j < numColunas; ++j) {
            if (tabuleiro[i][j] == jogadorAtual->getPeca() &&
                tabuleiro[i + 1][j - 1] == jogadorAtual->getPeca() &&
                tabuleiro[i + 2][j - 2] == jogadorAtual->getPeca() &&
                tabuleiro[i + 3][j - 3] == jogadorAtual->getPeca()) {
                condicaoVitoria = true;
            }
        }
    }
    
    if (condicaoVitoria == true) {
        cout << jogadorAtual->get_name() << " venceu!" << endl;
        jogadorAtual->win_lig4();
        jogadorAdversario->lose_lig4();
        jogoAtivo = false;
    }
    return condicaoVitoria;
}
