#include "../include/Cadastro_Jogadores.hpp"
/*bool decisao(){
    std::cout << "decisao() 1 = true 0 = false" << std::endl;
    int esse;
    std::cin >> esse;
    if (esse){
        return true;
    } else {
        return false;
    }
} \\\\\\\\\\\\\\\ função decisao usada para teste
*/
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
void cadastro::cadastrar(jogador * target){ //insere *jogador no vetor<*jogador>
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
void cadastro::remover(jogador * target){ //remove *jogador no vetor<*jogador>
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
    throw std::runtime_error("player_not_found");
  }
}
void cadastro::load(){//carrega do arquivo padrao
  std::fstream archive(default_name, std::ios::in);
  if (!archive){
    archive.close();
    return;
  }
  archive.seekg(0, archive.end);
  int final_position = archive.tellg();
  archive.seekg(0, archive.beg);
  char test_controll[70] = {};
  archive.read(test_controll, std::string(string_controll).length());
  if ( ! (std::string(test_controll) == std::string(string_controll)) ){
    throw std::runtime_error("data_corruption");
  }
  unsigned int n_registers;
  archive.read((char *)&n_registers, sizeof(unsigned int));
  while (n_registers){
    char _input_name[20] = {};
    unsigned int n_of_wins_lig4;
    unsigned int n_of_wins_Reversi;
    unsigned int n_of_loses_lig4;
    unsigned int n_of_loses_Reversi;
    archive.read(_input_name, 20);
    archive.read((char*) &n_of_wins_lig4, sizeof(unsigned int));
    archive.read((char*) &n_of_wins_Reversi, sizeof(unsigned int));
    archive.read((char*) &n_of_loses_lig4, sizeof(unsigned int));
    archive.read((char*) &n_of_loses_Reversi, sizeof(unsigned int));
    cadastrar(new jogador(_input_name, n_of_wins_lig4, n_of_wins_Reversi, n_of_loses_lig4, n_of_loses_Reversi));
    n_registers--;
  }
  if (archive.tellg() != final_position){
    /*arquivo corrompido*/
    bool decision = decisao();
    if (decision){
      return;
    } else {
      throw std::runtime_error("data_corruption");
    }
  }
  archive.close();
}
void cadastro::save(){//salva no arquivo padrao
  std::fstream archive(default_name, std::ios::out | std::ios::trunc | std::ios::binary);
  if (!archive){
    //arquivo não pode ser salvo, deseja sair?
    bool decision = decisao();
    if (decision){
      return;
    } else {
      std::runtime_error("fail");//catch na main -> retorna ao looping de jogo
    }
  }
  archive.write(string_controll, std::string(string_controll).length());
  unsigned int n_players = jogadores.size();
  archive.write((char*) &n_players, sizeof(unsigned int));
  for (auto _aux : jogadores){
    char p_name[20] = {};
    _aux->get_name().copy(p_name, _aux->get_name().size(), 0);
    unsigned int input_wins_lig4 = _aux->get_wins_lig4();
    unsigned int input_wins_Reversi = _aux->get_wins_Reversi();
    unsigned int input_loses_lig4 = _aux->get_loses_lig4();
    unsigned int input_loses_Reversi = _aux->get_loses_Reversi();
    archive.write(p_name, 20);
    archive.write((char *) &input_wins, sizeof(unsigned int));
    archive.write((char *) &input_loses, sizeof(unsigned int));
  }
  archive.close();
}
