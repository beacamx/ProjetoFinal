#include "Interface_Jogo.hpp"

using namespace std;

Interface_Jogo::Interface_Jogo(const std::string& nome_do_jogo)
    : nome_do_jogo(nome_do_jogo), janela(std::make_unique<sf::RenderWindow>()) {
    event = make_shared<sf::Event>();
}

void Interface_Jogo::draw() {
    janela->clear(sf::Color::Black);
    for(int i = 0; i < linhas; ++i) {
        for(int j = 0; j < colunas; ++j) {
            int index = grid[i][j] - 1; 
            int tam_sprites = sprites.size();
            if (index >= 0 && index < tam_sprites) {
                sf::Sprite& sprite = sprites[index];
                sprite.setPosition(j * largura_quadrado, i * largura_quadrado);
                janela->draw(sprite);
            } else {
                cerr << "Índice de sprite fora dos limites: " << index << std::endl;
            }
        }
    }

    janela->display();
}

void Interface_Jogo::events() {
    static bool mousePressed = false;

    while (janela->pollEvent(*event)) {
        if (event->type == sf::Event::Closed) {
            janela->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            janela->close();
        }

        if (event->type == sf::Event::MouseButtonPressed) {
            if (event->mouseButton.button == sf::Mouse::Left && !mousePressed) {
                mousePressed = true;

                sf::Vector2i posicao = sf::Mouse::getPosition(*janela);
                this->x = posicao.x / largura_quadrado;
                this->y = posicao.y / largura_quadrado;

                if (x >= 0 && x < colunas && y >= 0 && y < linhas) { // para testar se cada sprite está sendo lido corretamente
                    cout << "Você clicou no número: " << grid[x][y] << endl;
                }
            }
        }

        if (event->type == sf::Event::MouseButtonReleased) {
            if (event->mouseButton.button == sf::Mouse::Left) {
                mousePressed = false;
            }
        }
    }
}

void Interface_Jogo::Set_Janela() {
    janela->create(sf::VideoMode(largura_janela, altura_janela), nome_do_jogo, sf::Style::Titlebar | sf::Style::Close);
    janela->setFramerateLimit(60);
}

void Interface_Jogo::Define_Dimensoes_Janela() {
    this->largura_janela = colunas * largura_quadrado;
    this->altura_janela = linhas * largura_quadrado;
    this->num_quadrados = linhas * colunas;
}

void Interface_Jogo::Centralizar_Janela() {
    sf::Vector2i janela_centralizada(
        (sf::VideoMode::getDesktopMode().width - this->largura_janela) / 2, 
        (sf::VideoMode::getDesktopMode().height - this->altura_janela) / 2
    );
    janela->setPosition(janela_centralizada);
}

void Interface_Jogo::run(){
    cout << "Iniciando a execução do jogo..." << endl;
    while (janela->isOpen()) {
        this->events();
        this->draw();
        // this->logic();
    }
}
