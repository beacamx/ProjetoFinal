#include "Cadastro_Jogadores.hpp"
#ifndef DATA_MANAGER_HPP
#define DATA_MANAGER_HPP
namespace data_manager{
std::string default_name("game_data.lig4&Reversi");
void load(cadastro&);
void save(cadastro&);
}
#endif
