#include "../include/Cadastro_Jogadores.hpp"
#include <iostream>
jogador * cadastro::find(std::string _name){
  for (auto _aux : jogadores){
    if (_aux->get_name() == _name){
      return _aux;
    }
  }
  return NULL;
}
void cadastro::cadastrar(jogador * obj){
    if (_aux = find(obj->get_name()){
      /*Duplicidade de nome. Possibilidade de sobreposição, ou cancelamento*/
      boll decision = pergunta();
      if (decision){
        *_aux = *obj;
      } else {
        return;
      }
    }
    jogadores.push_back(obj);
}
void remover(jogador * target){
  unsigned int counter = 0;
  for (auto _aux : jogadores){
    if (_aux == target){
      jogadores.erase(jogadores.begin() + counter);
    }
    counter++;
  }
  throw register_error("player_not_find");
}
