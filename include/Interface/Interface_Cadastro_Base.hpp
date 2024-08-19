#ifndef INTERFACE_CADASTRO_BASE_HPP
#define INTERFACE_CADASTRO_BASE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Interface_Menu.hpp"
#include "Interface_Define_Jogo.hpp"
#include "Classes_auxiliares/Caixa_de_texto.hpp"
#include "Cadastro_Jogadores.hpp"
#include "jogador.hpp"

using namespace std;

class Interface_Cadastro_Base: public Interface_Menu {
    protected:
        unique_ptr<Interface_Define_Jogo> define_jogo;
        Caixa_de_texto caixa_de_texto1;
        Caixa_de_texto caixa_de_texto2;
        float altura_texto;

        virtual void Set_Values() override;
        virtual void Set_Opcoes() override; 
        virtual void Set_Image() override;  
        virtual void Set_Aviso() override;
        virtual void Definicoes_Espacamento_Janela() override;
        virtual void Loop_Events() override = 0;
        virtual void Atualizar_Janela() override;

    public:
        Interface_Cadastro_Base();
};

#endif
