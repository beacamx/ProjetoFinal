#ifndef INTERFACE_LOGIN_JOGADOR2_HPP
#define INTERFACE_LOGIN_JOGADOR2_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "Interface_Menu.hpp"
#include "Interface_Define_Jogo.hpp"
#include "Caixa_de_texto.hpp"
#include "Cadastro_Jogadores.hpp"
#include "Interface_Login_Base.hpp"
#include "Jogador.hpp"

class Interface_Login_Jogador2: public Interface_Login_Base {
    public:
        Interface_Login_Jogador2();
        ~Interface_Login_Jogador2(){};
        
    protected:
        virtual void Loop_Events() override;

    private:
        unique_ptr<Interface_Define_Jogo> define_jogo;
};

#endif