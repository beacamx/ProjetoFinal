#include <iostream>
#include <fstream>
#include "data_manager.hpp"
void data_manager::load(cadastro& player_ref)
{
    try
    {
        std::ifstream archive(data_manager::default_name, std::ios::binary);
        if (!archive)
            throw open_file_erro("load");
    }
    jogador _aux;
    while (archive.read(reinterpret_cast<char *>(&_aux)), sizeof(_aux))
    {
        player_ref.cadastrar(_aux);
    }
    archive.close();
}
void data_manager::save(cadastro& player_ref){
    try
    {
        std::ofstream archive(data_manager::default_name, std::ios::binary);
        if (!archive){
            throw open_file_erro("save");
        }
    }
    for (auto _aux : player_ref.get_vector()){
        archive.write(reinterpret_cast<const char*>(&_aux), sizeof(_aux));
    }
    archive.close();
}
