#include "Interface_Login.hpp"

using namespace std;

Interface_Login::Interface_Login(){
    Set_Values();
}

Interface_Login::~Interface_Login(){}

void Interface_Login::Set_Values(){
    if (!janela || !font || !image || !background) {
        cerr << "Erro: recursos não inicializados corretamente." << endl;
        return;
    }

    janela->create(sf::VideoMode(624,546), "", sf::Style::Titlebar | sf::Style::Close);
    janela->setPosition(sf::Vector2i(0,0));

    posicao_mouse = {0,0};
    mouse_coord = {0,0};
}

void Interface_Login::Loop_Events(){
    sf::Event evento;
    while(janela->pollEvent(evento)) {
        if(evento.type == sf::Event::Closed) {
            janela->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            janela->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
            janela->close();
            /* 
                chama funcao para verificar se o jogador existe
                se nao existir, mostra um aviso
                se existir, define o jogador que vai jogar
            */
            theselect = true;
            define_jogo = make_unique<Interface_Define_Jogo>();
            define_jogo->Run_Menu();
        }
    }
}

