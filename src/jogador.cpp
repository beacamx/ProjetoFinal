#include "../include/jogador.hpp"

jogador::jogador(std::string name, std::string nick) 
    : jogador(name, nick, 0, 0, 0, 0) {}

jogador::jogador(std::string name, std::string nick, unsigned int wins_lig4, unsigned int wins_Reversi, unsigned int loses_lig4, unsigned int loses_Reversi) 
    : _name(name), _nick(nick), n_of_wins_lig4(wins_lig4), n_of_wins_Reversi(wins_Reversi), n_of_loses_lig4(loses_lig4), n_of_loses_Reversi(loses_Reversi) {}

std::string jogador::get_name() { 
    return _name; 
}

unsigned int jogador::get_wins() { 
    return n_of_wins_lig4 + n_of_wins_Reversi; 
}

unsigned int jogador::get_loses() { 
    return n_of_loses_lig4 + n_of_loses_Reversi; 
}

unsigned int jogador::get_wins_lig4() { 
    return n_of_wins_lig4; 
}

unsigned int jogador::get_wins_Reversi() { 
    return n_of_wins_Reversi; 
}

unsigned int jogador::get_loses_lig4() { 
    return n_of_loses_lig4; 
}

unsigned int jogador::get_loses_Reversi() { 
    return n_of_loses_Reversi; 
}

void jogador::win_lig4() { 
    n_of_wins_lig4++; 
}

void jogador::win_Reversi() { 
    n_of_wins_Reversi++; 
}

void jogador::lose_lig4() { 
    n_of_loses_lig4++; 
}

void jogador::lose_Reversi() { 
    n_of_loses_Reversi++; 
}

bool player_compare::operator() (jogador * p1, jogador * p2) const {
    return p1->get_name() < p2->get_name();
}
