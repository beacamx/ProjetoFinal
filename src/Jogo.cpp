#include "Jogo.hpp"
#include <iostream>

using namespace std;

Jogo::Jogo() {}

Jogo::Jogo(cadastro& cadastro_jogadores, string nomeJogador1, string nomeJogador2, int linhas, int colunas)
    : numLinhas(linhas), numColunas(colunas), jogoAtivo(true) {
    // Busca os jogadores no cadastro
    cout << nomeJogador1 << endl << nomeJogador2 << endl << linhas << endl << colunas << endl;
    jogadorA = cadastro_jogadores.find_by_nick(nomeJogador1);
    jogadorB = cadastro_jogadores.find_by_nick(nomeJogador2);

    if (!jogadorA || !jogadorB) {
        throw std::runtime_error("Um ou ambos os jogadores não foram encontrados no cadastro.");
    }

    // Inicializa o tabuleiro
    tabuleiro.resize(numLinhas, std::vector<int>(numColunas));
    jogadorA->setPeca(1);
    jogadorB->setPeca(2);
    jogadorAtual = jogadorA;
    jogadorAdversario = jogadorB;
}

Jogo::~Jogo() {
    // Como o Jogo não é responsável pela alocação dos jogadores, não é necessário deletá-los
}

void Jogo::iniciarJogo() {
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
    cout << "Posicoes possiveis para " << jogadorAtual->get_name() << ":" << endl;
    auto posicoesPossiveis = calcularPosicoesPossiveis();
    for (const auto& pos : posicoesPossiveis) {
        cout << "(" << pos.first << ", " << pos.second << ") ";
    }
    cout << endl;

    cout << "Digite a linha e coluna desejada no seguinte formato (linha coluna): ";
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
    cout << "Jogada invalida, tente novamente." << endl;
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
