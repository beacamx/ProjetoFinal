#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "Interface/Interface_Jogo.hpp"
#include "Interface/Interface_Lig4.hpp"
#include "Interface/Interface_Reversi.hpp"

#include "Interface/Interface_Menu.hpp"
#include "Interface/Interface_Define_Jogo.hpp"
#include "Interface/Interface_Define_Dimensao.hpp"

#include "Interface/Interface_Login.hpp"
#include "Interface/Caixa_de_texto.hpp"

using namespace std;

int main() {
    //unique_ptr<Interface_Menu> menu = make_unique<Interface_Define_Jogo>();
    
    //menu->Run_Menu();

    unique_ptr<Interface_Login> login = make_unique<Interface_Login>();
    login->Run_Menu();
}
