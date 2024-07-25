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
            sprite.setTextureRect(sf::IntRect(j * largura_quadrado, i * largura_quadrado, largura_quadrado, largura_quadrado)); 

            grid[i][j] = index + 1; 
        }
    }
}

int Interface_Lig4::Inicia_Jogo(int argc, char **argv){
    int dimensao;

    cout << "Escolha uma dimensão:" << endl << "1- 7x6" << endl << "2- 8x7" << endl << "3- 9x7" << endl;
    cin >> dimensao;

    switch(dimensao) {
        case 1:
            this->linhas = 6;
            this->colunas = 7;
            break;
        case 2:
            this->linhas = 7;
            this->colunas = 8;
            break;
        case 3:
            this->linhas = 8;
            this->colunas = 9;
            break;
        default:
            cout << "Dimensão inválida. Usando padrão 7x6." << endl;
            this->linhas = 6;
            this->colunas = 7;
            break;
    }
    
    this->largura_quadrado = 78,
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
