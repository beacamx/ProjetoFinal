#include <iostream>
#include <set>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "jogador.hpp"
#ifndef CADASTRO_HPP
#define CADASTRO_HPP

class cadastro{
  public:
  cadastro();
  ~cadastro();
  Jogador * find_by_name(std::string);
  Jogador * find_by_nick(std::string);
  void cadastrar(Jogador*);
  void remover(Jogador*);
  void imprime_lista();
  std::vector<Jogador*> player_list();   
  void save();
  void load();
  std::set<Jogador*, player_compare> jogadores;
  char default_name[40] = "Lig4&Reversi_data.storage";
  char string_controll[70] = "Lig4&Reversi_string_controll PDSII 2024/1.v1";
};
#endif
