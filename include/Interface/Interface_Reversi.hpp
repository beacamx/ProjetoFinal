#ifndef INTERFACE_REVERSI_HPP
#define INTERFACE_REVERSI_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <array>

class Interface_Reversi {
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<sf::Event> event;

    sf::Texture texture;

    int largura, num_quadrados, x, y, direcionador_x, direcionador_y;
    std::array<std::array<int, 9>, 9> grid;
    std::array<sf::Sprite, 64> sprite;

    protected:
        void events();
        void draw();
        void logic();

    public:
        Interface_Reversi();
        void run();
};

#endif