#ifndef INTERFACE_JOGO_HPP
#define INTERFACE_JOGO_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>

#include "Interface_Base.hpp"
#include "Textos.hpp"

using namespace std;

class Interface_Jogo : public Interface_Base {
    public:
        Interface_Jogo(const string& nome_do_jogo);
        ~Interface_Jogo(){};

        void Eventos_Jogo();
        virtual void Atualizar_Janela() override;
        virtual void Set_Sprites() = 0;
        virtual void Set_Aviso() override;
        virtual void Run() override;
        virtual void Set_Textura_Sem_Peca() = 0;
        virtual void Set_Textura_Peca1() = 0;
        virtual void Set_Textura_Peca2() = 0;
        virtual void Logica() = 0;
        virtual void Set_Values() = 0;

        void Set_Janela();
        void Define_Dimensoes_Janela();

    protected:
        int linhas, colunas, largura_quadrado;
        vector<size_t> tamanho_fonte;
        Textos textos;
        string nome_do_jogo;

        sf::Texture textura_sem_peca;
        sf::Texture textura_peca1;
        sf::Texture textura_peca2;
        vector<sf::Sprite> sprites;
        vector<vector<int>> tabuleiro;

        shared_ptr<sf::Event> evento; 
        int x, y, direcionador_x, direcionador_y;
};

#endif