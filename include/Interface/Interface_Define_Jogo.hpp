#ifndef INTERFACE_DEFINICOES_JOGO_HPP
#define INTERFACE_DEFINICOES_JOGO_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>

#include "Interface_Menu.hpp"
#include "Interface_Define_Dimensao.hpp"
#include "Interface_Jogo.hpp"
#include "Interface_Lig4.hpp"
#include "Interface_Reversi.hpp"

using namespace std;

class Interface_Define_Jogo: public Interface_Menu {
    protected:
    void Set_Values() override;
    void Loop_Events() override;
    unique_ptr<Interface_Define_Dimensao> dimensao;
 
    public:
    Interface_Define_Jogo();
    ~Interface_Define_Jogo() override;
};

#endif