#include <iostream>
#include <vector>
#include "Jogo.hpp"
using namespace std;
class cadastro{
  public:
  cadastro();
  void cadastrar(jogador * player_1);
  jogador* find(string);
  private:
  vector jogadores<jogador*>;
}
