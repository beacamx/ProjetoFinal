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
        Caixa_de_texto() {}

        Caixa_de_texto(int tamanho_caixa, sf::Color cor_caixa, bool sel) {
            caixa_de_texto.setCharacterSize(tamanho_caixa);
            caixa_de_texto.setFillColor(cor_caixa);
            esta_selecionado = sel;
            if (sel) {
                caixa_de_texto.setString("_");
            } else {
                caixa_de_texto.setString("");
            }
        }

        void Set_Font(sf::Font &font) {
            caixa_de_texto.setFont(font);
        }

        void Set_Position(sf::Vector2f position) {
            caixa_de_texto.setPosition(position);
        }

        void Set_Limit(bool Tof, int lim) {
            tem_limite = Tof;
            limite = lim - 1;
        }

        void Set_Selected(bool sel) {
            esta_selecionado = sel;
            if (!sel) {
                string aux =  texto_login.str();
                string new_aux = "";
                int tamanho_aux = aux.length();
                for (int i = 0; i < tamanho_aux; i++) 
                    new_aux += aux[i];

                caixa_de_texto.setString(new_aux);
            }
        }

        string Get_Text() {
            return texto_login.str();
        }

        void Draw_To(sf::RenderWindow &janela) {
            janela.draw(caixa_de_texto);
        }

        void Typed_On(sf::Event input) {
            int tamanho_texto_login = texto_login.str().length();
            if (esta_selecionado) {
                int Char_Typed = input.text.unicode;
                if (Char_Typed < 128) {
                    if (tem_limite) {
                        if (tamanho_texto_login <= limite) {
                            Input_Logic(Char_Typed);
                        } else if (tamanho_texto_login > limite && Char_Typed == DELETE_KEY) {
                            Delete_Last_Char();
                        }
                    } else {
                        Input_Logic(Char_Typed);
                    }
                }
            }
        }
    private:
        sf::Text caixa_de_texto;
        ostringstream texto_login;
        bool esta_selecionado = false;
        bool tem_limite = false;
        int limite;

        void Input_Logic (int charTyped) {
            if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
                texto_login << static_cast<char>(charTyped);
            } else if (charTyped == DELETE_KEY) {
                if (texto_login.str().length() > 0) {
                    Delete_Last_Char();
                }
            }
            caixa_de_texto.setString(texto_login.str() + "_");
        }

        void Delete_Last_Char() {
            string aux =  texto_login.str();
            string new_aux = "";
            int tamanho_aux = aux.length();
            for (int i = 0; i < tamanho_aux - 1; i++) 
                new_aux += aux[i];
            texto_login.str("");
            texto_login << new_aux;

            caixa_de_texto.setString(texto_login.str());
        }
};

#endif