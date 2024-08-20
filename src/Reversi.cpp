#include "Reversi.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

Reversi::Reversi(cadastro& cadastro_jogadores, string nickJogador1, string nickJogador2, int linhas, int colunas)
    : Jogo(cadastro_jogadores, nickJogador1, nickJogador2, linhas, colunas) {
    try {
        inicializarTabuleiro();
    } catch (const exception& e) {
        cerr << "Erro ao inicializar o tabuleiro: " << e.what() << endl;
        throw;
    }
}

vector<vector<int>> Reversi::inicializarTabuleiro() {
    try {
        for (int i = 0; i < numLinhas; i++) {
            for (int j = 0; j < numColunas; j++) {
                tabuleiro[i][j] = 0;
            }
        }
        tabuleiro[(numLinhas/2)][(numColunas/2) -1] = tabuleiro[(numLinhas/2) -1][numColunas/2] = jogadorA->getPeca();
        tabuleiro[numLinhas/2][numColunas/2] = tabuleiro[(numLinhas/2) -1][(numColunas/2) -1] = jogadorB->getPeca();
        return tabuleiro;
    } catch (const out_of_range& e) {
        cerr << "Erro ao acessar o tabuleiro: " << e.what() << endl;
        throw;
    } catch (const exception& e) {
        cerr << "Erro desconhecido ao inicializar o tabuleiro: " << e.what() << endl;
        throw;
    }
}

vector<pair<int, int>> Reversi::calcularPosicoesPossiveis() {
    vector<pair<int, int>> posicoesPossiveis;
    try {
    for (int i = 0; i < numLinhas; ++i) {
        for (int j = 0; j < numColunas; ++j) {
            if (tabuleiro[i][j] == 0 && testarCapturasTotais(i, j)) {
                posicoesPossiveis.push_back({i, j});
            }
        }
    }
    if(posicoesPossiveis.empty()) {
        cout << "Não ha jogadas possiveis! " << jogadorAtual->get_name() << " perde a vez." << endl;
        //no Reversi uma jogada só é válida se resulta na captura de pelo menos uma peça do adversário.
        //se não há captura possíveis, o jogador perde a vez.
    }
    } catch (const out_of_range& e) {
        cerr << "Erro ao acessar o tabuleiro: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Erro desconhecido ao calcular posições possíveis: " << e.what() << endl;
    }
    return posicoesPossiveis;
}

vector<vector<int>> Reversi::fazerJogada(int linha, int coluna) {
    tabuleiro[linha][coluna] = jogadorAtual->getPeca();
    fazerCaptura(linha, coluna);
    //como para uma jogada ser válida sempre deve resultar em captura de pelo menos uma posição, o método fazerCaptura
    //sempre deve ser chamado em fazerJogada.
    imprimirTabuleiro();
    encerrarJogada();
    return tabuleiro;
}

bool Reversi::testarVitoria() {
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
            jogadorA->win_Reversi();
            jogadorB->lose_Reversi();
        } else if (pecasB > pecasA) {
            cout << jogadorB->get_name() << " venceu!" << endl;
            jogadorB->win_Reversi();
            jogadorA->lose_Reversi();
        } else {
            cout << "Empate!" << endl;
        }
        jogoAtivo=false;
        return condicaoVitoria;
    }
}

bool Reversi::testarCapturaPorDirecao(int linha, int coluna, int dx, int dy) {
    //testa se é possível capturar alguma peça do adversário pela direção {dx, dy}
    try {
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
    } catch (const out_of_range& e) {
        cerr << "Erro ao testar captura por direção: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Erro desconhecido ao testar captura por direção: " << e.what() << endl;
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
    try {
        const int direcoes[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        //8 direções possíveis: para cima {0,1}, baixo {0,-1}, esquerda{-1,0}, direita {1,0} e diagonais
        
        for (const auto& direcao : direcoes) {
            int dx = direcao[0], dy = direcao[1];
            vector<pair<int, int>> capturas;
            //criação de vetor que guarda as posições capturadas
            
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
    } catch (const out_of_range& e) {
        cerr << "Erro ao fazer captura: " << e.what() << endl;
        throw;
    } catch (const exception& e) {
        cerr << "Erro desconhecido ao fazer captura: " << e.what() << endl;
        throw;
    }

}