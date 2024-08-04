#ifndef INTERFACE_CADASTRO_HPP
#define INTERFACE_CADASTRO_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Interface_Menu.hpp"
#include "Interface_Define_Jogo.hpp"
#include "Caixa_de_texto.hpp"

using namespace std;

class Interface_Cadastro: public Interface_Menu {
    protected:
        void Set_Values() override;
        void Loop_Events() override;
        void Draw_All() override;
        void Set_Opcoes() override; 
        void Set_Image() override;  
        void Set_Textos() override;
        unique_ptr<Interface_Define_Jogo> define_jogo;
    public:
        Interface_Cadastro();
        ~Interface_Cadastro() override;

        void Definicoes_Espacamento_Janela() override;
    private:
        Caixa_de_texto caixa_de_texto1;
        Caixa_de_texto caixa_de_texto2;
        float altura_texto;
};

#endif