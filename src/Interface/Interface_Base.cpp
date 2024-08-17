#include "Interface_Base.hpp"

void Interface_Base::Centralizar_Janela() {
    try {
        sf::Vector2i janela_centralizada(
            (sf::VideoMode::getDesktopMode().width - this->largura_janela) / 2, 
            (sf::VideoMode::getDesktopMode().height - this->altura_janela) / 2
        );
        janela->setPosition(janela_centralizada);
    } catch (const std::exception& e) {
        cerr << "Erro ao centralizar a janela: " << e.what() << endl;
    }
}