#ifndef TEXTOS_HPP
#define TEXTOS_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>

using namespace std;

class Textos {
    private:
        vector<sf::Text> textos;
        vector<sf::Vector2f> coords;
        vector<size_t> tamanho_fonte;
        unique_ptr<sf::Font> fonte;

    public:
        Textos();
        ~Textos();

        size_t Get_Tamanho_Vetor_Textos() const;
        const sf::Font& Get_Fonte() const;
        const vector<sf::Text>& Get_Vetor_Textos() const;
        vector<sf::Text>& Get_Vetor_Textos();
        void Draw_Vetor_Textos(sf::RenderWindow& janela) const;
        void Set_Fonte(const vector<size_t>& tamanhos);
        void Set_Textos_Sem_Entrada(const vector<const char*>& opcoes_de_escolha, float largura_janela, float altura_inferior_titulo, float espaco_vertical);
        void Set_Textos_Com_Entrada(const vector<const char*>& opcoes_de_escolha, float largura_janela, float altura_inferior_titulo, float espaco_vertical, float espaco_vertical_botao_play, float altura_texto);
};

#endif