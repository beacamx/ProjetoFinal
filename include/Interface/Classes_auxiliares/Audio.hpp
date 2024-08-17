#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <iostream>
#include <SFML/Audio.hpp>
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
    public:
        Textos(){};
        ~Textos(){};
        void Set_Efeito_Sonoro_Selecao_Botao();
        void Set_Efeito_Sonoro_Aviso();
        void Set_Music(string nome_jogo);
};

#endif