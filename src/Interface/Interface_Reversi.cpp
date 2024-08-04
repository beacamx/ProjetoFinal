#include "Interface/Interface_Reversi.hpp"
#include "Reversi.hpp"

using namespace std;

void Interface_Reversi::logic() {
    
}

void Interface_Reversi::cleanup() {
    janela.reset();
    sprites.clear();
    grid.clear();
}

void Interface_Reversi::Set_Music() {
    if (!som_jogo.openFromFile("./assets/audio/4.wav")) {
        cerr << "Erro ao carregar música" << std::endl;
        exit(1);
    }

    som_jogo.setVolume(2);
    som_jogo.play();
}

int Interface_Reversi::Start_Game_Interface(int num_linhas, int num_colunas){
    Set_Music();

    this->linhas = num_linhas;
    this->colunas = num_colunas;

    cout << "Criando Interface_Lig4..." << endl;

    Define_Dimensoes_Janela();
    Set_Janela();
    Centralizar_Janela();

    grid.resize(linhas, std::vector<int>(colunas, 0));

    set_Sprites();
    set_Image();
    run();

    return 0;
}

void Interface_Reversi::set_Image(){
    if(num_quadrados == 64) {
        if (!texture.loadFromFile("./assets/Reversi/Reversi_8x8.png")) {
            cerr << "Erro ao carregar textura 8x8" << endl;
            exit(1);
        }
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

