#include "Interface_Define_Jogo.hpp"

using namespace std;

Interface_Define_Jogo::Interface_Define_Jogo(){
    Set_Values();
}

Interface_Define_Jogo::~Interface_Define_Jogo(){}

void Interface_Define_Jogo::Set_Opcoes() {
    opcoes_de_escolha = {"Lig4", "Reversi"};
}

void Interface_Define_Jogo::Definicoes_Espacamento_Janela() {
    this->espaco_vertical = 61.0f;
    this->largura_janela = 624.0f;
    this->altura_titulo = 271.0f; 
    this->altura_inferior_titulo = this->altura_titulo + 20.0f; 
}

void Interface_Define_Jogo::Set_Image() {
    if (!image->loadFromFile("./assets/Menu/Selecao_Jogo.png")) 
        cerr << "Erro ao carregar imagem de fundo" << endl;
    background->setTexture(*image);
}

void Interface_Define_Jogo::Set_Values(){
    Set_Efeito_Sonoro_Selecao_Botao();
    Set_Janela();
    Centralizar_Janela();
    Set_Font();
    Set_Image();

    posicao = 0;
    pressed = theselect = false;   
    coords.clear();

    Definicoes_Espacamento_Janela();
    Set_Opcoes();
    Set_Textos();
    Set_Contorno_Inicial();
}

void Interface_Define_Jogo::Loop_Events(){
    sf::Event evento;
    while(janela->pollEvent(evento)) {
        if ((evento.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
            janela->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
            if(posicao < 1){
                som_selecao.play();
                ++posicao;
                pressed = true;
                Set_Contorno_Avancar(posicao);
                pressed = false;
                theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
            if(posicao > 0){
                som_selecao.play();
                --posicao;
                pressed = true;
                Set_Contorno_Voltar(posicao);
                pressed = false;
                theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
            theselect = true;

            if(posicao == 0) {
                janela->close();
                dimensao = make_unique<Interface_Define_Dimensao>("Lig4");
                dimensao->Run_Menu();
            } else if(posicao == 1) {
                janela->close();
                dimensao = make_unique<Interface_Define_Dimensao>("Reversi");
                dimensao->Run_Menu();
            }
        }
    }
}

