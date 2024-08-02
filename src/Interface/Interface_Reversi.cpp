#include "Interface/Interface_Reversi.hpp"
#include "Reversi.hpp"

using namespace std;

void Interface_Reversi::logic() {
    
}

int Interface_Reversi::Start_Game_Interface(int num_linhas, int num_colunas){
    this->linhas = num_linhas;
    this->colunas = num_colunas;
    
    this->largura_quadrado = 74;
    this->num_quadrados = linhas * colunas;

    int largura_janela = colunas * largura_quadrado;
    int altura_janela = linhas * largura_quadrado;

    cout << "Criando Interface_Lig4..." << endl;
    window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(largura_janela, altura_janela),
        nome_do_jogo,
        sf::Style::Titlebar | sf::Style::Close
    );

    window->setPosition(sf::Vector2i(50, 50));
    window->setFramerateLimit(60);

    grid.resize(linhas, std::vector<int>(colunas, 0));

    set_Sprites();
    set_Image();
    run();

    return 0;
}

void Interface_Reversi::set_Image(){
    if(num_quadrados == 64) {
        texture.loadFromFile("./assets/Reversi/Reversi_8x8.png");
    }
}

void Interface_Reversi::set_Sprites() {
    sprites.resize(linhas * colunas);
    grid.resize(linhas, std::vector<int>(colunas, 0));
    for(int i = 0; i < linhas; ++i) {
        for(int j = 0; j < colunas; ++j) {
            int index = i * colunas + j; 
            int tam_sprites = sprites.size();

            if (index >= tam_sprites) {
                std::cerr << "Índice fora dos limites: " << index << std::endl;
                continue;
            }

            sf::Sprite& sprite = sprites[index];
            sprite.setTexture(texture);
            sprite.setTextureRect(sf::IntRect(j * largura_quadrado, i * largura_quadrado, largura_quadrado, largura_quadrado)); // Definir a área da textura
            sprite.setPosition(j * largura_quadrado, i * largura_quadrado); 

            grid[i][j] = index + 1; 
        }
    }
}

