#include "Lig4.hpp"
#include <iostream>

using namespace std;

Lig4::Lig4(Jogador* jogador1, Jogador* jogador2)
    : Jogo(jogador1, jogador2, 6, 7) {
    inicializarTabuleiro();
}

void Lig4::inicializarTabuleiro() {
    // Tabuleiro do Lig4 começa vazio, então já é inicializado no construtor da classe base
}

vector<pair<int, int>> Lig4::calcularPosicoesPossiveis() {
    vector<pair<int, int>> posicoesPossiveis;
    //Implementar cálculo das posições possíveis: serão as posições não ocupadas "mais abaixo" no tabuleiro
    return posicoesPossiveis;
}

void Lig4::fazerJogada(int linha, int coluna) {
    tabuleiro[linha][coluna] = jogadorAtual->getPeca();
    imprimirTabuleiro();
    testarVitoria();
}

bool Lig4::testarVitoria() {
    /* Implementação para verificar se há uma fileira de 4 peças
    Se há fileira de 4 peças, o vencedor é declarado e o jogo é encerrado
    if (condição para 4 peças em linha) {
        cout << jogadorAtual->getNome() << " venceu!" << endl;
        jogoAtivo = false;
        return true;
    }*/
    return false;
}