#ifndef BOTAO_HPP
#define BOTAO_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

enum estados_botao{
    BOTAO_INATIVO = 0,
    BOTAO_HOVER,
    BOTAO_ATIVO
};

using namespace std;

class Botao {
    private:
        short unsigned estado_botao;

        int posicao;

        sf::RectangleShape caixa;
        sf::Font * fonte;
        sf::Text texto;

        sf::Color cor_inativa;
        sf::Color hover_color;
        sf::Color cor_ativa;
    public:
        Botao(float x, float y, float largura_botao, float altura_botao, 
            sf::Font* fonte, string texto, 
            sf::Color cor_inativa, sf::Color hover_color, sf::Color cor_ativa);
        ~Botao();

        // funcoes auxiliares
        const bool isPressed() const;

        // funcoes
        void update(const sf::Vector2f posicao_mouse);
        void render(sf::RenderTarget* target);

};

#endif