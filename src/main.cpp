#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "Interface/Interface_Tela_Inicial.hpp"
#include "Interface/Interface_Define_Dimensao.hpp"

using namespace std;

int main() {
    //testar tudo
    //unique_ptr<Interface_Tela_Inicial> menu = make_unique<Interface_Tela_Inicial>();
    //menu->Run();

    //testar Lig4 (só pra teste)
    unique_ptr<Interface_Define_Dimensao> dimensao;

    dimensao = make_unique<Interface_Define_Dimensao>("Lig4");
    dimensao->Run();

    //testar Reversi (só pra teste)

    //unique_ptr<Interface_Define_Dimensao> dimensao;

    //dimensao = make_unique<Interface_Define_Dimensao>("Reversi");
    //dimensao->Run();
}
