#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "../include/Cadastro_Jogadores.hpp"
#include "../include/jogador.hpp"

TEST_CASE("Cadastro de Jogadores") {
    cadastro c;

    // Teste de cadastro
    Jogador* j1 = new Jogador("Alice", "A1", 5, 3, 2, 1);
    c.cadastrar(j1);
    CHECK(c.find_by_name("Alice") == j1);
    CHECK(c.find_by_nick("A1") == j1);

    // Teste de remover
    c.remover(j1);
    CHECK(c.find_by_name("Alice") == nullptr);
    CHECK(c.find_by_nick("A1") == nullptr);

    delete j1;
}

TEST_CASE("Cadastro de Jogadores - Exceções") {
    cadastro c;

    Jogador* j1 = new Jogador("Bob", "B1", 0, 0, 0, 0);
    c.cadastrar(j1);

    // Teste de exceção ao tentar cadastrar jogador com o mesmo nome
    CHECK_THROWS_AS(c.cadastrar(new Jogador("Bob", "B2", 0, 0, 0, 0)), std::runtime_error);

    c.remover(j1);
    delete j1;
}
