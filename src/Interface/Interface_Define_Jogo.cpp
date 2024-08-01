#include "Interface_Define_Jogo.hpp"

Interface_Define_Jogo::Interface_Define_Jogo(){
    window = new sf::RenderWindow();
    winclose = new sf::RectangleShape();
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();

    Set_Values();
}

Interface_Define_Jogo::~Interface_Define_Jogo(){
    delete window;
    delete winclose;
    delete font;
    delete image;
    delete bg;
}

void Interface_Define_Jogo::Set_Values(){
    window->create(sf::VideoMode(624,546), "Jogos", sf::Style::Titlebar | sf::Style::Close);
    window->setPosition(sf::Vector2i(0,0));

    pos = 0;
    pressed = theselect = false;

    font->loadFromFile("./assets/fontes/pixelmix.ttf");
    image->loadFromFile("./assets/Menu/Menu.png");

    bg->setTexture(*image);

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

void Interface_Define_Jogo::Loop_Events(){
    sf::Event event;
    while(window->pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            window->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
            if(pos < 1){
                ++pos;
                pressed = true;
                texts[pos].setOutlineThickness(0.5);
                texts[pos].setOutlineColor(sf::Color(255,255,255));
                texts[pos - 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
            if(pos > 0){
                --pos;
                pressed = true;
                texts[pos].setOutlineThickness(0.5);
                texts[pos].setOutlineColor(sf::Color(255,255,255));
                texts[pos + 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
            theselect = true;
            if(pos == 0) {
                window->close();
                jogo = make_unique<Interface_Lig4>();
                jogo->Start_Game_Interface();
            } else if(pos == 1) {
                window->close();
                jogo = make_unique<Interface_Reversi>();
                jogo->Start_Game_Interface();
            }
        }
    }
}

void Interface_Define_Jogo::Draw_All(){
    window->clear();
    window->draw(*bg);
    for(auto t : texts) {
        window->draw(t);
    }
    window->display();
}

void Interface_Define_Jogo::Run_Menu(){
    while(window->isOpen()) {
        Loop_Events();
        Draw_All();
    }
}