#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "Interface/Interface_Jogo.hpp"
#include "Interface/Interface_Lig4.hpp"
#include "Interface/Interface_Reversi.hpp"

#include "Interface/Interface_Tela_Inicial.hpp"
#include "Interface/Interface_Menu.hpp"
#include "Interface/Interface_Define_Jogo.hpp"
#include "Interface/Interface_Define_Dimensao.hpp"

#include "Interface/Interface_Login_Jogador1.hpp"
#include "Interface/Interface_Cadastro_Jogador1.hpp"
#include "Interface/Interface_Login_Jogador2.hpp"
#include "Interface/Interface_Cadastro_Jogador2.hpp"

#include "Interface/Interface_Definicao_Entrada_Jogador1.hpp"
#include "Interface/Interface_Definicao_Entrada_Jogador2.hpp"
#include "Interface/Caixa_de_texto.hpp"

using namespace std;

int main() {
    unique_ptr<Interface_Tela_Inicial> menu = make_unique<Interface_Tela_Inicial>();
    menu->Run_Menu();
}
