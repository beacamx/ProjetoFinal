#ifndef INTERFACE_REVERSI_HPP
#define INTERFACE_REVERSI_HPP

#include "Interface_Jogo.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>

class Interface_Reversi : public Interface_Jogo {
    public:
        Interface_Reversi() : Interface_Jogo("Reversi") {
            this->largura_quadrado = 74;
        }
        ~Interface_Reversi() {}

        void Logica() override; 
        int Start_Game_Interface(int num_linhas, int num_colunas) override; 
        void Set_Sprites() override;
        void Set_Textura_Peca1() override;
        void Set_Textura_Peca2() override;
        void Set_Textura_Sem_Peca() override;
        void Set_Music() override;
};

#endif