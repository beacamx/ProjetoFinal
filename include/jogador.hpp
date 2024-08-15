#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <iostream>
#include <string>

class Jogador
{
public:
    Jogador(std::string name, std::string nick);
    Jogador(std::string name, std::string nick, unsigned int wins_lig4, unsigned int wins_Reversi, unsigned int loses_lig4, unsigned int loses_Reversi);

    std::string get_name();
    std::string get_nick();
    int getPeca();
    void setPeca(int p);
    unsigned int get_wins();
    unsigned int get_loses();
    unsigned int get_wins_lig4();
    unsigned int get_wins_Reversi();
    unsigned int get_loses_lig4();
    unsigned int get_loses_Reversi();
    
    void win_lig4();
    void win_Reversi();
    void lose_lig4();
    void lose_Reversi();

private:
    std::string _name;
    std::string _nick;
    unsigned int n_of_wins_lig4;
    unsigned int n_of_wins_Reversi;
    unsigned int n_of_loses_lig4;
    unsigned int n_of_loses_Reversi;
    int peca;
};

struct player_compare {
    bool operator() (Jogador* p1, Jogador* p2) const;
};

#endif JOGADOR_HPP