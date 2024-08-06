#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "Interface/Interface_Tela_Inicial.hpp"

using namespace std;

int main() {
    unique_ptr<Interface_Tela_Inicial> menu = make_unique<Interface_Tela_Inicial>();
    menu->Run_Menu();
}
