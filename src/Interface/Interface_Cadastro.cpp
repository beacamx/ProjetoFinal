#include "Interface_Cadastro.hpp"

using namespace std;

Interface_Cadastro::Interface_Cadastro()
    : define_jogo(nullptr), caixa_de_texto1(15, sf::Color::White, false), caixa_de_texto2(15, sf::Color::White, false) {
    Set_Values();
}

Interface_Cadastro::~Interface_Cadastro(){}

void Interface_Cadastro::Set_Opcoes() {
    opcoes_de_escolha = {"Digitar apelido", "Digitar nome", "Cadastrar"};
}

void Interface_Cadastro::Set_Textos() {
    tamanho_fonte = {22, 22, 17};

    for (size_t i = 0; i < opcoes_de_escolha.size(); ++i) {
        float pos_y = altura_texto + (i * espaco_vertical);
        coords.push_back(sf::Vector2f(largura_janela / 2, pos_y));
    }

    texto.resize(opcoes_de_escolha.size());

    for(size_t i{}; i < texto.size(); ++i) {
        texto[i].setFont(*font);
        texto[i].setString(opcoes_de_escolha[i]);
        texto[i].setCharacterSize(tamanho_fonte[i]);
        texto[i].setOutlineColor(sf::Color::Black);
        texto[i].setPosition(coords[i]);

        sf::FloatRect text_bounds = texto[i].getLocalBounds();
        float largura_texto = text_bounds.width;
        float altura_texto = text_bounds.height;

        texto[i].setOrigin(largura_texto / 2.0f, altura_texto / 2.0f);
        texto[i].setPosition(coords[i].x, coords[i].y);
    }

}

void Interface_Cadastro::Set_Image() {
    if (!image->loadFromFile("./assets/Menu/Cadastro.png")) 
        cerr << "Erro ao carregar imagem de fundo" << endl;

    background->setTexture(*image);
} 

void Interface_Cadastro::Definicoes_Espacamento_Janela() {
    espaco_vertical = 95.0f;
    largura_janela = 624.0f;
    altura_texto = 244.0f; 
}

void Interface_Cadastro::Set_Values(){
    Set_Efeito_Sonoro_Selecao_Botao();
    Set_Font();
    Set_Janela();
    Centralizar_Janela();
    Set_Image();
    Set_Opcoes();

    posicao = 0;
    pressed = theselect = false;
    
    Definicoes_Espacamento_Janela();

    coords.clear();

    Set_Textos();
    Set_Contorno_Inicial();

    float largura_caixa = 120.0f;
    float espaco_adicional_entre_caixa_apelido = 16.0f;

    float posicao_x_caixa_texto = (largura_janela - largura_caixa) / 2;
    float posicao_y_caixa_texto1 = coords[0].y + texto[0].getGlobalBounds().height + espaco_adicional_entre_caixa_apelido;
    float posicao_y_caixa_texto2 = posicao_y_caixa_texto1 + 50.0f;

    caixa_de_texto1.Set_Font(*font);
    caixa_de_texto1.Set_Position({posicao_x_caixa_texto, posicao_y_caixa_texto1});
    caixa_de_texto1.Set_Limit(true, 10);

    caixa_de_texto2.Set_Font(*font);
    caixa_de_texto2.Set_Position({posicao_x_caixa_texto, posicao_y_caixa_texto2});
    caixa_de_texto2.Set_Limit(true, 10);

    janela->setKeyRepeatEnabled(true);
}

void Interface_Cadastro::Loop_Events(){
    sf::Event evento;
    int tam_vetor_texto = texto.size();

    while(janela->pollEvent(evento)) {
        if (evento.type == sf::Event::Closed) {
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
            if (posicao == 0) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                    caixa_de_texto1.Set_Selected(true);
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    caixa_de_texto1.Set_Selected(false);
                }
            } else if (posicao == 1) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                    caixa_de_texto2.Set_Selected(true);
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    caixa_de_texto2.Set_Selected(false);
                }
            } else if (posicao == 2) {
                theselect = true;
                /*chama funcao r*/
                janela->close();
                define_jogo = make_unique<Interface_Define_Jogo>();
                define_jogo->Run_Menu();
            }
        }

        if (evento.type == sf::Event::TextEntered) {
            if (caixa_de_texto1.caixa_esta_selecionado()) {
                caixa_de_texto1.Typed_On(evento);
            } else if (caixa_de_texto2.caixa_esta_selecionado()) {
                caixa_de_texto2.Typed_On(evento);
            }
        }
    }
}

void Interface_Cadastro::Draw_All() {
    this->janela->clear();
    this->janela->draw(*background);
    int tamanho_texto = texto.size();
    if(tamanho_texto) {
        for (const auto& text : texto) {
            janela->draw(text);
        }
    }
    caixa_de_texto1.Draw_To(*janela);
    caixa_de_texto2.Draw_To(*janela);
    this->janela->display();
}



