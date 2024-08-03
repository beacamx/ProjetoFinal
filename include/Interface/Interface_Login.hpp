#ifndef INTERFACE_LOGIN_HPP
#define INTERFACE_LOGIN_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>

#include "Interface_Menu.hpp"
#include "Interface_Define_Jogo.hpp"
#include "data_manager.hpp"

using namespace std;

class Interface_Login: public Interface_Menu {
    protected:
        void Set_Values() override;
        void Loop_Events() override;
        unique_ptr<Interface_Define_Jogo> define_jogo;
    public:
        Interface_Login();
        ~Interface_Login() override;
};

#endif