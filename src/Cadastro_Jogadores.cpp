#include "Cadastro_Jogadores.hpp"
#include <iostream>
#include <fstream>
cadastro::cadastro(){
  load();
}
cadastro::~cadastro(){
  save();
}
jogador * cadastro::find(std::string _name){
  for (auto _aux : jogadores){
    if(_aux->get_name() == _name){
      return _aux;
    }
  }
  return NULL;
}
void cadastro::cadastrar(jogador * target){
  if (auto _aux = find(target->get_name())){
    bool decision = sobrepor();
    if(decision){
      *_aux = *target;
    } else {
      return;
    }
  }
  jogadores.push_back(target);
}
void cadastro::remover(jogador * target){
  unsigned int counter = 0;
  for (auto _aux : jogadores){
    if (_aux == target){
      jogadores.erase(jogadores.begin() + counter);
    } 
    counter++;
  }
  throw exception("player_not_found");
}
void cadastro::load(){
  std::fstream archive(default_name, std::ios::in);
  if (!archive){
    return;
  }
  archive.seekg(0, archive.end);
  int final_position = archive.tellg();
  archive.seekg(0, archive.beg);
  char * test_controll = new char[20];
  archive.read(test_controll, string_controll.length());
  input_controll(test_controll);
  if ( ! (input_controll == string_controll) ){
    throw exception("data_corrupted")
  }
  unsigned int n_registers;
  archive.read(&n_registers, sizeof(unsigned int));
  while (n_registers){
    char * _input_name = new char[20];
    unsigned int n_of_wins;
    unsigned int n_of_loses;
    archive.read(_input_name, 20);
    archive.read(&n_of_wins, sizeof(unsigned int));
    archive.read(&n_of_loses, sizeof(unsigned int));
    cadastrar(new jogador(_input_name, n_of_wins, n_of_loses));
    n_registers--;
  }
  if (archive != final_position){
    /*arquico corrompido*/
    bool decision = continuar();
    if (decision){
      return;
    } else {
      throw exception("shutdown");
    }
  }
}
void cadastro::save(){
  
}
