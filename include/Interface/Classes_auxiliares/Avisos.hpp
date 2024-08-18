#ifndef AVISOS_HPP
#define AVISOS_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <string>
#include <vector>

#include "Textos.hpp"

using namespace std;

class Avisos {
    private:
        sf::Clock timer;
        bool mostrar_aviso = false;
        Textos texto; 
        sf::Text aviso;
        float tempo_exibicao = 3.0f;
        float tempo_total = 0.0f;

    public:
        Avisos() {
            try {
                Set_Aviso();
            } catch (const std::exception& e) {
                cerr << "Erro ao inicializar os avisos: " << e.what() << endl;
            }
        }
        ~Avisos(){};
        bool Get_Mostrar_Aviso() const;
        void Get_Aviso_Com_Entrada(const string& mensagem_de_erro, float largura_janela, const vector<sf::Text>& textos);
        void Get_Aviso_Sem_Entrada(const string& mensagem_de_erro, float largura_janela, const vector<sf::Text>& textos);
        const sf::Text& Get_Aviso() const;
        void Set_Aviso();
        void Set_Mostrar_Aviso(bool mostrar);
        void Start_Timer(float tempo_exibicao);
        bool Is_Timer_Expired() const;
};

#endif