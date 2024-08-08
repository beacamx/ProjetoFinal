#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "Jogo.hpp"
#ifndef CADASTRO_HPP
#define CADASTRO_HPP
class cadastro{
  public:
  cadastro();
  ~cadastro();
  jogador * find(std::string);
  void cadastrar(jogador*);
  void remover(jogador*);
  std::string default_name;
  std::string string_controll;
  private:
  void save();
  void load();
  vector<jogador*> jogadores;
}
#endif
