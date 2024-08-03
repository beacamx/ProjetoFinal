#include "Interface_Define_Dimensao.hpp"

using namespace std;

Interface_Define_Dimensao::~Interface_Define_Dimensao(){}

void Interface_Define_Dimensao::Set_Values(){
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
    
    if (!image->loadFromFile("./assets/Menu/Selecao_Dimensao.png")) 
        cerr << "Erro ao carregar imagem de fundo" << endl;
    
    background->setTexture(*image);

    posicao_mouse = {0,0};
    mouse_coord = {0,0};

    if (nome_jogo == "Lig4") {
        opcoes_de_escolha = {"6x7", "7x8", "8x9"};
    } else if (nome_jogo == "Reversi") {
        opcoes_de_escolha = {"8x8", "9x9", "10x10"};
    } 

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

void Interface_Define_Dimensao::Loop_Events(){
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
                texto[posicao].setOutlineThickness(0.6);
                texto[posicao].setOutlineColor(sf::Color(255,255,255));
                texto[posicao - 1].setOutlineThickness(0);
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

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
            theselect = true;

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