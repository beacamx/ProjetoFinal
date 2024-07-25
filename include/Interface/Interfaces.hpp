#ifndef INTERFACES_HPP
#define INTERFACES_HPP

#include "Interface_Lig4.hpp"
#include "Interface_Reversi.hpp"

int inicia_Lig4(int argc, char **argv) {
    auto p = std::make_unique<Interface_Lig4>();
    p->run();
    return 0;
}

int inicia_Reversi(int argc, char **argv) {
    auto p = std::make_unique<Interface_Reversi>();
    p->run();
    return 0;
}

#endif