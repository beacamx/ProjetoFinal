#ifndef INTERFACE_MENU_HPP
#define INTERFACE_MENU_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

class Interface_Menu {
protected:
    int posicao, num_botoes, num_janela;
    bool pressed, theselect;
    sf::RenderWindow* window;
    sf::RectangleShape* winclose;
    sf::Font* font;
    sf::Texture* image;
    sf::Sprite* background;
    sf::Vector2i pos_mouse;
    sf::Vector2f mouse_coord;

    vector<const char*> options;
    vector<sf::Vector2f> coords;
    vector<sf::Text> texts;
    vector<size_t> sizes;

    virtual void Set_Values() = 0;
    virtual void Loop_Events() = 0;
    void Draw_All();
public:
    Interface_Menu();
    virtual ~Interface_Menu();
    void Run_Menu();
};

#endif
