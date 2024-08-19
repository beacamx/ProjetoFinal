#ifndef INTERFACE_LOGIN_JOGADOR1_HPP
#define INTERFACE_LOGIN_JOGADOR1_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Interface_Menu.hpp"
#include "Interface_Define_Jogo.hpp"
#include "Classes_auxiliares/Caixa_de_texto.hpp"
#include "Cadastro_Jogadores.hpp"
#include "Interface_Login_Base.hpp"
#include "Jogador.hpp"

using namespace std;

class Interface_Login_Jogador1: public Interface_Login_Base {
    public:
        Interface_Login_Jogador1();
        ~Interface_Login_Jogador1(){};

    protected:
        virtual void Loop_Events() override;

    private:
        unique_ptr<Interface_Define_Jogo> define_jogo;
};

#endif