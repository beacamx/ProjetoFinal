#include "Interface_Menu.hpp"

Interface_Menu::Interface_Menu() {
    this->janela = make_unique<sf::RenderWindow>();
    this->winclose = make_unique<sf::RectangleShape>();
    this->font = make_unique<sf::Font>();
    this->image = make_unique<sf::Texture>();
    this->background = make_unique<sf::Sprite>();
}

Interface_Menu::~Interface_Menu() {}

void Interface_Menu::Set_Efeito_Sonoro_Selecao_Botao() {
    if (!buffer_selecao.loadFromFile("./assets/audio/a.wav")) {
        cerr << "Erro ao carregar efeito sonoro" << endl;
        exit(1);
    }

    som_selecao.setBuffer(buffer_selecao);
    som_selecao.setVolume(50);
}

void Interface_Menu::Centralizar_Janela() {
    sf::Vector2i janela_centralizada(
        (sf::VideoMode::getDesktopMode().width - 624) / 2, 
        (sf::VideoMode::getDesktopMode().height - 546 )/ 2
    );
    janela->create(sf::VideoMode(624,546), "", sf::Style::Titlebar | sf::Style::Close);
    janela->setPosition(janela_centralizada);
}

void Interface_Menu::Draw_All() {
    this->janela->clear();
    this->janela->draw(*background);
    int tamanho_texto = texto.size();
    if(tamanho_texto) {
        for (const auto& text : texto) {
            janela->draw(text);
        }
    }
    this->janela->display();
}

void Interface_Menu::Run_Menu() {
    while (janela->isOpen()) {
        this->Loop_Events();
        Draw_All();
    }
}