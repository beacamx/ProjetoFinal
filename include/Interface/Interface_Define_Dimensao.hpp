#ifndef INTERFACE_DEFINE_DIMENSAO_HPP
#define INTERFACE_DEFINE_DIMENSAO_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>

#include "Interface_Menu.hpp"
#include "Interface_Jogo.hpp"
#include "Interface_Lig4.hpp"
#include "Interface_Reversi.hpp"

using namespace std;

class Interface_Define_Dimensao: public Interface_Menu {
    protected:
        void Set_Values() override;
        void Loop_Events() override;
        unique_ptr<Interface_Jogo> jogo;
 
    public:
        Interface_Define_Dimensao(const std::string& jogo) : nome_jogo(jogo) { Set_Values(); }
        ~Interface_Define_Dimensao() override;

        void Set_Image() override;
        void Set_Opcoes() override;
        void Definicoes_Espacamento_Janela() override;

    private:
        string nome_jogo;
        int num_linhas, num_colunas;
};

#endif