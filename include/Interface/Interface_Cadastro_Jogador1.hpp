#ifndef INTERFACE_CADASTRO_JOGADOR1_HPP
#define INTERFACE_CADASTRO_JOGADOR1_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Interface_Menu.hpp"
#include "Interface_Define_Jogo.hpp"
#include "Caixa_de_texto.hpp"
#include "Interface_Cadastro_Base.hpp"
#include "Cadastro_Jogadores.hpp"
#include "Troca_Definicao_Entrada_Jogador.hpp"
#include "jogador.hpp"

using namespace std;

class Interface_Cadastro_Jogador1: public Interface_Cadastro_Base {
    public:
        Interface_Cadastro_Jogador1();
        ~Interface_Cadastro_Jogador1(){};

    protected:
        virtual void Loop_Events() override;
};

#endif