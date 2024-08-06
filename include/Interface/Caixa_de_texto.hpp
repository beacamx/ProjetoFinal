#ifndef CAIXA_DE_TEXTO_HPP
#define CAIXA_DE_TEXTO_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

using namespace std;

class Caixa_de_texto {
    public:
        Caixa_de_texto();
        Caixa_de_texto(int tamanho_caixa, sf::Color cor_caixa, bool sel);

        void Set_Font(sf::Font &font);
        void Set_Position(sf::Vector2f position);
        void Set_Limit(bool Tof, int lim);
        bool caixa_esta_selecionado() const;
        void Set_Selected(bool sel);
        string Get_Text();
        void Draw_To(sf::RenderWindow &janela);
        void Typed_On(sf::Event input);

    private:
        sf::Text caixa_de_texto;
        ostringstream texto_login;
        bool esta_selecionado = false;
        bool caixa_selecionada = false;
        bool tem_limite = false;
        int limite;

        void Input_Logic (int charTyped);
        void Delete_Last_Char();
};

#endif