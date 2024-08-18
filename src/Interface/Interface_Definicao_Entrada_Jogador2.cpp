#include "Interface_Definicao_Entrada_Jogador2.hpp"

void Interface_Definicao_Entrada_Jogador2::Set_Opcoes() {
    opcoes_de_escolha = {"Login", "Cadastro"};
}

void Interface_Definicao_Entrada_Jogador2::Set_Image() {
    try {
        if (!image->loadFromFile("./assets/Menu/Definicao_entrada_jogador2.png")) 
            cerr << "Erro ao carregar imagem de fundo" << endl;
        background->setTexture(*image); 
    } catch (const std::exception& e) {
        cerr << "Erro ao definir a imagem de fundo: " << e.what() << endl;
    }
}

void Interface_Definicao_Entrada_Jogador2::Definicoes_Espacamento_Janela() {
    this->espaco_vertical = 61.0f;
    this->largura_janela = 624.0f;
    this->altura_titulo = 271.0f; 
    this->altura_inferior_titulo = this->altura_titulo + 20.0f; 
}

void Interface_Definicao_Entrada_Jogador2::Set_Values(){
    Set_Janela();
    Set_Image();
    Definicoes_Espacamento_Janela();

    posicao = 0;
    pressed = seleção_ativa = false;
    Set_Opcoes();

    tamanho_fonte = {18, 18};
    textos.Set_Fonte(tamanho_fonte);
    textos.Set_Textos_Sem_Entrada(opcoes_de_escolha, largura_janela, altura_inferior_titulo, espaco_vertical);
    textos.Set_Contorno_Inicial_Texto();

    janela->setVerticalSyncEnabled(true);
}

void Interface_Definicao_Entrada_Jogador2::Loop_Events(){
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
            if (posicao == 0) {
                janela->close();
                login = make_unique<Interface_Login_Jogador2>();
                login->Run();
            } else if (posicao == 1) {
                janela->close();
                cadastro = make_unique<Interface_Cadastro_Jogador2>();
                cadastro->Run();
            } 
        }
    }
}