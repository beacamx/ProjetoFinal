#ifndef INTERFACE_LIG4_HPP
#define INTERFACE_LIG4_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <array>

class Lig4 {
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<sf::Event> event;

    sf::Texture texture;

    int largura, num_quadrados, x, y, direcionador_x, direcionador_y;
    std::array<std::array<int, 7>, 6> grid;
    sf::Sprite sprite;

    protected:
        void events();
        void draw();

    public:
        Lig4();
        void run();
};

#endif