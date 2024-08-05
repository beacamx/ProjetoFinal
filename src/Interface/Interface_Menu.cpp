#include "Interface_Menu.hpp"

Interface_Menu::Interface_Menu() 
    : posicao(0), num_botoes(0), num_janela(0), pressed(false), theselect(false),
      espaco_vertical(0.0f), largura_janela(624.0f), altura_titulo(0.0f), altura_inferior_titulo(0.0f) {
    this->janela = make_unique<sf::RenderWindow>();
    this->winclose = make_unique<sf::RectangleShape>();
    this->font = make_unique<sf::Font>();
    this->image = make_unique<sf::Texture>();
    this->background = make_unique<sf::Sprite>();
}

Interface_Menu::~Interface_Menu() {}

void Interface_Menu::Set_Efeito_Sonoro_Selecao_Botao() {
    if (!buffer_selecao.loadFromFile("./assets/audio/c.wav")) {
        cerr << "Erro ao carregar efeito sonoro" << endl;
        exit(1);
    }

    som_selecao.setBuffer(buffer_selecao);
    som_selecao.setVolume(50);
}

void Interface_Menu::Centralizar_Janela() {
    sf::Vector2i janela_centralizada(
        (sf::VideoMode::getDesktopMode().width - 624) / 2, 
        (sf::VideoMode::getDesktopMode().height - 546 )/ 2
    );
    janela->setPosition(janela_centralizada);
}

void Interface_Menu::Set_Janela() {
    janela->create(sf::VideoMode(624,546), "", sf::Style::Titlebar | sf::Style::Close);
}

void Interface_Menu::Set_Font() {
    tamanho_fonte.clear();
    if (!font->loadFromFile("./assets/fontes/pixelmix.ttf")) 
        cerr << "Erro ao carregar fonte" << endl;
}

void Interface_Menu::Set_Contorno_Inicial() {
    texto[0].setOutlineThickness(0.6);
    texto[0].setOutlineColor(sf::Color(255,255,255));
}

void Interface_Menu::Set_Contorno_Avancar(int posicao) {
    texto[posicao].setOutlineThickness(0.6);
    texto[posicao].setOutlineColor(sf::Color(255,255,255));
    texto[posicao - 1].setOutlineThickness(0);              
}

void Interface_Menu::Set_Contorno_Voltar(int posicao) {
    texto[posicao].setOutlineThickness(0.6);
    texto[posicao].setOutlineColor(sf::Color(255,255,255));
    texto[posicao + 1].setOutlineThickness(0);                
}

void Interface_Menu::Set_Textos() {
    for (size_t i = 0; i < opcoes_de_escolha.size(); ++i) {
        float pos_y = altura_inferior_titulo + (i * espaco_vertical);
        coords.push_back(sf::Vector2f(largura_janela / 2, pos_y));
        tamanho_fonte.push_back(18); 
    }

    texto.resize(opcoes_de_escolha.size());

    for(size_t i{}; i < texto.size(); ++i) {
        texto[i].setFont(*font);
        texto[i].setString(opcoes_de_escolha[i]);
        texto[i].setCharacterSize(tamanho_fonte[i]);
        texto[i].setOutlineColor(sf::Color::Black);
        texto[i].setPosition(coords[i]);

        sf::FloatRect text_bounds = texto[i].getLocalBounds();
        float largura_texto = text_bounds.width;
        float altura_texto = text_bounds.height;

        texto[i].setOrigin(largura_texto / 2.0f, altura_texto / 2.0f);
        texto[i].setPosition(coords[i].x, coords[i].y);
    }
}


void Interface_Menu::Draw_All() {
    this->janela->clear();
    this->janela->draw(*background);
    int tamanho_texto = texto.size();
    if(tamanho_texto) {
        for (const auto& text : texto) {
            janela->draw(text);
        }
    }
    this->janela->display();
}

void Interface_Menu::Run_Menu() {
    while (janela->isOpen()) {
        this->Loop_Events();
        Draw_All();
    }
}