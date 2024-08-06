#ifndef INTERFACE_JOGO_HPP
#define INTERFACE_JOGO_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <memory>
#include <array>
#include <cstdlib>

using namespace std;

class Interface_Jogo {
    public:
        Interface_Jogo(const std::string& nome_do_jogo);
        virtual ~Interface_Jogo() = default;

        void events();
        void run();
        void draw();

        virtual void set_Sprites() = 0;
        virtual void set_Image() = 0;
        virtual void logic() = 0;
        virtual int Start_Game_Interface(int linhas, int colunas) = 0;
        void Set_Janela();
        void Define_Dimensoes_Janela();
        void Centralizar_Janela();
        virtual void Set_Music() = 0;

    protected:
        int linhas, colunas, largura_quadrado, num_quadrados;
        int largura_janela, altura_janela;
        string nome_do_jogo;

        sf::Music som_jogo;

        unique_ptr<sf::RenderWindow> janela;
        sf::Texture texture;
        sf::Texture pieceTexture1;
        sf::Texture pieceTexture2;
        vector<sf::Sprite> sprites;
        vector<std::vector<int>> grid;

        shared_ptr<sf::Event> event; 
        int x, y, direcionador_x, direcionador_y;
};

#endif