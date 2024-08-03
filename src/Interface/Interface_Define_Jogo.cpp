#include "Interface_Define_Jogo.hpp"

using namespace std;

Interface_Define_Jogo::Interface_Define_Jogo(){
    Set_Values();
}

Interface_Define_Jogo::~Interface_Define_Jogo(){}

void Interface_Define_Jogo::Set_Values(){
    if (!janela || !font || !image || !background) {
        cerr << "Erro: recursos não inicializados corretamente." << endl;
        return;
    }

    Set_Efeito_Sonoro_Selecao_Botao();

    Centralizar_Janela();

    posicao = 0;
    pressed = theselect = false;
    
    if (!font->loadFromFile("./assets/fontes/pixelmix.ttf")) 
        cerr << "Erro ao carregar fonte" << endl;
    
    if (!image->loadFromFile("./assets/Menu/Selecao_Jogo.png")) 
        cerr << "Erro ao carregar imagem de fundo" << endl;

    background->setTexture(*image);

    posicao_mouse = {0,0};
    mouse_coord = {0,0};

    opcoes_de_escolha = {"Lig4", "Reversi"};
    
    coords.clear();
    tamanho_fonte.clear();

    float espaco_vertical = 61.0f;
    float largura_janela = 624.0f;
    float altura_titulo = 271.0f; 
    float altura_inferior_titulo = altura_titulo + 20.0f; 

    for (size_t i = 0; i < opcoes_de_escolha.size(); ++i) {
        float pos_y = altura_inferior_titulo + (i * espaco_vertical);
        coords.push_back(sf::Vector2f(largura_janela / 2, pos_y));
        tamanho_fonte.push_back(18); 
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
                texto[posicao].setOutlineThickness(0.6);
                texto[posicao].setOutlineColor(sf::Color(255,255,255));
                texto[posicao - 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
            if(posicao > 0){
                som_selecao.play();
                --posicao;
                pressed = true;
                texto[posicao].setOutlineThickness(0.6);
                texto[posicao].setOutlineColor(sf::Color(255,255,255));
                texto[posicao + 1].setOutlineThickness(0);
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

