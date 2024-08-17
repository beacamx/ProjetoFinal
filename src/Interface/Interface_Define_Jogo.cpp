#include "Interface_Define_Jogo.hpp"

using namespace std;

Interface_Define_Jogo::Interface_Define_Jogo() : Interface_Menu() {
    try {
        Set_Values();
    } catch (const std::exception& e) {
        cerr << "Erro na inicialização da interface de definição do jogo: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

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
    try {
        if (!image->loadFromFile("./assets/Menu/Selecao_Jogo.png")) 
            cerr << "Erro ao carregar imagem de fundo" << endl;
        background->setTexture(*image);
    } catch (const std::exception& e) {
        cerr << "Erro ao definir a imagem de fundo: " << e.what() << endl;
    }
}

void Interface_Define_Jogo::Set_Values(){
    Set_Efeito_Sonoro_Selecao_Botao();
    Set_Janela();
    Set_Opcoes();
    Set_Image();
    Definicoes_Espacamento_Janela();

    posicao = 0;
    pressed = seleção_ativa = false;   

    tamanho_fonte = {18, 18};
    textos.Set_Fonte(tamanho_fonte);
    textos.Set_Textos_Sem_Entrada(opcoes_de_escolha, largura_janela, altura_inferior_titulo, espaco_vertical);
    textos.Set_Contorno_Inicial_Texto();

    janela->setVerticalSyncEnabled(true);
}

void Interface_Define_Jogo::Loop_Events(){
    sf::Event evento;
    int tam_vetor_texto = textos.Get_Tamanho_Vetor_Textos();

    while(janela->pollEvent(evento)) {
        if ((evento.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
            janela->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
            if(posicao < tam_vetor_texto - 1){
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
                dimensao = make_unique<Interface_Define_Dimensao>("Lig4");
                dimensao->Run();
            } else if(posicao == 1) {
                janela->close();
                dimensao = make_unique<Interface_Define_Dimensao>("Reversi");
                dimensao->Run();
            }
        }
    }
}

