#ifndef INTERFACE_DEFINICAO_ENTRADA_JOGADOR2_HPP
#define INTERFACE_DEFINICAO_ENTRADA_JOGADOR2_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>

#include "Interface_Menu.hpp"
#include "Interface_Login_Jogador2.hpp"
#include "Interface_Cadastro_Jogador2.hpp"

using namespace std;

class Interface_Definicao_Entrada_Jogador2: public Interface_Menu {
    protected:
        void Set_Values() override;
        void Loop_Events() override;
        unique_ptr<Interface_Login_Jogador2> login;
        unique_ptr<Interface_Cadastro_Jogador2> cadastro;
 
    public:
        Interface_Definicao_Entrada_Jogador2() : Interface_Menu() { Set_Values(); }
        ~Interface_Definicao_Entrada_Jogador2();

        void Set_Image() override;
        void Set_Opcoes() override;
        void Definicoes_Espacamento_Janela() override;
};

#endif