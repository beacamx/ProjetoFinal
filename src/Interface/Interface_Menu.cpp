#include "Interface_Menu.hpp"

Interface_Menu::Interface_Menu() {
    this->window = new sf::RenderWindow();
    this->winclose = new sf::RectangleShape();
    this->font = new sf::Font();
    this->image = new sf::Texture();
    this->background = new sf::Sprite();
}

Interface_Menu::~Interface_Menu() {
    delete window;
    delete winclose;
    delete font;
    delete image;
    delete background;
}

void Interface_Menu::Draw_All() {
    this->window->clear();
    this->window->draw(*background);
    for (const auto& text : texts) {
        window->draw(text);
    }
    this->window->display();
}

void Interface_Menu::Run_Menu() {
    while (window->isOpen()) {
        this->Loop_Events();
        Draw_All();
    }
}
