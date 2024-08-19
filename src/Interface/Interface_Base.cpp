#include "Interface_Base.hpp"

cadastro Interface_Base::registro_geral;
string Interface_Base::apelido_jogador1;
string Interface_Base::apelido_jogador2;

void Interface_Base::Set_Apelido_Jogador1(const string& apelido) {
    apelido_jogador1 = apelido;
}

void Interface_Base::Set_Apelido_Jogador2(const string& apelido) {
    apelido_jogador2 = apelido;
}

string Interface_Base::Get_Apelido_Jogador1() {
    return apelido_jogador1;
}

string Interface_Base::Get_Apelido_Jogador2() {
    return apelido_jogador2;
}

cadastro& Interface_Base::Get_Registro_Geral() { 
    try {
        return registro_geral;
    } catch (const exception& e) {
        cerr << "Erro ao acessar o registro geral: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

Interface_Base::Interface_Base(int largura, int altura) 
    : largura_janela(largura), altura_janela(altura) {
    try {
        this->janela = make_unique<sf::RenderWindow>();
        if (!janela) {
            throw runtime_error("Falha ao criar a janela.");
        }
        this->winclose = make_unique<sf::RectangleShape>();
        if (!winclose) {
            throw runtime_error("Falha ao criar o retângulo de fechamento.");
        }

        janela->setVerticalSyncEnabled(true);
    } catch (const exception& e) {
        cerr << "Erro na inicialização da Interface_Base: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

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