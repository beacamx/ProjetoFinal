#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../libs/doctest/doctest.h"
#include "../include/Lig4.hpp"
#include "../include/Cadastro_Jogadores.hpp"

// Mock classes for testing
class MockCadastro : public cadastro {
public:
    MockCadastro() {
        // Adding dummy players for testing
        jogadores.push_back(Jogador("Alice"));
        jogadores.push_back(Jogador("Bob"));
    }

    Jogador* find_by_name(const std::string& name) override {
        for (auto& jogador : jogadores) {
            if (jogador.get_name() == name) {
                return &jogador;
            }
        }
        return nullptr;
    }
    
private:
    std::vector<Jogador> jogadores;
};

TEST_CASE("Lig4 initialization and functionality") {
    MockCadastro cadastro_jogadores;
    
    // Testing initialization of Lig4
    SUBCASE("Test Initialization") {
        Lig4 lig4(cadastro_jogadores, "Alice", "Bob", 6, 7);
        CHECK(lig4.getNumLinhas() == 6);
        CHECK(lig4.getNumColunas() == 7);

        // Check if the board is initialized to 0
        vector<vector<int>> expected_board(6, vector<int>(7, 0));
        CHECK(lig4.getTabuleiro() == expected_board);
    }
    
    // Testing making a valid move
    SUBCASE("Test Valid Move") {
        Lig4 lig4(cadastro_jogadores, "Alice", "Bob", 6, 7);
        lig4.fazerJogada(5, 3);
        CHECK(lig4.getTabuleiro()[5][3] == 1); // Assuming Alice's piece is 1
    }

    // Testing making an invalid move
    SUBCASE("Test Invalid Move") {
        Lig4 lig4(cadastro_jogadores, "Alice", "Bob", 6, 7);
        lig4.fazerJogada(6, 8); // Out of bounds
        CHECK(lig4.getTabuleiro()[0][8] == 0); // No change in the board
    }
    
    // Testing calculate available row
    SUBCASE("Test Calculate Available Row") {
        Lig4 lig4(cadastro_jogadores, "Alice", "Bob", 6, 7);
        lig4.fazerJogada(5, 3);
        CHECK(lig4.calcularLinhaDisponivel(3) == 4); // Row below the occupied one
    }

    // Testing calculating possible positions
    SUBCASE("Test Calculate Possible Positions") {
        Lig4 lig4(cadastro_jogadores, "Alice", "Bob", 6, 7);
        vector<pair<int, int>> posicoes = lig4.calcularPosicoesPossiveis();
        // Expected positions based on empty board should be all the positions in the bottom row
        CHECK(posicoes.size() == 7); // Should return 7 possible positions
    }

    // Testing victory condition
    SUBCASE("Test Victory Condition") {
        Lig4 lig4(cadastro_jogadores, "Alice", "Bob", 6, 7);
        // Simulate a winning condition
        for (int i = 0; i < 4; ++i) {
            lig4.fazerJogada(5, i);
        }
        lig4.testarVitoria();
        // Assuming the print statement does not interfere with the test
        CHECK(lig4.getJogoAtivo() == false); // Game should be over
    }
}
