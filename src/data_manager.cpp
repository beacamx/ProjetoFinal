#include <iostream>
#include <fstream>
#include "data_manager.hpp"
void data_manager::load(cadastro& player_ref)
{
    try
    {
        std::ifstream archive(data_manager::default_name, std::ios::binary);
        if (!archive)
            throw data_manager::open_file_erro("load");
    }
    jogador _aux;
    while (archive.read(reinterpret_cast<char *>(&_aux)), sizeof(_aux))
    {
        player_ref.cadastrar(_aux);
    }
    archive.close();
}
void data_manager::save(cadastro& players_ref){
    try
    {
        std::ofstream archive(data_manager::default_name, std::ios::binary);
        if (!archive){
            throw data_manager::open_file_erro("save");
        }
    }
        std::vector<jogadores*>& vector_reference = players_ref.get_vector();  
    for (auto _aux : vector_reference){
        archive.write(reinterpret_cast<const char*>(&_aux), sizeof(_aux));
    }
    archive.close();
}
data_manager::open_file_erro::open_file_erro(std::string input_type) : type(input_type) {}
std::string data_manager::open_file_erro::get_type(){ return type };
