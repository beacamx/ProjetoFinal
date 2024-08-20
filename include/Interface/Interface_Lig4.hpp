#ifndef INTERFACE_LIG4_HPP
#define INTERFACE_LIG4_HPP

#include "Interface_Jogo.hpp"
#include "Lig4.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>

using namespace std;

class Interface_Lig4 : public Interface_Jogo {
    public:
        Interface_Lig4(int num_linhas, int num_colunas);
        ~Interface_Lig4(){};

        void Logica() override;
        void Set_Values() override; 
        void Set_Sprites() override;
        void Set_Textura_Sem_Peca() override;
        void Set_Textura_Peca1() override;
        void Set_Textura_Peca2() override;

    private:
        Lig4 lig4;
};

#endif