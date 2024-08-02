#include "Interface_Lig4.hpp"
#include "Interface_Jogo.hpp"
#include "Lig4.hpp"

using namespace std;

void Interface_Lig4::logic() {

}

void Interface_Lig4::set_Image(){
    if(num_quadrados == 42) {
        texture.loadFromFile("./assets/Lig4/Lig4_7x6.png");
    } else if(num_quadrados == 56){
        texture.loadFromFile("./assets/Lig4/Lig4_8x7.png");
    } else if(num_quadrados == 72) {
        texture.loadFromFile("./assets/Lig4/Lig4_9x8.png");
    }
}

void Interface_Lig4::set_Sprites() {
    sprites.resize(linhas * colunas);
    grid.resize(linhas, vector<int>(colunas, 0));
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
            sprite.setTextureRect(sf::IntRect(j * largura_quadrado, i * largura_quadrado, largura_quadrado, largura_quadrado)); 

            grid[i][j] = index + 1; 
        }
    }
}

int Interface_Lig4::Start_Game_Interface(int num_linhas, int num_colunas){
    this->linhas = num_linhas;
    this->colunas = num_colunas;

    this->largura_quadrado = 78,
    this->num_quadrados = linhas * colunas;

    int largura_janela = colunas * largura_quadrado;
    int altura_janela = linhas * largura_quadrado;

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
