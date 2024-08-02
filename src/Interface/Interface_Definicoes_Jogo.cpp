#include "Interface_Definicoes_Jogo.hpp"

Interface_Definicoes_Jogo::Interface_Definicoes_Jogo(){
    Set_Values();
}

Interface_Definicoes_Jogo::~Interface_Definicoes_Jogo(){}

void Interface_Definicoes_Jogo::Set_Values(){
    window->create(sf::VideoMode(624,546), "Jogos", sf::Style::Titlebar | sf::Style::Close);
    window->setPosition(sf::Vector2i(0,0));

    posicao = 0;
    pressed = theselect = false;
    
    if (!font->loadFromFile("./assets/fontes/pixelmix.ttf")) 
        cerr << "Erro ao carregar fonte" << endl;
    
    if (!image->loadFromFile("./assets/Menu/Selecao_Jogo.png")) 
        cerr << "Erro ao carregar imagem de fundo" << endl;

    background->setTexture(*image);

    pos_mouse = {0,0};
    mouse_coord = {0,0};

    options = {"Lig4", "Reversi"};
    coords = {{288,283}, {268,344}};
    sizes = {18, 18};

    texts.resize(2);

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

void Interface_Definicoes_Jogo::Loop_Events(){
    sf::Event event;
    while(window->pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            window->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
            if(posicao < 1){
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
            if(posicao == 0) {
                window->close();
                dimensao = make_unique<Interface_Define_Dimensao>("Lig4");
                dimensao->Run_Menu();
            } else if(posicao == 1) {
                window->close();
                dimensao = make_unique<Interface_Define_Dimensao>("Reversi");
                dimensao->Run_Menu();
            }
        }
    }
}

