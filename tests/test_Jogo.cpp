#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../libs/doctest/doctest.h"
#include "../include/Jogador.hpp"
#include "../include/Cadastro_Jogadores.hpp"
#include "../include/Jogo.hpp"

TEST_CASE("Testando a classe Jogo") {
    cadastro cadastro_jogadores;

    // Adicionando jogadores fictícios
    Jogador jogador1("Alice", "A");
    Jogador jogador2("Bob", "B");
    cadastro_jogadores.cadastrar(&jogador1);
    cadastro_jogadores.cadastrar(&jogador2);

    SUBCASE("Construtor e Métodos Básicos") {
        CHECK_NOTHROW(Jogo jogo(cadastro_jogadores, "Alice", "Bob", 3, 3));

        Jogo jogo(cadastro_jogadores, "Alice", "Bob", 3, 3);

        // Verificar se os jogadores foram corretamente atribuídos
        CHECK(jogo.jogadorA == &jogador1);
        CHECK(jogo.jogadorB == &jogador2);

        // Verificar se o tabuleiro foi inicializado
        CHECK(jogo.tabuleiro.size() == 3);
        CHECK(jogo.tabuleiro[0].size() == 3);
    }

    SUBCASE("Recebendo e Testando Jogada") {
        // Mock para testar as jogadas
        // Aqui, você precisaria definir um jogo concreto que implementa os métodos virtuais puros

        // Exemplo de verificação básica
        // (Esta parte precisa ser ajustada com uma implementação concreta)
        // JogoTest jogo(cadastro_jogadores, "Alice", "Bob", 3, 3);
        // CHECK_NOTHROW(jogo.receberJogada());
    }
}
