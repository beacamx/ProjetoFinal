#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "../include/Lig4.hpp"
#include "../include/Cadastro_Jogadores.hpp"
#include "../include/Jogador.hpp"

TEST_CASE("Lig4 - Inicialização do Tabuleiro") {
    cadastro c;
    c.cadastrar(new Jogador("Alice", "A1", 0, 0, 0, 0));
    c.cadastrar(new Jogador("Bob", "B1", 0, 0, 0, 0));

    Lig4 jogo(c, "A1", "B1", 6, 7);

    auto tabuleiro = jogo.inicializarTabuleiro();
    CHECK(tabuleiro.size() == 6); // Verifica o número de linhas
    CHECK(tabuleiro[0].size() == 7); // Verifica o número de colunas

    // Verifica se o tabuleiro está vazio
    for (auto& linha : tabuleiro) {
        for (auto& celula : linha) {
            CHECK(celula == 0);
        }
    }
}

TEST_CASE("Lig4 - Fazer Jogada e Testar Vitória") {
    cadastro c;
    c.cadastrar(new Jogador("Alice", "A1", 0, 0, 0, 0));
    c.cadastrar(new Jogador("Bob", "B1", 0, 0, 0, 0));

    Lig4 jogo(c, "A1", "B1", 6, 7);

    // Jogadas
    jogo.fazerJogada(5, 0); // Jogador 1
    jogo.fazerJogada(5, 1); // Jogador 2
    jogo.fazerJogada(4, 0); // Jogador 1
    jogo.fazerJogada(4, 1); // Jogador 2
    jogo.fazerJogada(3, 0); // Jogador 1
    jogo.fazerJogada(3, 1); // Jogador 2
    jogo.fazerJogada(2, 0); // Jogador 1 - Vitória vertical

    CHECK(jogo.testarVitoria() == true); // Deve ser verdadeiro porque o Jogador 1 ganhou
}

TEST_CASE("Lig4 - Calcular Linha Disponível") {
    cadastro c;
    c.cadastrar(new Jogador("Alice", "A1", 0, 0, 0, 0));
    c.cadastrar(new Jogador("Bob", "B1", 0, 0, 0, 0));

    Lig4 jogo(c, "A1", "B1", 6, 7);

    // Verifica se a primeira linha disponível na coluna 0 é a última linha do tabuleiro
    CHECK(jogo.calcularLinhaDisponivel(0) == 5);

    // Faz uma jogada na coluna 0
    jogo.fazerJogada(5, 0);

    // Verifica se a próxima linha disponível na coluna 0 é a penúltima linha do tabuleiro
    CHECK(jogo.calcularLinhaDisponivel(0) == 4);
}
