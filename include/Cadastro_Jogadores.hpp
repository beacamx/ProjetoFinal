#include <iostream>
#include <vector>
#include "Jogo.hpp"
#ifndef CADASTRO_HPP
#define CADASTRO_HPP
class cadastro{
  public:
  jogador * find(std::string);
  void cadastrar(jogador*);
  void remover(jogador*);
  void save();
  void load();
  private:
  vector<jogador*> jogadores;
}
#endif
