#include "Interface_Menu.hpp"

Interface_Menu::Interface_Menu() 
    : posicao(0), num_botoes(0), num_janela(0), pressed(false), seleção_ativa(false),
      espaco_vertical(0.0f), largura_janela(624.0f), altura_titulo(0.0f), altura_inferior_titulo(0.0f) {
    this->janela = make_unique<sf::RenderWindow>();
    this->winclose = make_unique<sf::RectangleShape>();
    this->fonte = make_unique<sf::Font>();
    this->image = make_unique<sf::Texture>();
    this->background = make_unique<sf::Sprite>();
    janela->setVerticalSyncEnabled(true);
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

void Interface_Menu::Definir_Fonte() {
    try {
        tamanho_fonte.clear();
        if (!fonte->loadFromFile("./assets/fontes/pixelmix.ttf")) {
            throw runtime_error("Erro ao carregar fonte");
        }
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
    }
}

void Interface_Menu::Definir_Contorno_Inicial_Texto() {
    try {
        texto[0].setOutlineThickness(0.6);
        texto[0].setOutlineColor(sf::Color(255,255,255));
    } catch (const std::exception& e) {
        cerr << "Erro ao definir contorno inicial: " << e.what() << endl;
    }
}

void Interface_Menu::Definir_Contorno_Texto_Avancar(int posicao) {
    try {
        texto[posicao].setOutlineThickness(0.6);
        texto[posicao].setOutlineColor(sf::Color(255,255,255));
        texto[posicao - 1].setOutlineThickness(0);
    } catch (const std::exception& e) {
        cerr << "Erro ao avançar contorno: " << e.what() << endl;
    }       
}

void Interface_Menu::Definir_Contorno_Texto_Voltar(int posicao) {
    try {
        texto[posicao].setOutlineThickness(0.6);
        texto[posicao].setOutlineColor(sf::Color(255,255,255));
        texto[posicao + 1].setOutlineThickness(0);
    } catch (const std::exception& e) {
        cerr << "Erro ao voltar contorno: " << e.what() << endl;
    }      
}

void Interface_Menu::Definir_Textos() {
    try {
        for (size_t i = 0; i < opcoes_de_escolha.size(); ++i) {
            float pos_y = altura_inferior_titulo + (i * espaco_vertical);
            coords.push_back(sf::Vector2f(largura_janela / 2, pos_y));
            tamanho_fonte.push_back(18); 
        }

        texto.resize(opcoes_de_escolha.size());

        for(size_t i = 0; i < texto.size(); ++i) {
            texto[i].setFont(*fonte);
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
    } catch (const std::exception& e) {
        cerr << "Erro ao definir textos: " << e.what() << endl;
    }
}


void Interface_Menu::Draw_All() {
    try {
        this->janela->clear();
        this->janela->draw(*background);

        for (const auto& text : texto) {
            janela->draw(text);
        }

        this->janela->display();
    } catch (const exception& e) {
        cerr << "Erro ao desenhar todos os elementos: " << e.what() << endl;
    }
}

void Interface_Menu::Define_Aviso() {
    try {
        aviso.setFont(*fonte);
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