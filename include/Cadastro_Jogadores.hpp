#include <iostream>
#include <vector>
#include "Jogo.hpp"
using namespace std;
class cadastro{
  public:
  cadastro();
  void cadastrar(jogador * player_1, jogador * player_2);
  private:
  vector jogadores<jogador*>;
}
