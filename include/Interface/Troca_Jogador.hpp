#ifndef TROCA_JOGADOR_HPP
#define TROCA_JOGADOR_HPP

#include <memory>
#include "Interface_Definicao_Entrada_Jogador2.hpp"
#include "Interface_Menu.hpp"

class Troca_Jogador : public Interface_Menu {
public:
    void Troca_Definicao_Jogador();
    Troca_Jogador();
    ~Troca_Jogador();

private:
    static std::unique_ptr<Interface_Definicao_Entrada_Jogador2> jogador2;
};

#endif
