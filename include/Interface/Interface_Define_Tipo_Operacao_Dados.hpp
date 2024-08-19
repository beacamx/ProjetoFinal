#ifndef INTERFACE_DEFINE_TIPO_OPERACAO_DADOS_HPP
#define INTERFACE_DEFINE_TIPO_OPERACAO_DADOS_JOGO_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "Interface_Menu.hpp"
#include "Cadastro_Jogadores.hpp"
#include "Interface_Remove_Jogador.hpp"

using namespace std;

class Interface_Define_Tipo_Operacao_Dados: public Interface_Menu {
    protected:
        void Set_Values() override;
        void Loop_Events() override;
 
    public:
        Interface_Define_Tipo_Operacao_Dados();
        ~Interface_Define_Tipo_Operacao_Dados(){};

        void Set_Image() override;  
        void Set_Opcoes() override;
        void Definicoes_Espacamento_Janela() override;
};

#endif
