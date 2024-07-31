#ifndef INTERFACE_JOGO_HPP
#define INTERFACE_JOGO_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <array>

using namespace std;

class Interface_Jogo {
public:
    Interface_Jogo(const std::string& nome_do_jogo);
    virtual ~Interface_Jogo() = default;
    
    void events();
    void run();
    void draw();

    virtual void set_Sprites() = 0;
    virtual void set_Image() = 0;
    virtual void logic() = 0;
    virtual int Start_Game_Interface(int argc, char **argv) = 0;

protected:
    int linhas;
    int colunas;
    int largura_quadrado;
    int num_quadrados;
    string nome_do_jogo;

    shared_ptr<sf::RenderWindow> window;
    sf::Texture texture;
    vector<sf::Sprite> sprites;
    vector<std::vector<int>> grid;

    shared_ptr<sf::Event> event; 
    int x, y, direcionador_x, direcionador_y;
};

#endif