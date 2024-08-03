#include "Interface_Login.hpp"

using namespace std;

Interface_Login::Interface_Login()
    : define_jogo(nullptr), caixa_de_texto1(15, sf::Color::White, false) { Set_Values();}

Interface_Login::~Interface_Login(){}

void Interface_Login::Set_Values(){
    if (!janela || !font || !image || !background) {
        cerr << "Erro: recursos não inicializados corretamente." << endl;
        return;
    }

    Set_Efeito_Sonoro_Selecao_Botao();

    if (!font->loadFromFile("./assets/fontes/pixelmix.ttf")) 
        cerr << "Erro ao carregar fonte" << endl;

    Centralizar_Janela();

    posicao = 0;
    pressed = theselect = false;
    
    if (!image->loadFromFile("./assets/Menu/Login.png")) 
        cerr << "Erro ao carregar imagem de fundo" << endl;

    background->setTexture(*image);

    opcoes_de_escolha = {"Digitar apelido", "Login"};
    tamanho_fonte = {22, 17};
    
    float espaco_vertical = 95.0f;
    float largura_janela = 624.0f;
    float altura_texto = 244.0f; 

    coords.clear();

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

    texto[0].setOutlineThickness(0.6);
    texto[0].setOutlineColor(sf::Color(255,255,255));

    float largura_caixa = 120.0f;
    float espaco_adicional_entre_caixa_apelido = 16.0f;

    float posicao_x_caixa_texto = (largura_janela - largura_caixa) / 2;
    float posicao_y_caixa_texto = coords[0].y + texto[0].getGlobalBounds().height + espaco_adicional_entre_caixa_apelido;

    caixa_de_texto1.Set_Font(*font);
    caixa_de_texto1.Set_Position({posicao_x_caixa_texto, posicao_y_caixa_texto});
    caixa_de_texto1.Set_Limit(true, 10);

    janela->setKeyRepeatEnabled(true);
}

void Interface_Login::Loop_Events(){
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
                if(posicao != 0) {
                    texto[posicao].setOutlineThickness(0.6);
                    texto[posicao].setOutlineColor(sf::Color(255,255,255));
                    texto[posicao - 1].setOutlineThickness(0);
                }
                pressed = false;
                theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
            som_selecao.play();
            if(posicao > 0){
                --posicao;
                pressed = true;
                texto[posicao].setOutlineThickness(0.6);
                texto[posicao].setOutlineColor(sf::Color(255,255,255));
                texto[posicao + 1].setOutlineThickness(0);
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
                theselect = true;
                /*chama funcao para verificar se o jogador existe
                se nao existir, mostra um aviso
                se existir, define o jogador que vai jogar*/
                janela->close();
                define_jogo = make_unique<Interface_Define_Jogo>();
                define_jogo->Run_Menu();
            } 
        }

        if (evento.type == sf::Event::TextEntered) {
            caixa_de_texto1.Typed_On(evento);
        }
    }
}

void Interface_Login::Draw_All() {
    this->janela->clear();
    this->janela->draw(*background);
    int tamanho_texto = texto.size();
    if(tamanho_texto) {
        for (const auto& text : texto) {
            janela->draw(text);
        }
    }
    caixa_de_texto1.Draw_To(*janela);

    this->janela->display();
}



