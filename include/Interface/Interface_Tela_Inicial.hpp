#ifndef INTERFACE_TELA_INICIAL_HPP
#define INTERFACE_TELA_INICIAL_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>

#include "Interface_Menu.hpp"
#include "Interface_Definicao_Entrada_Jogador1.hpp"
#include "Interface_Define_Tipo_Operacao_Dados.hpp"

using namespace std;

class Interface_Tela_Inicial: public Interface_Menu {
    protected:
        void Set_Values() override;
        void Loop_Events() override;
        unique_ptr<Interface_Definicao_Entrada_Jogador1> jogador1;
        unique_ptr<Interface_Define_Tipo_Operacao_Dados> dados;
 
    public:
        Interface_Tela_Inicial();
        ~Interface_Tela_Inicial(){};

        void Set_Image() override;
        void Set_Opcoes() override;
        void Definicoes_Espacamento_Janela() override;
};

#endif
