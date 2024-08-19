#ifndef INTERFACE_REVERSI_HPP
#define INTERFACE_REVERSI_HPP

#include "Interface_Jogo.hpp"
#include "Reversi.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Interface_Reversi : public Interface_Jogo {
    public:
        Interface_Reversi(int num_linhas, int num_colunas);
        ~Interface_Reversi(){};

        void Logica() override; 
        void Set_Values() override; 
        void Set_Sprites() override;
        void Set_Textura_Peca1() override;
        void Set_Textura_Peca2() override;
        void Set_Textura_Sem_Peca() override;
        //void Set_Music() override;

    private:
        Reversi reversi;
};
#endif