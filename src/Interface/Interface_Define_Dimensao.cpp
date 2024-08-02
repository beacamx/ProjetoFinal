#include "Interface_Define_Dimensao.hpp"

#include <string>

using namespace std;

Interface_Define_Dimensao::~Interface_Define_Dimensao(){}

void Interface_Define_Dimensao::Set_Values(){
    if (!window || !font || !image || !background) {
        cerr << "Erro: recursos não inicializados corretamente." << endl;
        return;
    }

    window->create(sf::VideoMode(624,546), "Dimensoes", sf::Style::Titlebar | sf::Style::Close);
    window->setPosition(sf::Vector2i(0,0));

    posicao = 0;
    pressed = theselect = false;

    if (!font->loadFromFile("./assets/fontes/pixelmix.ttf")) 
        cerr << "Erro ao carregar fonte" << endl;
    
    if (!image->loadFromFile("./assets/Menu/Selecao_Dimensao.png")) 
        cerr << "Erro ao carregar imagem de fundo" << endl;
    
    background->setTexture(*image);

       std::cout << "Nome do jogo: " << nome_jogo << std::endl;

    pos_mouse = {0,0};
    mouse_coord = {0,0};

    if (nome_jogo == "Lig4") {
        options = {"7x6", "8x7", "9x7"};
    } else if (nome_jogo == "Reversi") {
        options = {"8x8", "9x9", "10x10"};
    } else {
        std::cerr << "Nome do jogo desconhecido: " << nome_jogo << std::endl;
        return;
    }

    coords.clear();
    sizes.clear();
    
    std::cout << "Número de opções: " << options.size() << std::endl;

    float espaco_vertical = 61.0f;

    for (size_t i = 0; i < options.size(); ++i) {
        coords.push_back(sf::Vector2f(288, 283 + i * espaco_vertical));
        sizes.push_back(18); 
    }

    texts.resize(options.size());

    for(size_t i{}; i < texts.size(); ++i) {
        texts[i].setFont(*font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(sizes[i]);
        texts[i].setOutlineColor(sf::Color::Black);
        texts[i].setPosition(coords[i]);
    }

    texts[0].setOutlineThickness(0.5);
    texts[0].setOutlineColor(sf::Color(255,255,255));
}

void Interface_Define_Dimensao::Loop_Events(){
    sf::Event event;

    int tam_vetor_texto = texts.size();
    while(window->pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            window->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
            if(posicao < tam_vetor_texto - 1){
                ++posicao;
                pressed = true;
                texts[posicao].setOutlineThickness(0.5);
                texts[posicao].setOutlineColor(sf::Color(255,255,255));
                texts[posicao - 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
            if(posicao > 0){
                --posicao;
                pressed = true;
                texts[posicao].setOutlineThickness(0.5);
                texts[posicao].setOutlineColor(sf::Color(255,255,255));
                texts[posicao + 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
            theselect = true;

            if (nome_jogo == "Lig4") {
                if (posicao == 0) {
                    window->close();
                    num_linhas = 6;
                    num_colunas = 7;
                    jogo = make_unique<Interface_Lig4>();
                    jogo->Start_Game_Interface(num_linhas, num_colunas);
                } else if (posicao == 1) {
                    window->close();
                    num_linhas = 7;
                    num_colunas = 8;
                    jogo = make_unique<Interface_Lig4>();
                    jogo->Start_Game_Interface(num_linhas, num_colunas);
                } else if (posicao == 2) {
                    window->close();
                    num_linhas = 8;
                    num_colunas = 9;
                    jogo = make_unique<Interface_Lig4>();
                    jogo->Start_Game_Interface(num_linhas, num_colunas);
                }
            } else if (nome_jogo == "Reversi") {
                if (posicao == 0) {
                    window->close();
                    num_linhas = 8;
                    num_colunas = 8;
                    jogo = make_unique<Interface_Reversi>();
                    jogo->Start_Game_Interface(num_linhas, num_colunas);
                } else if (posicao == 1) {
                    window->close();
                    num_linhas = 9;
                    num_colunas = 9;
                    jogo = make_unique<Interface_Reversi>();
                    jogo->Start_Game_Interface(num_linhas, num_colunas);
                } else if (posicao == 2) {
                    window->close();
                    num_linhas = 10;
                    num_colunas = 10;
                    jogo = make_unique<Interface_Reversi>();
                    jogo->Start_Game_Interface(num_linhas, num_colunas);
                }
            }
        }
    }
}
