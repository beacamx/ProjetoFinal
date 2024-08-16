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

        void Definir_Fonte(sf::Font &font);
        void Definir_Posicao(sf::Vector2f position);
        void Definir_Limite(bool com_limite, int lim);
        // bool Caixa_Esta_Selecionada() const;
        void Definir_Selecao(bool sel);
        string Obter_Texto_Entrada();
        void Draw_To(sf::RenderWindow &janela);
        void Processar_Entrada(sf::Event input);
        void Definir_Configuracoes_Caixa_de_Texto(sf::Font &font, sf::Vector2f position, bool com_limite, int lim);

    private:
        sf::Text caixa_de_texto;
        ostringstream texto_de_entrada;
        bool selecionado = false;
        // bool caixa_selecionada = false;
        bool tem_limite = false;
        int limite;

        void Logica_Entrada (int charTyped);
        void Excluir_Ultimo_Caractere();
};

#endif