#ifndef INTERFACE_LOGIN_JOGADOR2_HPP
#define INTERFACE_LOGIN_JOGADOR2_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Interface_Menu.hpp"
#include "Interface_Define_Jogo.hpp"
#include "Classes_auxiliares/Caixa_de_texto.hpp"
#include "Cadastro_Jogadores.hpp"
#include "jogador.hpp"

using namespace std;

class Interface_Login_Jogador2: public Interface_Menu {
    protected:
        void Set_Values() override;
        void Loop_Events() override;
        void Atualizar_Janela() override;
        void Set_Opcoes() override; 
        void Set_Image() override;  
        void Define_Aviso() override;
        unique_ptr<Interface_Define_Jogo> define_jogo;
    public:
        Interface_Login_Jogador2();
        ~Interface_Login_Jogador2(){};

        void Definicoes_Espacamento_Janela() override;
    private:
        Caixa_de_texto caixa_de_texto1;
        float altura_texto;
};

#endif