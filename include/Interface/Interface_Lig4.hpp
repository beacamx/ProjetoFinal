#ifndef INTERFACE_LIG4_HPP
#define INTERFACE_LIG4_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <array>

class Interface_Lig4 {
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<sf::Event> event;

    sf::Texture texture;

    int largura, num_quadrados, x, y, direcionador_x, direcionador_y;
    std::array<std::array<int, 8>, 7> grid;
    std::array<sf::Sprite, 42> sprite;

    protected:
        void events();
        void draw();
        void logic();

    public:
        Interface_Lig4();
        void run();
};

#endif