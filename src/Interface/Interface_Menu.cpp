#include "Interface_Menu.hpp"

Interface_Menu::Interface_Menu() {
    this->janela = make_unique<sf::RenderWindow>();
    this->winclose = make_unique<sf::RectangleShape>();
    this->font = make_unique<sf::Font>();
    this->image = make_unique<sf::Texture>();
    this->background = make_unique<sf::Sprite>();
}

Interface_Menu::~Interface_Menu() {}

void Interface_Menu::Draw_All() {
    this->janela->clear();
    this->janela->draw(*background);
    for (const auto& text : texto) {
        janela->draw(text);
    }
    this->janela->display();
}

void Interface_Menu::Run_Menu() {
    while (janela->isOpen()) {
        this->Loop_Events();
        Draw_All();
    }
}