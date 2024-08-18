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
        sf::Sound som_selecao;
        sf::Music som_jogo;
        const float tempo_limite = 1.0f;
    public:
        Audio() {};
        ~Audio() {};
        void Set_Efeito_Sonoro_Selecao_Botao();
        void Set_Music(const string& nome_jogo);

        void Play_Efeito_Sonoro_Selecao_Botao();
        void Play_Music();

        void Stop_Music();
};

#endif