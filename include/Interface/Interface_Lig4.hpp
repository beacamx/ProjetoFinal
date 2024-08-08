#ifndef INTERFACE_LIG4_HPP
#define INTERFACE_LIG4_HPP

#include "Interface_Jogo.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>

class Interface_Lig4 : public Interface_Jogo {
    public:
        Interface_Lig4() : Interface_Jogo("Lig4") {
            this->largura_quadrado = 78;
        }

        ~Interface_Lig4() {}

        void Logica() override;
        int Start_Game_Interface(int num_linhas, int num_colunas) override; 
        void Set_Sprites() override;
        void Set_Textura_Sem_Peca() override;
        void Set_Textura_Peca1() override;
        void Set_Textura_Peca2() override;
        void Set_Music() override;
};

#endif