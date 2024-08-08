#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "jogador.cpp"
#ifndef CADASTRO_HPP
#define CADASTRO_HPP

class cadastro{
  public:
  cadastro();
  ~cadastro();
  jogador * find(std::string);
  void cadastrar(jogador*);
  void remover(jogador*);  
  void save();
  void load();
  private:
  char default_name[40] = "Lig4&Reversi_data.storage";
  char string_controll[70] = "Lig4&Reversi_string_controll PDSII 2024/1.v1";
  std::set<jogador*, player_compare> jogadores;
};
#endif
