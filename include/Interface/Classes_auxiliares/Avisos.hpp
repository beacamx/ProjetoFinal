#ifndef AVISOS_HPP
#define AVISOS_HPP

#include <SFML/System.hpp>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "Audio.hpp"

using namespace std;

class Avisos {
    private:
        sf::Clock clock_aviso;
        bool mostrar_aviso = false;
        Audio audio;
        Texto texto;

    public:
        Textos(){};
        ~Textos(){};
        void Set_Aviso();

};

#endif