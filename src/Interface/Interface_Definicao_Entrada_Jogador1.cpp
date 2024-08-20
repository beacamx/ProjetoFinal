#include "Interface_Definicao_Entrada_Jogador1.hpp"

void Interface_Definicao_Entrada_Jogador1::Set_Opcoes() {
    opcoes_de_escolha = {"Login", "Cadastro"};
}

void Interface_Definicao_Entrada_Jogador1::Set_Image() {
    try {
        if (!image->loadFromFile("./assets/Menu/Definicao_entrada_jogador1.png")) 
            cerr << "Erro ao carregar imagem de fundo" << endl;
        background->setTexture(*image);
    } catch (const std::exception& e) {
        cerr << "Erro ao definir a imagem de fundo: " << e.what() << endl;
    }
}

void Interface_Definicao_Entrada_Jogador1::Definicoes_Espacamento_Janela() {
    this->espaco_vertical = 61.0f;
    this->largura_janela = 624.0f;
    this->altura_titulo = 271.0f; 
    this->altura_inferior_titulo = this->altura_titulo + 20.0f; 
}

void Interface_Definicao_Entrada_Jogador1::Set_Values(){
    Set_Janela();
    Set_Image();
    Definicoes_Espacamento_Janela();
    Set_Opcoes();
    posicao = 0;
    pressed = seleção_ativa = false;

    tamanho_fonte = {18, 18};
    textos.Set_Fonte(tamanho_fonte);
    textos.Set_Textos_Sem_Entrada(opcoes_de_escolha, largura_janela, altura_inferior_titulo, espaco_vertical);
    textos.Set_Contorno_Inicial_Texto();
}

void Interface_Definicao_Entrada_Jogador1::Loop_Events(){
    sf::Event evento;
    int tam_vetor_texto = textos.Get_Tamanho_Vetor_Textos();
    
    while(janela->pollEvent(evento)) {
        if ((evento.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
            janela->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
            if(posicao < tam_vetor_texto - 1){
                ++posicao;
                pressed = true;
                textos.Set_Contorno_Texto_Avancar(posicao);
                pressed = false;
                seleção_ativa = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
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
                login = make_unique<Interface_Login_Jogador1>();
                login->Run();
            } else if (posicao == 1) {
                janela->close();
                cadastro = make_unique<Interface_Cadastro_Jogador1>();
                cadastro->Run();          
            }
        }
    }
}

