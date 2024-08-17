#include "Interface_Menu.hpp"

Interface_Menu::Interface_Menu() 
    : posicao(0), num_botoes(0), num_janela(0), pressed(false), seleção_ativa(false),
      espaco_vertical(0.0f), largura_janela(624.0f), altura_titulo(0.0f), altura_inferior_titulo(0.0f) {
    this->janela = make_unique<sf::RenderWindow>();
    this->winclose = make_unique<sf::RectangleShape>();
    this->image = make_unique<sf::Texture>();
    this->background = make_unique<sf::Sprite>();
    janela->setVerticalSyncEnabled(true);
    registro_geral.save();
}

Interface_Menu::~Interface_Menu() {
    som_selecao.stop(); 
}

void Interface_Menu::Set_Efeito_Sonoro_Selecao_Botao() {
    try {
        if (!buffer_selecao.loadFromFile("./assets/audio/c.wav")) {
            throw runtime_error("Erro ao carregar efeito sonoro");
        }
        som_selecao.setBuffer(buffer_selecao);
        som_selecao.setVolume(50);
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
    }
}

void Interface_Menu::Centralizar_Janela() {
    try {
        sf::Vector2i janela_centralizada(
            (sf::VideoMode::getDesktopMode().width - 624) / 2, 
            (sf::VideoMode::getDesktopMode().height - 546 )/ 2
        );
        janela->setPosition(janela_centralizada);
    } catch (const std::exception& e) {
        cerr << "Erro ao centralizar a janela: " << e.what() << endl;
    }
}

void Interface_Menu::Set_Janela() {
    try {
        janela->create(sf::VideoMode(624,546), "", sf::Style::Titlebar | sf::Style::Close);
    } catch (const std::exception& e) {
        cerr << "Erro ao criar a janela: " << e.what() << endl;
    }
}

void Interface_Menu::Draw_All() {
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

void Interface_Menu::Run_Menu() {
        while (janela->isOpen()) {
            this->Loop_Events();
            Draw_All();
        }
}