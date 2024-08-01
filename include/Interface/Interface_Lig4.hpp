#ifndef INTERFACE_LIG4_HPP
#define INTERFACE_LIG4_HPP

#include "Interface_Jogo.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <array>

class Interface_Lig4 : public Interface_Jogo {
    public:
    Interface_Lig4() : Interface_Jogo("Lig4") {}

    void logic() override;
    int Start_Game_Interface() override; 
    void set_Sprites() override;
    void set_Image() override;
};

#endif