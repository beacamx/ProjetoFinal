#include "Caixa_de_texto.hpp"

Caixa_de_texto::Caixa_de_texto() {}

Caixa_de_texto::Caixa_de_texto(int tamanho_caixa, sf::Color cor_caixa, bool sel) {
    caixa_de_texto.setCharacterSize(tamanho_caixa);
    caixa_de_texto.setFillColor(cor_caixa);
    esta_selecionado = sel;
    if (sel) {
        caixa_de_texto.setString("_");
    } else {
        caixa_de_texto.setString("");
    }
}

void Caixa_de_texto::Input_Logic (int charTyped) {
    if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
        texto_de_entrada << static_cast<char>(charTyped);
    } else if (charTyped == DELETE_KEY) {
        if (texto_de_entrada.str().length() > 0) {
            Delete_Last_Char();
        }
    }
    caixa_de_texto.setString(texto_de_entrada.str() + "_");
}

void Caixa_de_texto::Delete_Last_Char() {
    string aux =  texto_de_entrada.str();
    string new_aux = "";
    int tamanho_aux = aux.length();
    for (int i = 0; i < tamanho_aux - 1; i++) 
        new_aux += aux[i];
    texto_de_entrada.str("");
    texto_de_entrada << new_aux;
    caixa_de_texto.setString(texto_de_entrada.str());
}

void Caixa_de_texto::Set_Font(sf::Font &font) {
    caixa_de_texto.setFont(font);
}

void Caixa_de_texto::Set_Position(sf::Vector2f position) {
    caixa_de_texto.setPosition(position);
}

void Caixa_de_texto::Set_Limit(bool Tof, int lim) {
    tem_limite = Tof;
    limite = lim - 1;
}

bool Caixa_de_texto::caixa_esta_selecionado() const { 
    return caixa_selecionada; 
}

void Caixa_de_texto::Set_Selected(bool sel) {
    esta_selecionado = sel;

    if (!sel) {
        string aux =  texto_de_entrada.str();
        string new_aux = "";
        int tamanho_aux = aux.length();
        for (int i = 0; i < tamanho_aux; i++) 
            new_aux += aux[i];

        caixa_de_texto.setString(new_aux);
    }
}

string Caixa_de_texto::Get_Text() {
    return texto_de_entrada.str();
}

void Caixa_de_texto::Draw_To(sf::RenderWindow &janela) {
    janela.draw(caixa_de_texto);
}

void Caixa_de_texto::Typed_On(sf::Event input) {
    int tamanho_texto_login = texto_de_entrada.str().length();
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
