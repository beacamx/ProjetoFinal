#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include "../include/Reversi.hpp"
#include "../include/Cadastro_Jogadores.hpp"
#include "../include/Jogador.hpp"


TEST_CASE("Reversi - Inicialização do Tabuleiro") {
    cadastro c;
    c.cadastrar(new Jogador("Alice", "A1", 0, 0, 0, 0));
    c.cadastrar(new Jogador("Bob", "B1", 0, 0, 0, 0));

    Reversi jogo(c, "A1", "B1", 8, 8);

    auto tabuleiro = jogo.inicializarTabuleiro();
    CHECK(tabuleiro.size() == 8); // Verifica o número de linhas
    CHECK(tabuleiro[0].size() == 8); // Verifica o número de colunas

    // Verifica se o tabuleiro está inicializado corretamente
    // Dependendo da implementação, você pode precisar ajustar isso
}

TEST_CASE("Reversi - Fazer Jogada e Testar Vitória") {
    cadastro c;
    c.cadastrar(new Jogador("Alice", "A1", 0, 0, 0, 0));
    c.cadastrar(new Jogador("Bob", "B1", 0, 0, 0, 0));

    Reversi jogo(c, "A1", "B1", 8, 8);

    // Realiza jogadas
    jogo.fazerJogada(3, 3); // Exemplo de jogada
    jogo.fazerJogada(4, 4); // Exemplo de jogada

    // Verifica se a vitória está sendo detectada corretamente
    CHECK(jogo.testarVitoria() == false); // Ajuste conforme a lógica do jogo
}

TEST_CASE("Reversi - Calcular Posições Possíveis") {
    cadastro c;
    c.cadastrar(new Jogador("Alice", "A1", 0, 0, 0, 0));
    c.cadastrar(new Jogador("Bob", "B1", 0, 0, 0, 0));

    Reversi jogo(c, "A1", "B1", 8, 8);

    auto posicoes = jogo.calcularPosicoesPossiveis();

    // Verifique as posições possíveis, se necessário
    // Dependendo da implementação, ajuste os testes para verificar as posições corretas
}
