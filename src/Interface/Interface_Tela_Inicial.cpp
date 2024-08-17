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
    opcoes_de_escolha = {"Jogar", "Dados"};
}

void Interface_Tela_Inicial::Definicoes_Espacamento_Janela() {
    this->espaco_vertical = 61.0f;
    this->largura_janela = 624.0f;
    this->altura_titulo = 271.0f; 
    this->altura_inferior_titulo = this->altura_titulo + 20.0f;
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
        Set_Image();
        janela->setVerticalSyncEnabled(true);
        Definicoes_Espacamento_Janela();
        Set_Opcoes();

        tamanho_fonte = {18, 18};
        textos.Set_Fonte(tamanho_fonte);
        textos.Set_Textos_Sem_Entrada(opcoes_de_escolha, largura_janela, altura_inferior_titulo, espaco_vertical);
        textos.Set_Contorno_Inicial_Texto();

        posicao = 0;
        pressed = seleção_ativa = false;   
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
                if(posicao < 1){
                    som_selecao.play();
                    ++posicao;
                    pressed = true;
                    textos.Set_Contorno_Texto_Avancar(posicao);
                    pressed = false;
                    seleção_ativa = false;
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
                if(posicao > 0){
                    som_selecao.play();
                    --posicao;
                    pressed = true;
                    textos.Set_Contorno_Texto_Voltar(posicao);
                    pressed = false;
                    seleção_ativa = false;
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !seleção_ativa) {
                seleção_ativa = true;

                if(posicao == 0) {
                    janela->close();
                    jogador1 = make_unique<Interface_Definicao_Entrada_Jogador1>();
                    jogador1->Run_Menu();
                } else if(posicao == 1) {
                    cout << "Em construçao... Vou fazer no sábado" << endl;
                    janela->close();
                } 
            }
        }
    } catch (const std::exception& e) {
        cerr << "Erro no loop de eventos da Tela Inicial: " << e.what() << endl;
    }
}

