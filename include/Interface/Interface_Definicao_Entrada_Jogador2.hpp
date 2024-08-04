#ifndef INTERFACE_DEFINICAO_ENTRADA_JOGADOR2_HPP
#define INTERFACE_DEFINICAO_ENTRADA_JOGADOR2_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>

#include "Interface_Menu.hpp"
#include "Interface_Login.hpp"
#include "Interface_Cadastro.hpp"

using namespace std;

class Interface_Definicao_Entrada_Jogador2: public Interface_Menu {
    protected:
        void Set_Values() override;
        void Loop_Events() override;
        unique_ptr<Interface_Login> login;
        unique_ptr<Interface_Cadastro> cadastro;
 
    public:
        Interface_Definicao_Entrada_Jogador2() { Set_Values(); }
        ~Interface_Definicao_Entrada_Jogador2();

        void Set_Image() override;
        void Set_Opcoes() override;
        void Definicoes_Espacamento_Janela() override;

    private:
        string nome_jogo;
        int num_linhas, num_colunas;
};

#endif