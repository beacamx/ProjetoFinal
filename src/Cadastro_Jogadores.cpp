#include "../include/Cadastro_Jogadores.hpp"
cadastro::cadastro()
{
  load();
}
cadastro::~cadastro()
{
  save();
}
Jogador *cadastro::find_by_name(std::string _name)
{ // encontra jogador por nome
  for (auto _aux : jogadores)
  {
    if (_aux->get_name() == _name)
    {
      return _aux;
    }
  }
  return NULL;
}
Jogador * cadastro::find_by_nick(std::string _nick){
  for (auto _aux : jogadores)
  {
    if (_aux->get_nick() == _nick){
      return _aux;
    }
  }
  return NULL;
}
void cadastro::cadastrar(Jogador *target)
{ // insere *jogador no vetor<*jogador>
  if (auto _aux = find_by_name(target->get_name()))
  {
    throw std::runtime_error("override_player");
  }
  jogadores.insert(target);
}

void cadastro::remover(Jogador *target)
{ // remove *jogador na lista. Caso não encontre, lança runtime exception
  std::set<Jogador*, player_compare>::iterator posi = jogadores.find(find_by_name(target->get_name()));
  if (posi != jogadores.end())
  {
    jogadores.erase(posi);
  }
  else
  {
    throw std::runtime_error("player_not_found");
  }
}
std::vector<Jogador*> cadastro::player_list(){
  std::vector<Jogador*> build;
  for (auto _aux : jogadores){
    build.push_back(_aux);
  }
  return build;
}
void cadastro::load()
{ // carrega do arquivo padrao
  std::fstream archive(default_name, std::ios::in);
  if (!archive)
  {
    archive.close();
    return;
  }
  archive.seekg(0, archive.end);
  int final_position = archive.tellg();
  archive.seekg(0, archive.beg);
  char test_controll[70] = {};
  archive.read(test_controll, std::string(string_controll).length());
  if (!(std::string(test_controll) == std::string(string_controll)))
  {
    throw std::runtime_error("data_corruption");
  }
  unsigned int n_registers;
  archive.read((char *)&n_registers, sizeof(unsigned int));
  while (n_registers)
  {
    char _input_name[20] = {};
    char _input_nick[20] = {};
    unsigned int n_of_wins_lig4;
    unsigned int n_of_wins_Reversi;
    unsigned int n_of_loses_lig4;
    unsigned int n_of_loses_Reversi;
    archive.read(_input_name, 20);
    archive.read(_input_nick, 20);
    archive.read((char *)&n_of_wins_lig4, sizeof(unsigned int));
    archive.read((char *)&n_of_wins_Reversi, sizeof(unsigned int));
    archive.read((char *)&n_of_loses_lig4, sizeof(unsigned int));
    archive.read((char *)&n_of_loses_Reversi, sizeof(unsigned int));
    cadastrar(new Jogador(_input_name, _input_nick, n_of_wins_lig4, n_of_wins_Reversi, n_of_loses_lig4, n_of_loses_Reversi));
    n_registers--;
  }
  if (archive.tellg() != final_position)
  {
    /*arquivo corrompido*/
    throw std::runtime_error("data_corruption");
  }
  archive.close();
}
void cadastro::save()
{ // salva no arquivo padrao
  std::fstream archive(default_name, std::ios::out | std::ios::trunc | std::ios::binary);
  if (!archive)
  {
    // arquivo não pode ser salvo, deseja sair?
    std::runtime_error("fail"); // catch na main -> retorna ao looping de jogo
  }
  archive.write(string_controll, std::string(string_controll).length());
  unsigned int n_players = jogadores.size();
  archive.write((char *)&n_players, sizeof(unsigned int));
  for (auto _aux : jogadores)
  {
    char p_name[20] = {};
    _aux->get_name().copy(p_name, _aux->get_name().size(), 0);
    char p_nick[20] = {};
    _aux->get_nick().copy(p_nick, _aux->get_name().size(), 0);
    unsigned int input_wins_lig4 = _aux->get_wins_lig4();
    unsigned int input_wins_Reversi = _aux->get_wins_Reversi();
    unsigned int input_loses_lig4 = _aux->get_loses_lig4();
    unsigned int input_loses_Reversi = _aux->get_loses_Reversi();
    archive.write(p_name, 20);
    archive.write(p_nick, 20);
    archive.write((char *)&input_wins_lig4, sizeof(unsigned int));
    archive.write((char *)&input_wins_Reversi, sizeof(unsigned int));
    archive.write((char *)&input_loses_lig4, sizeof(unsigned int));
    archive.write((char *)&input_loses_Reversi, sizeof(unsigned int));
  }
  archive.close();
}
