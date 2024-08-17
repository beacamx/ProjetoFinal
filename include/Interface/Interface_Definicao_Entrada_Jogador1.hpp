#ifndef INTERFACE_DEFINICAO_ENTRADA_JOGADOR1_HPP
#define INTERFACE_DEFINICAO_ENTRADA_JOGADOR1_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>

#include "Interface_Menu.hpp"
#include "Interface_Login_Jogador1.hpp"
#include "Interface_Cadastro_Jogador1.hpp"

using namespace std;

class Interface_Definicao_Entrada_Jogador1: public Interface_Menu {
    protected:
        void Set_Values() override;
        void Loop_Events() override;
        unique_ptr<Interface_Login_Jogador1> login;
        unique_ptr<Interface_Cadastro_Jogador1> cadastro;
 
    public:
        Interface_Definicao_Entrada_Jogador1() : Interface_Menu() { Set_Values(); }
        ~Interface_Definicao_Entrada_Jogador1(){};

        void Set_Image() override;
        void Set_Opcoes() override;
        void Definicoes_Espacamento_Janela() override;
};

#endif