#include "Interface_Definicao_Entrada_Jogador2.hpp"

using namespace std;

Interface_Definicao_Entrada_Jogador2::~Interface_Definicao_Entrada_Jogador2(){}

void Interface_Definicao_Entrada_Jogador2::Set_Opcoes() {
    opcoes_de_escolha = {"Login", "Cadastro"};
}

void Interface_Definicao_Entrada_Jogador2::Set_Image() {
    if (!image->loadFromFile("./assets/Menu/Definicao_entrada_jogador2.png")) 
        cerr << "Erro ao carregar imagem de fundo" << endl;
    background->setTexture(*image);
}

void Interface_Definicao_Entrada_Jogador2::Definicoes_Espacamento_Janela() {
    this->espaco_vertical = 61.0f;
    this->largura_janela = 624.0f;
    this->altura_titulo = 271.0f; 
    this->altura_inferior_titulo = this->altura_titulo + 20.0f; 
}

void Interface_Definicao_Entrada_Jogador2::Set_Values(){
    Set_Efeito_Sonoro_Selecao_Botao();
    Set_Janela();
    Centralizar_Janela();
    Definir_Fonte();
    Set_Image();

    posicao = 0;
    pressed = theselect = false;
    coords.clear();
    
    Definicoes_Espacamento_Janela();
    Set_Opcoes();
    Set_Textos();
    Set_Contorno_Inicial();
}

void Interface_Definicao_Entrada_Jogador2::Loop_Events(){
    sf::Event evento;

    int tam_vetor_texto = texto.size();
    while(janela->pollEvent(evento)) {
        if ((evento.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
            janela->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
            som_selecao.play();
            if(posicao < tam_vetor_texto - 1){
                ++posicao;
                pressed = true;
                Set_Contorno_Avancar(posicao);
                pressed = false;
                theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
            som_selecao.play();
            if(posicao > 0){
                --posicao;
                pressed = true;
                Set_Contorno_Voltar(posicao);
                pressed = false;
                theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
            theselect = true;
            if (posicao == 0) {
                janela->close();
                login = make_unique<Interface_Login_Jogador2>();
                login->Run_Menu();
            } else if (posicao == 1) {
                janela->close();
                cadastro = make_unique<Interface_Cadastro_Jogador2>();
                cadastro->Run_Menu();
            } 
        }
    }
}