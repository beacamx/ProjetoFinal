#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <stdexcept>
#include <cstdlib>

using namespace std;

class Audio {
    private:
        sf::SoundBuffer buffer_selecao;
        sf::SoundBuffer buffer_avisos;
        sf::Sound som_selecao;
        sf::Sound som_aviso;
        sf::Music som_jogo;
        sf::Clock timer;
        const float tempo_limite = 1.0f;
    public:
        Textos(){};
        ~Textos(){};
        void Set_Efeito_Sonoro_Selecao_Botao();
        void Set_Efeito_Sonoro_Aviso();
        void Set_Music(string nome_jogo);
        void Timer(float tempo_duracao);
};

#endif