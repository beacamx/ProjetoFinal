#ifndef INTERFACE_CADASTRO_JOGADOR_BASE_HPP
#define INTERFACE_CADASTRO_JOGADOR_BASE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Interface_Menu.hpp"
#include "Interface_Define_Jogo.hpp"
#include "Classes_auxiliares/Caixa_de_texto.hpp"
#include "Cadastro_Jogadores.hpp"
#include "jogador.hpp"

using namespace std;

class Interface_Cadastro_Jogador_Base: public Interface_Menu {
    protected:
        Caixa_de_texto caixa_de_texto1;
        Caixa_de_texto caixa_de_texto2;
        unique_ptr<Interface_Define_Jogo> define_jogo;
        cadastro registro_geral;
        float altura_texto;

        void Set_Values() override;
        void Loop_Events() override;
        void Atualizar_Janela() override;
        void Set_Opcoes() override; 
        void Set_Image() override;  
        void Set_Aviso() override;

    public:
        Interface_Cadastro_Jogador_Base();
        virtual ~Interface_Cadastro_Jogador_Base() {};
        virtual void Definicoes_Espacamento_Janela() override = 0;
};

#endif