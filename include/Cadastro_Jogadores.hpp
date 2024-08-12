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
  jogador * find_by_name(std::string);
  jogador * find_by_nick(std::string);
  void cadastrar(jogador*);
  void remover(jogador*);
  void imprime_lista();
  std::vector<jogador*> player_list();   
  void save();
  void load();
  private:
  char default_name[40] = "Lig4&Reversi_data.storage";
  char string_controll[70] = "Lig4&Reversi_string_controll PDSII 2024/1.v1";
  std::set<jogador*, player_compare> jogadores;
};
#endif
