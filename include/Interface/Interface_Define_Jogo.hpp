#ifndef INTERFACE_DEFINE_JOGO_HPP
#define INTERFACE_DEFINE_JOGO_HPP

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include "Interface_Jogo.hpp"
#include "Interface_Lig4.hpp"
#include "Interface_Reversi.hpp"

using namespace std;

class Interface_Define_Jogo {
    int pos;
    bool pressed, theselect;

    sf::RenderWindow * window;
    sf::RectangleShape * winclose;
    sf::Font * font;
    sf::Texture * image;
    sf::Sprite * bg;

    sf::Vector2i pos_mouse;
    sf::Vector2f mouse_coord;

    vector<const char*> options;
    vector<sf::Vector2f> coords;
    vector<sf::Text> texts;
    vector<size_t> sizes;

    protected:
    void Set_Values();
    void Loop_Events();
    void Draw_All();
    unique_ptr<Interface_Jogo> jogo;

    public:
    Interface_Define_Jogo();
    ~Interface_Define_Jogo();
    void Run_Menu();
};

#endif