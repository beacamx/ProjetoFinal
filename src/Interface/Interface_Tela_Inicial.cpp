#include "Interface_Tela_Inicial.hpp"

using namespace std;

Interface_Tela_Inicial::Interface_Tela_Inicial(){
    try {
        Set_Values();
    } catch (const std::exception& e) {
        cerr << "Erro na inicialização da tela inicial: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

Interface_Tela_Inicial::~Interface_Tela_Inicial(){}

void Interface_Tela_Inicial::Set_Opcoes() {
    opcoes_de_escolha = {"Jogar", "Dados", "Manual"};
}

void Interface_Tela_Inicial::Definicoes_Espacamento_Janela() {
    try {
        this->espaco_vertical = 61.0f;
        this->largura_janela = 624.0f;
        this->altura_titulo = 271.0f; 
        this->altura_inferior_titulo = this->altura_titulo + 20.0f;
    } catch (const std::exception& e) {
        cerr << "Erro ao definir espaçamento da janela: " << e.what() << endl;
    }
}

void Interface_Tela_Inicial::Set_Image() {
     try {
        if (!image->loadFromFile("./assets/Menu/Tela_Inicial.png")) 
            throw runtime_error("Erro ao carregar imagem de fundo");

        background->setTexture(*image);
    } catch (const std::exception& e) {
        cerr << "Erro na configuração da imagem: " << e.what() << endl;
    }
}

void Interface_Tela_Inicial::Set_Values(){
    try {
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
        Definir_Textos();
        Definir_Contorno_Inicial_Texto();
    } catch (const std::exception& e) {
        cerr << "Erro ao definir valores iniciais: " << e.what() << endl;
        throw;
    }
}

void Interface_Tela_Inicial::Loop_Events(){
    sf::Event evento;
    try {
        while(janela->pollEvent(evento)) {
            if ((evento.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
                janela->close();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
                if(posicao < 2){
                    som_selecao.play();
                    ++posicao;
                    pressed = true;
                    Definir_Contorno_Texto_Avancar(posicao);
                    pressed = false;
                    theselect = false;
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
                if(posicao > 0){
                    som_selecao.play();
                    --posicao;
                    pressed = true;
                    Definir_Contorno_Texto_Voltar(posicao);
                    pressed = false;
                    theselect = false;
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
                theselect = true;

                if(posicao == 0) {
                    janela->close();
                    jogador1 = make_unique<Interface_Definicao_Entrada_Jogador1>();
                    jogador1->Run_Menu();
                } else if(posicao == 1) {
                    janela->close();
                } else if(posicao == 2) {
                    janela->close();
                }
            }
        }
    } catch (const std::exception& e) {
        cerr << "Erro no loop de eventos: " << e.what() << endl;
    }
}

