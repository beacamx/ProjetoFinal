#ifndef INTERFACE_MENU_HPP
#define INTERFACE_MENU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "Cadastro_Jogadores.hpp"
#include "Textos.hpp"

using namespace std;

class Interface_Menu {
    protected:
        int posicao, num_botoes, num_janela;
        bool pressed, seleção_ativa;

        sf::Clock clock_aviso;
        bool mostrar_aviso = false;

        unique_ptr<sf::RenderWindow> janela;
        unique_ptr<sf::RectangleShape> winclose;
        unique_ptr<sf::Texture> image;
        unique_ptr<sf::Sprite> background;

        sf::Vector2i posicao_mouse;
        sf::Vector2f mouse_coord;

        sf::SoundBuffer buffer_selecao;
        sf::Sound som_selecao;

        sf::Text aviso;

        vector<const char*> opcoes_de_escolha;
        vector<sf::Vector2f> coords_copia;

        virtual void Set_Values() = 0;
        virtual void Loop_Events() = 0;
        virtual void Draw_All();
        virtual void Set_Opcoes() = 0;
        virtual void Definicoes_Espacamento_Janela() = 0;
        
        virtual void Set_Image() = 0;
        virtual void Set_Efeito_Sonoro_Selecao_Botao();

        float espaco_vertical;
        float espaco_vertical_botao_play;
        float largura_janela;
        float altura_titulo; 
        float altura_inferior_titulo; 

        cadastro registro_geral;
        vector<size_t> tamanho_fonte;
        Textos textos;

    public:
        Interface_Menu();
        virtual ~Interface_Menu();
        void Run_Menu();
        void Set_Janela();
        void Centralizar_Janela();
        virtual void Define_Aviso();
};

#endif