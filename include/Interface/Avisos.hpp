#ifndef AVISOS_HPP
#define AVISOS_HPP

#include <SFML/System.hpp>
#include <iostream>

class Avisos {
    private:
        sf::Clock clock_aviso;
        bool mostrar_aviso = false;

    public:
        void Set_Aviso();

};

#endif