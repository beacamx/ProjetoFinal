#include "Interface_Jogo.hpp"

Interface_Jogo::Interface_Jogo(const std::string& nome_do_jogo)
    : nome_do_jogo(nome_do_jogo) {
    event = std::make_shared<sf::Event>();
}

void Interface_Jogo::draw() {
    window->clear(sf::Color::Black);
    for(int i = 0; i < linhas; ++i) {
        for(int j = 0; j < colunas; ++j) {
            int index = grid[i][j] - 1; 
            int tam_sprites = sprites.size();
            if (index >= 0 && index < tam_sprites) {
                sf::Sprite& sprite = sprites[index];
                sprite.setPosition(j * largura_quadrado, i * largura_quadrado);
                window->draw(sprite);
            } else {
                std::cerr << "Índice de sprite fora dos limites: " << index << std::endl;
            }
        }
    }

    window->display();
}

void Interface_Jogo::events() {
    static bool mousePressed = false;

    while (window->pollEvent(*event)) {
        if (event->type == sf::Event::Closed) {
            window->close();
        }

        if (event->type == sf::Event::MouseButtonPressed) {
            if (event->mouseButton.button == sf::Mouse::Left && !mousePressed) {
                mousePressed = true;

                sf::Vector2i pos = sf::Mouse::getPosition(*window);
                this->x = pos.x / largura_quadrado;
                this->y = pos.y / largura_quadrado;

                if (x >= 0 && x < colunas && y >= 0 && y < linhas) { // para testar se cada sprite está sendo lido corretamente
                    cout << "Você clicou no número: " << grid[y][x] << endl;
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

void Interface_Jogo::run(){
    std::cout << "Iniciando a execução do jogo..." << std::endl;
    while (window->isOpen()) {
        this->events();
        this->draw();
        // this->logic();
    }
}
