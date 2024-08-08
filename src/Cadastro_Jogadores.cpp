#include "../include/Cadastro_Jogadores.hpp"
cadastro::cadastro(){
  load();
}
cadastro::~cadastro(){
  save();
}
jogador * cadastro::find(std::string _name){ //encontra jogador por nome
  for (auto _aux : jogadores){
    if(_aux->get_name() == _name){
      return _aux;
    }
  }
  return NULL;
}
void cadastro::cadastrar(jogador * target){ //insere *jogador no vetor
  if (auto _aux = find(target->get_name())){
    bool decision = decisao();
    if(decision){
      _aux = target;
      return;
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
      return;
    } 
    counter++;
  }
  bool decision = decisao();
  if (decision){
    return;
  } else {
    throw std::run_time_error("player_not_found");
  }
}
void cadastro::load(){
  std::fstream archive(default_name, std::ios::in);
  if (!archive){
    return;
  }
  archive.seekg(0, archive.end);
  int final_position = archive.tellg();
  archive.seekg(0, archive.beg);
  char test_controll[20] = {};
  archive.read(test_controll, string_controll.length());
  std::string input_controll(test_controll);
  if ( ! (input_controll == string_controll) ){
    throw std::run_time_error("data_corruption")
  }
  unsigned int n_registers;
  archive.read(&n_registers, sizeof(unsigned int));
  while (n_registers){
    char _input_name[20] = {};
    unsigned int n_of_wins;
    unsigned int n_of_loses;
    archive.read(_input_name, 20);
    archive.read((char*) &n_of_wins, sizeof(unsigned int));
    archive.read((char*) &n_of_loses, sizeof(unsigned int));
    cadastrar(new jogador(_input_name, n_of_wins, n_of_loses));
    n_registers--;
  }
  if (archive.tellg() != final_position){
    /*arquivo corrompido*/
    bool decision = decisao();
    if (decision){
      return;
    } else {
      throw std::run_time_error("data_corruption");
    }
  }
  archive.close();
}
void cadastro::save(){
  std::fstream archive(default_name, std::ios::out | std::ios::trunc);
  if (!archive){
    //arquivo não pode ser salvo, deseja sair?
    bool decision = decisao();
    if (decision){
      return;
    } else {
      std::run_time_error("fail");//catch na main -> retorna ao looping de jogo
    }
  }
  archive.write(string_controll.c_str(), string_controll.length());
  unsigned int n_players = jogadores.size();
  archive.write((char*) &n_players, sizeof(unsigned int));
  for (auto _aux : jogadores){
    char p_name[20] = {};
    _aux->get_name().copy(p_name, _aux->get_name().size(), 0);
    unsigned int input_wins = _aux->get_wins();
    unsigned int input_loses = _aux->get_loses();
    archive.write(p_name, 20);
    archive.write((char *) &input_wins, sizeof(unsigned int));
    archive.write((char *) &input_loses, sizeof(unsigned int));
  }
  archive.close();
}
