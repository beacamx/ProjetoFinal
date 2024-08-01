#ifndef INTERFACE_REVERSI_HPP
#define INTERFACE_REVERSI_HPP

#include "Interface_Jogo.hpp"

class Interface_Reversi : public Interface_Jogo {
public:
    Interface_Reversi() : Interface_Jogo("Reversi") {}

    void logic() override; 
    int Start_Game_Interface() override; 
    void set_Sprites() override;
    void set_Image() override;
};

#endif