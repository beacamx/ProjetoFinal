#include "../include/jogador.hpp"

Jogador::Jogador(std::string name, std::string nick) 
    : Jogador(name, nick, 0, 0, 0, 0) {}

Jogador::Jogador(std::string name, std::string nick, unsigned int wins_lig4, unsigned int wins_Reversi, unsigned int loses_lig4, unsigned int loses_Reversi) 
    : _name(name), _nick(nick), n_of_wins_lig4(wins_lig4), n_of_wins_Reversi(wins_Reversi), n_of_loses_lig4(loses_lig4), n_of_loses_Reversi(loses_Reversi) {}

std::string Jogador::get_name() { 
    return _name; 
}

std::string Jogador::get_nick() { 
    return _nick; 
}

int getPeca() {
    return this->peca;
}

void setPeca(int p) {
    this->peca = p;
}

unsigned int Jogador::get_wins() { 
    return n_of_wins_lig4 + n_of_wins_Reversi; 
}

unsigned int Jogador::get_loses() { 
    return n_of_loses_lig4 + n_of_loses_Reversi; 
}

unsigned int Jogador::get_wins_lig4() { 
    return n_of_wins_lig4; 
}

unsigned int Jogador::get_wins_Reversi() { 
    return n_of_wins_Reversi; 
}

unsigned int Jogador::get_loses_lig4() { 
    return n_of_loses_lig4; 
}

unsigned int Jogador::get_loses_Reversi() { 
    return n_of_loses_Reversi; 
}

void Jogador::win_lig4() { 
    n_of_wins_lig4++; 
}

void Jogador::win_Reversi() { 
    n_of_wins_Reversi++; 
}

void Jogador::lose_lig4() { 
    n_of_loses_lig4++; 
}

void Jogador::lose_Reversi() { 
    n_of_loses_Reversi++; 
}

bool player_compare::operator() (Jogador * p1, Jogador * p2) const {
    return p1->get_name() < p2->get_name();
}
