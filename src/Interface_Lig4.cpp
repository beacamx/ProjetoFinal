#include "Interface_Lig4.hpp"
#include "Lig4.hpp"

using namespace std;

Lig4::Lig4() {
    window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(546, 468),
        "Lig4",
        sf::Style::Titlebar | sf::Style::Close
    );

    window->setPosition(sf::Vector2i(50, 50));
    window->setFramerateLimit(60);
    event = std::make_shared<sf::Event>();

    texture.loadFromFile("./assets/Lig4_7x6.png");

    largura = 78; 
    num_quadrados = x = y = direcionador_x = direcionador_y = 0;

    grid.fill({0});

    for(size_t i {}; i < 6; ++i) {
        for(size_t j {}; j < 7; ++j) {
            ++num_quadrados;
            sprite[num_quadrados - 1].setTexture(texture);
            sprite[num_quadrados - 1].setTextureRect(sf::IntRect(j * largura, i * largura, largura, largura)); // Corrigido para j e i
            grid[i + 1][j + 1] = num_quadrados;
        }
    }
}

void Lig4::events() {
    while (window->pollEvent(*event)) {
        if (event->type == sf::Event::Closed) {
            window->close();
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            cout << "Teste";
        }
    }
}

void Lig4::draw() {
    window->clear(sf::Color::Black);
    for(size_t i {}; i < 6; ++i) {
        for(size_t j {}; j < 7; ++j) {
            num_quadrados = grid[i + 1][j + 1];
            sprite[num_quadrados - 1].setPosition(j * largura, i * largura);
            window->draw(sprite[num_quadrados - 1]);
        }
    }
    window->display();
}

void Lig4::run() {
    while (window->isOpen()) {
        this->events();
        this->draw();
    }
}
