#include <iostream>

class jogador
{
public:
    jogador(std::string name, std::string nick) : jogador(name, nick, 0, 0, 0, 0) {}
    jogador(std::string name, std::string nick, unsigned int wins_lig4, unsigned int wins_Reversi, unsigned int loses_lig4, unsigned int loses_Reversi) : _name(name), _nick(nick), n_of_wins_lig4(wins_lig4), n_of_wins_Reversi(wins_Reversi), n_of_loses_lig4(loses_lig4), n_of_loses_Reversi(loses_Reversi) {}
    std::string get_name() { return _name; };
    unsigned int get_wins() { return n_of_wins_lig4 + n_of_wins_Reversi; };
    unsigned int get_loses() { return n_of_loses_lig4 + n_of_loses_Reversi; };
    unsigned int get_wins_lig4() { return n_of_wins_lig4;};
    unsigned int get_wins_Reversi() { return n_of_wins_Reversi;};
    unsigned int get_loses_lig4() { return n_of_loses_lig4;};
    unsigned int get_loses_Reversi() { return n_of_loses_Reversi;};
    void win_lig4(){ n_of_wins_lig4++; };
    void win_Reversi(){ n_of_wins_Reversi++; };
    void lose_lig4(){ n_of_loses_lig4++; };
    void lose_Reversi(){ n_of_loses_Reversi++; };
private:
    std::string _name;
    std::string _nick;
    unsigned int n_of_wins_lig4;
    unsigned int n_of_wins_Reversi;
    unsigned int n_of_loses_lig4;
    unsigned int n_of_loses_Reversi;
};
struct player_compare{
    bool operator() (jogador * p1, jogador * p2) const{
        return p1->get_name() < p2->get_name();
    }
};
