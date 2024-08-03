#ifndef INTERFACE_MENU_HPP
#define INTERFACE_MENU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

using namespace std;

class Interface_Menu {
    protected:
        int posicao, num_botoes, num_janela;
        bool pressed, theselect;

        unique_ptr<sf::RenderWindow> janela;
        unique_ptr<sf::RectangleShape> winclose;
        unique_ptr<sf::Font> font;
        unique_ptr<sf::Texture> image;
        unique_ptr<sf::Sprite> background;

        sf::Vector2i posicao_mouse;
        sf::Vector2f mouse_coord;

        sf::SoundBuffer buffer_selecao;
        sf::Sound som_selecao;

        vector<const char*> opcoes_de_escolha;
        vector<sf::Vector2f> coords;
        vector<sf::Text> texto;
        vector<size_t> tamanho_fonte;

        virtual void Set_Values() = 0;
        virtual void Loop_Events() = 0;
        virtual void Draw_All();

    public:
        Interface_Menu();
        virtual ~Interface_Menu();
        void Run_Menu();
        virtual void Set_Efeito_Sonoro_Selecao_Botao();
        virtual void Centralizar_Janela();
};

#endif