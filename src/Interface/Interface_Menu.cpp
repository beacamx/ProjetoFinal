#include "Interface_Menu.hpp"

Interface_Menu::Interface_Menu() 
    : Interface_Base(624, 546), posicao(0), num_botoes(0), num_janela(0), pressed(false), seleção_ativa(false),
      espaco_vertical(0.0f), espaco_vertical_botao_play(0.0f), altura_titulo(0.0f), altura_inferior_titulo(0.0f) {
    this->image = make_unique<sf::Texture>();
    this->background = make_unique<sf::Sprite>();
    audio.Set_Efeito_Sonoro_Selecao_Botao();
}

void Interface_Menu::Set_Janela() {
    try {
        janela->create(sf::VideoMode(624,546), "", sf::Style::Titlebar | sf::Style::Close);
    } catch (const std::exception& e) {
        cerr << "Erro ao criar a janela: " << e.what() << endl;
    }
}

void Interface_Menu::Atualizar_Janela() {
    try {
        this->janela->clear();
        this->janela->draw(*background);

        auto& textos_aux = textos.Get_Vetor_Textos();
        for (const auto& text : textos_aux) {
            janela->draw(text);
        }

        this->janela->display();
    } catch (const exception& e) {
        cerr << "Erro ao desenhar todos os elementos: " << e.what() << endl;
    }
}

void Interface_Menu::Define_Aviso() {
    try {
        const sf::Font& fonte = textos.Get_Fonte();
        aviso.setFont(fonte); 
        aviso.setCharacterSize(18);
        aviso.setFillColor(sf::Color::Red);
    } catch (const exception& e) {
        cerr << "Erro ao definir aviso: " << e.what() << endl;
    }
}

void Interface_Menu::Run() {
    while (janela->isOpen()) {
        this->Loop_Events();
        Atualizar_Janela();
    }
}