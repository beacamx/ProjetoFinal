#ifndef INTERFACE_MENU_HPP
#define INTERFACE_MENU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "Cadastro_Jogadores.hpp"
#include "Interface_Base.hpp"
#include "Textos.hpp"

using namespace std;

class Interface_Menu: public Interface_Base  {
    protected:
        int posicao, num_botoes, num_janela;
        bool pressed, seleção_ativa;

        unique_ptr<sf::Texture> image;
        unique_ptr<sf::Sprite> background;

        sf::Vector2i posicao_mouse;
        sf::Vector2f mouse_coord;

        vector<const char*> opcoes_de_escolha;
        vector<sf::Vector2f> coords_copia;

        virtual void Set_Values() = 0;
        virtual void Loop_Events() = 0;
        virtual void Atualizar_Janela() override;
        virtual void Set_Opcoes() = 0;
        virtual void Definicoes_Espacamento_Janela() = 0;
        
        virtual void Set_Image() = 0;

        float espaco_vertical;
        float espaco_vertical_botao_play;
        float altura_titulo; 
        float altura_inferior_titulo; 

        cadastro registro_geral;
        vector<size_t> tamanho_fonte;
        Textos textos;

    public:
        Interface_Menu();
        ~Interface_Menu() {};
        void Run() override;
        void Set_Janela();
};

#endif