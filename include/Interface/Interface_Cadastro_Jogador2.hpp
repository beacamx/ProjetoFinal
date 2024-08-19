#ifndef INTERFACE_CADASTRO_JOGADOR2_HPP
#define INTERFACE_CADASTRO_JOGADOR2_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "Interface_Menu.hpp"
#include "Interface_Cadastro_Base.hpp"
#include "Interface_Define_Jogo.hpp"
#include "Caixa_de_texto.hpp"
#include "Cadastro_Jogadores.hpp"
#include "jogador.hpp"

using namespace std;

class Interface_Cadastro_Jogador2: public Interface_Cadastro_Base {
    public:
        Interface_Cadastro_Jogador2();
        ~Interface_Cadastro_Jogador2(){};
    protected:
        unique_ptr<Interface_Define_Jogo> define_jogo;
        virtual void Loop_Events() override;
};

#endif