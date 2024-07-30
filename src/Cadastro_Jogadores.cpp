#include "Cadastro.hpp"
#include "data_managment.hpp"
cadastro::cadastro(){
  load(this);
}
void cadastro::cadastrar(jogador * player_1, jogador * player_2){
  jogadores.push_back(player_1);
  jogadores.push_back(player_2);
}
