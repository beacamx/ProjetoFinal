#include "Interface_Lig4.hpp"
#include "Lig4.hpp"

using namespace std;

Interface_Lig4::Interface_Lig4() {
    window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(546, 468),
        "Lig4",
        sf::Style::Titlebar | sf::Style::Close
    );

    window->setPosition(sf::Vector2i(50, 50));
    window->setFramerateLimit(60);
    event = std::make_shared<sf::Event>();

    texture.loadFromFile("./assets/Lig4/Lig4_7x6.png");

    largura = texture.getSize().x / 7;
    int altura = texture.getSize().y / 6;
    num_quadrados = x = y = direcionador_x = direcionador_y = 0;

    grid.fill({0});

    for(size_t i {}; i < 6; ++i) {
        for(size_t j {}; j < 7; ++j) {
            ++num_quadrados;
            sprite[num_quadrados - 1].setTexture(texture);
            sprite[num_quadrados - 1].setTextureRect(sf::IntRect(j * largura, i * altura, largura, altura));
            grid[i + 1][j + 1] = num_quadrados;
        }
    }
}

void Interface_Lig4::events() {
    static bool mousePressed = false;

    while (window->pollEvent(*event)) {
        if (event->type == sf::Event::Closed) {
            window->close();
        }

        if (event->type == sf::Event::MouseButtonPressed) {
            if (event->mouseButton.button == sf::Mouse::Left && !mousePressed) {
                mousePressed = true;

                sf::Vector2i pos = sf::Mouse::getPosition(*window);
                this->x = pos.x / largura + 1;
                this->y = pos.y / largura + 1;

                if (x > 0 && x <= 7 && y > 0 && y <= 6) { // para testar se cada sprite está sendo lido corretamente
                    cout << "Você clicou no número: " << grid[y][x] << endl;
                }
            }
        }

        if (event->type == sf::Event::MouseButtonReleased) {
            if (event->mouseButton.button == sf::Mouse::Left) {
                mousePressed = false;
            }
        }
    }
}

void Interface_Lig4::draw() {
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

void Interface_Lig4::run() {
    while (window->isOpen()) {
        this->events();
        this->draw();
        // this->logic();
    }
}

void Interface_Lig4::logic() {
}