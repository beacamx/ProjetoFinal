#include "Interface_Define_Dimensao.hpp"

void Interface_Define_Dimensao::Set_Opcoes() {
    if (nome_jogo == "Lig4") {
        opcoes_de_escolha = {"6x7", "7x8", "8x9"};
    } else if (nome_jogo == "Reversi") {
        opcoes_de_escolha = {"8x8", "9x9", "10x10"};
    } 
}

void Interface_Define_Dimensao::Set_Image() {
    try {
        if (!image->loadFromFile("./assets/Menu/Selecao_Dimensao.png")) 
            cerr << "Erro ao carregar imagem de fundo" << endl;
        background->setTexture(*image);
    } catch (const std::exception& e) {
        cerr << "Erro ao definir a imagem de fundo: " << e.what() << endl;
    }
}

void Interface_Define_Dimensao::Definicoes_Espacamento_Janela() {
    this->espaco_vertical = 61.0f;
    this->largura_janela = 624.0f;
    this->altura_titulo = 271.0f; 
    this->altura_inferior_titulo = this->altura_titulo + 20.0f; 
}

void Interface_Define_Dimensao::Set_Values(){
    Set_Janela();
    Set_Opcoes();
    Set_Image();
    Definicoes_Espacamento_Janela();

    posicao = 0;
    pressed = seleção_ativa = false;

    tamanho_fonte = {18, 18, 18};
    textos.Set_Fonte(tamanho_fonte);
    textos.Set_Textos_Sem_Entrada(opcoes_de_escolha, largura_janela, altura_inferior_titulo, espaco_vertical);
    textos.Set_Contorno_Inicial_Texto();
}

void Interface_Define_Dimensao::Loop_Events(){
    sf::Event evento;
    int tam_vetor_texto = textos.Get_Tamanho_Vetor_Textos();

    while(janela->pollEvent(evento)) {
        if ((evento.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
            janela->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
            //audio.Play_Efeito_Sonoro_Selecao_Botao();
            if(posicao < tam_vetor_texto - 1){
                ++posicao;
                pressed = true;
                textos.Set_Contorno_Texto_Avancar(posicao);
                pressed = false;
                seleção_ativa = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
            //audio.Play_Efeito_Sonoro_Selecao_Botao();
            if(posicao > 0){
                --posicao;
                pressed = true;
                textos.Set_Contorno_Texto_Voltar(posicao);
                pressed = false;
                seleção_ativa = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !seleção_ativa) {
            seleção_ativa = true;

            if (nome_jogo == "Lig4") {
                if (posicao == 0) {
                    janela->close();
                    num_linhas = 6;
                    num_colunas = 7;
                    jogo = make_unique<Interface_Lig4>();
                    jogo->Start_Game_Interface(num_linhas, num_colunas);
                } else if (posicao == 1) {
                    janela->close();
                    num_linhas = 7;
                    num_colunas = 8;
                    jogo = make_unique<Interface_Lig4>();
                    jogo->Start_Game_Interface(num_linhas, num_colunas);
                } else if (posicao == 2) {
                    janela->close();
                    num_linhas = 8;
                    num_colunas = 9;
                    jogo = make_unique<Interface_Lig4>();
                    jogo->Start_Game_Interface(num_linhas, num_colunas);
                }
            } else if (nome_jogo == "Reversi") {
                if (posicao == 0) {
                    janela->close();
                    num_linhas = 8;
                    num_colunas = 8;
                    jogo = make_unique<Interface_Reversi>();
                    jogo->Start_Game_Interface(num_linhas, num_colunas);
                } else if (posicao == 1) {
                    janela->close();
                    num_linhas = 9;
                    num_colunas = 9;
                    jogo = make_unique<Interface_Reversi>();
                    jogo->Start_Game_Interface(num_linhas, num_colunas);
                } else if (posicao == 2) {
                    janela->close();
                    num_linhas = 10;
                    num_colunas = 10;
                    jogo = make_unique<Interface_Reversi>();
                    jogo->Start_Game_Interface(num_linhas, num_colunas);
                }
            }
        }
    }
}