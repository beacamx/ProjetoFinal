#ifndef INTERFACE_CADASTRO_JOGADOR1_HPP
#define INTERFACE_CADASTRO_JOGADOR1_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Interface_Menu.hpp"
#include "Interface_Define_Jogo.hpp"
#include "Classes_auxiliares/Caixa_de_texto.hpp"
#include "Cadastro_Jogadores.hpp"
#include "jogador.hpp"

using namespace std;

class Interface_Cadastro_Jogador1: public Interface_Menu {
    protected:
        void Set_Values() override;
        void Loop_Events() override;
        void Draw_All() override;
        void Set_Opcoes() override; 
        void Set_Image() override;  
        void Define_Aviso() override;
    public:
        Interface_Cadastro_Jogador1();
        ~Interface_Cadastro_Jogador1() override;

        void Definicoes_Espacamento_Janela() override;
    private:
        Caixa_de_texto caixa_de_texto1;
        Caixa_de_texto caixa_de_texto2;
        cadastro registro_geral;
        float altura_texto;
};

#endif