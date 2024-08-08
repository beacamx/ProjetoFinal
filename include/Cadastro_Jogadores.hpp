#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
/*class jogador
{
public:
    jogador(std::string name) : jogador(name, 0, 0) {}
    jogador(std::string name, unsigned int wins, unsigned int loses) : _name(name), n_of_wins(wins), n_of_loses(loses) {}
    std::string get_name() { return _name; };
    unsigned int get_wins() { return n_of_wins; };
    unsigned int get_loses() { return n_of_loses; };

private:
    std::string _name;
    unsigned int n_of_wins;
    unsigned int n_of_loses;
};*/
#ifndef CADASTRO_HPP
#define CADASTRO_HPP
class cadastro{
  public:
  cadastro();
  ~cadastro();
  jogador * find(std::string);
  void cadastrar(jogador*);
  void remover(jogador*);  
  private:
  char default_name[40] = "Lig4&Reversi_data.storage";
  char string_controll[70] = "Lig4&Reversi_string_controll PDSII 2024/1.v1";
  void save();
  void load();
  std::vector<jogador*> jogadores;
};
#endif
