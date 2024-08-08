#include <iostream>

class jogador
{
public:
    jogador(std::string name) : jogador(name, 0, 0, 0, 0) {}
    jogador(std::string name, unsigned int wins_lig4, unsigned int wins_Reversi, unsigned int loses_lig4, unsigned int loses_Reversi) : _name(name), n_of_wins_lig4(wins_lig4), n_of_wins_Reversi(wins_Reversi), n_of_loses_lig4(loses_lig4), n_of_loses_Reversi(loses_Reversi) {}
    std::string get_name() { return _name; };
    unsigned int get_wins() { return n_of_wins_lig4 + n_of_wins_Reversi; };
    unsigned int get_loses() { return n_of_loses_lig4 + n_of_loses_Reversi; };
    unsigned int get_wins_lig4() { return n_of_wins_lig4;};
    unsigned int get_wins_Reversi() { return n_of_wins_Reversi;};
    unsigned int get_loses_lig4() { return n_of_loses_lig4;};
    unsigned int get_loses_Reversi() { return n_of_loses_Reversi;};
private:
    std::string _name;
    unsigned int n_of_wins_lig4;
    unsigned int n_of_wins_Reversi;
    unsigned int n_of_loses_lig4;
    unsigned int n_of_loses_Reversi;
};
class player_compare{
    bool operator() (const jogador * p1, const jogador * p2){
        return p1->get_name() < p2->get_name();
    }
};
