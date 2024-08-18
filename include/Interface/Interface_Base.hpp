#ifndef INTERFACE_BASE_HPP
#define INTERFACE_BASE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

//#include "Classes_auxiliares/Audio.hpp"
#include "Classes_auxiliares/Avisos.hpp"
#include "Cadastro_Jogadores.hpp"
//#include "Audio.hpp"

using namespace std;

class Interface_Base {
    protected:
        unique_ptr<sf::RenderWindow> janela;
        unique_ptr<sf::RectangleShape> winclose;
        sf::Texture textura;

        //Audio audio;
        Avisos avisos;
        cadastro registro_geral;

        int largura_janela, altura_janela; 
        string mensagem_de_erro;
        string nome_jogador1, nome_jogador2;
        string apelido_jogador1, apelido_jogador2;
    public:
        Interface_Base(int largura, int altura) 
            : largura_janela(largura), altura_janela(altura) {
            this->janela = make_unique<sf::RenderWindow>();
            this->winclose = make_unique<sf::RectangleShape>();
            janela->setVerticalSyncEnabled(true);
            registro_geral.save();
            avisos.Set_Aviso();
        };
        ~Interface_Base(){};

        virtual void Run() = 0;
        virtual void Atualizar_Janela() = 0;

        void Centralizar_Janela();

};

#endif