#include "Cadastro.hpp"
#include "data_managment.hpp"
cadastro::cadastro(){
  load(this);
}
void cadastro::cadastrar(jogador * player_1){
  if (find(player_1->get_name()){
    mensagem avisa que já exist, colhe resposta se deseja sobrecadastro;
    if (!sobre){
      return;
    }
  }
  jogadores.push_back(player_1);
}
jogador * cadastro::find(string input_name){
    for (auto run : jogadores){
      if (run->get_name() == input_name){
        return run;
      }
    }
    return NULL;
}
