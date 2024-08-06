#ifndef INTERFACE_JOGO_HPP
#define INTERFACE_JOGO_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>

using namespace std;

class Interface_Jogo {
    public:
        Interface_Jogo(const std::string& nome_do_jogo);
        virtual ~Interface_Jogo() = default;

        void Eventos_Jogo();
        void Run_Interface_Jogo();
        void Atualizar_Janela_Jogo();

        virtual void Set_Sprites() = 0;
        virtual void Set_Music() = 0;
        virtual void Set_Textura_Sem_Peca() = 0;
        virtual void Set_Textura_Peca1() = 0;
        virtual void Set_Textura_Peca2() = 0;
        virtual void logic() = 0;
        virtual int Start_Game_Interface(int linhas, int colunas) = 0;

        void Set_Janela();
        void Define_Dimensoes_Janela();
        void Centralizar_Janela();

    protected:
        int linhas, colunas, largura_quadrado;
        int largura_janela, altura_janela;
        string nome_do_jogo;

        sf::Music som_jogo;

        unique_ptr<sf::RenderWindow> janela;
        sf::Texture textura;
        sf::Texture textura_peca1;
        sf::Texture textura_peca2;
        vector<sf::Sprite> sprites;
        vector<vector<int>> tabuleiro;

        shared_ptr<sf::Event> evento; 
        int x, y, direcionador_x, direcionador_y;
};

#endif