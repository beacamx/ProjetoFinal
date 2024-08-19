#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../libs/doctest/doctest.h"
#include "../include/jogador.hpp"

TEST_CASE("Testando o Construtor Jogador") {
    Jogador jogador1("Alice", "Alicinha");
    CHECK(jogador1.get_name() == "Alice");
    CHECK(jogador1.get_nick() == "Alicinha");
    CHECK(jogador1.get_wins() == 0);
    CHECK(jogador1.get_loses() == 0);

    Jogador jogador2("Bob", "Bobby", 5, 3, 2, 4);
    CHECK(jogador2.get_name() == "Bob");
    CHECK(jogador2.get_nick() == "Bobby");
    CHECK(jogador2.get_wins_lig4() == 5);
    CHECK(jogador2.get_wins_Reversi() == 3);
    CHECK(jogador2.get_loses_lig4() == 2);
    CHECK(jogador2.get_loses_Reversi() == 4);
}

TEST_CASE("Testando os Métodos get e set") {
    Jogador jogador("Carlos", "Carlinhos");
    CHECK(jogador.getPeca() == 0);  // Valor inicial, dependendo da implementação
    jogador.setPeca(1);
    CHECK(jogador.getPeca() == 1);

    jogador.win_lig4();
    CHECK(jogador.get_wins_lig4() == 1);

    jogador.lose_Reversi();
    CHECK(jogador.get_loses_Reversi() == 1);
}

TEST_CASE("Testando player_compare") {
    Jogador jogador1("Diana", "Didi", 3, 2, 1, 1);
    Jogador jogador2("Elena", "Eli", 4, 3, 0, 0);
    
    player_compare comp;
    CHECK(comp(&jogador1, &jogador2) == true); // Depende da lógica implementada
}
