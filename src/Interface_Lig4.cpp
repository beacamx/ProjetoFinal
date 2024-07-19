#include "Interface_Lig4.hpp"
#include "Lig4.hpp"

Lig4::Lig4(){
    window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(546, 468),
        "Lig4",
        sf::Style::Titlebar | sf::Style::Close
    );

    window->setPosition(sf::Vector2i(50, 50));
    window->setFramerateLimit(60);
    event = std::make_shared<sf::Event>();

    texture.loadFromFile("./assets/Lig4_7x6.png");

    largura = {128}; num_quadrados = x = y = direcionador_x = direcionador_y = {0};

    grid = {0};

    sprite.setTexture(texture);
}

void Lig4::Lig4::events(){
    while(window->pollEvent(*event)){
        if(event->type == sf::Event::Closed) {
            window->close();
        }
    }
}

void Lig4::draw(){
    window->clear(sf::Color::Black);
    window->draw(sprite);
    window->display();
}

void Lig4::run(){
    while(window->isOpen()){
        this->events();
        this->draw();
    }
}