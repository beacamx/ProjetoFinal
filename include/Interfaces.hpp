#ifndef INTERFACES_HPP
#define INTERFACES_HPP

#include "Interface_Lig4.hpp"

int inicia_Lig4(int argc, char **argv) {
    auto p = std::make_unique<Lig4>();
    p->run();
    return 0;
}

#endif