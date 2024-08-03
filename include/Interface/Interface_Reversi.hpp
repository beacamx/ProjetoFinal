#ifndef INTERFACE_REVERSI_HPP
#define INTERFACE_REVERSI_HPP

#include "Interface_Jogo.hpp"

class Interface_Reversi : public Interface_Jogo {
    public:
        Interface_Reversi() : Interface_Jogo("Reversi") {}
        ~Interface_Reversi() { cleanup(); }

        void logic() override; 
        int Start_Game_Interface(int num_linhas, int num_colunas) override; 
        void set_Sprites() override;
        void set_Image() override;

    private:
        void cleanup();

};

#endif