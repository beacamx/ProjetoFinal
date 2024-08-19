#ifndef INTERFACE_REMOVE_JOGADOR_HPP
#define INTERFACE_REMOVE_JOGADOR_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Interface_Menu.hpp"
#include "Caixa_de_texto.hpp"
#include "Cadastro_Jogadores.hpp"
#include "Jogador.hpp"

using namespace std;

class Interface_Remove_Jogador : public Interface_Menu {
    protected:
        Caixa_de_texto caixa_de_texto1;
        float altura_texto;

        void Set_Values() override;
        void Set_Opcoes() override; 
        void Set_Image() override;  
        void Set_Aviso() override;
        void Definicoes_Espacamento_Janela() override;
        void Loop_Events() override;
        void Atualizar_Janela() override;
    
    public:
        Interface_Remove_Jogador();
        ~Interface_Remove_Jogador(){};
};

#endif