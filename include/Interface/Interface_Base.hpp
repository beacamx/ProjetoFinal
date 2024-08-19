#ifndef INTERFACE_BASE_HPP
#define INTERFACE_BASE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>

//#include "Audio.hpp"
#include "Avisos.hpp"
#include "Cadastro_Jogadores.hpp"
#include "Jogador.hpp"

using namespace std;

class Interface_Base {
    protected:
        unique_ptr<sf::RenderWindow> janela;
        unique_ptr<sf::RectangleShape> winclose;
        sf::Texture textura;

        sf::Clock clock_aviso;
        bool mostrar_aviso = false;
        sf::Text aviso;

        //Audio audio;
        Avisos avisos;
        static cadastro registro_geral;

        int largura_janela, altura_janela; 
        string mensagem_de_erro;
        string nome_jogador1, nome_jogador2;
        string apelido_jogador1, apelido_jogador2;
        static cadastro& Get_Registro_Geral();
    public:
        Interface_Base(int largura, int altura);
        ~Interface_Base(){};

        virtual void Run() = 0;
        virtual void Atualizar_Janela() = 0;
        virtual void Set_Aviso() = 0;
        void Centralizar_Janela();
};

#endif