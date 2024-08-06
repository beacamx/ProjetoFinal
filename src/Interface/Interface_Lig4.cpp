#include "Interface_Lig4.hpp"
#include "Interface_Jogo.hpp"
#include "Lig4.hpp"

using namespace std;

void Interface_Lig4::logic() {

}

void Interface_Lig4::cleanup() {
    janela.reset();
    sprites.clear();
    grid.clear();
}

void Interface_Lig4::set_Image(){
    if(num_quadrados == 42) {
        if (!texture.loadFromFile("./assets/Lig4/Lig4_7x6.png")) {
            cerr << "Erro ao carregar textura 7x6" << endl;
            exit(1);
        }
    } else if(num_quadrados == 56){
        if (!texture.loadFromFile("./assets/Lig4/Lig4_8x7.png")) {
            cerr << "Erro ao carregar textura 8x7" << endl;
            exit(1);
        }
    } else if(num_quadrados == 72) {
        if (!texture.loadFromFile("./assets/Lig4/Lig4_9x8.png")) {
            cerr << "Erro ao carregar textura 9x8" << endl;
            exit(1);
        }
    }
}

void Interface_Lig4::Set_Music() {
    if (!som_jogo.openFromFile("./assets/audio/3.wav")) {
        cerr << "Erro ao carregar música" << std::endl;
        exit(1);
    }

    som_jogo.setVolume(2);
    som_jogo.setLoop(true);
    som_jogo.play();
}

void Interface_Lig4::set_Sprites() {
    sprites.resize(linhas * colunas);
    grid.resize(linhas, vector<int>(colunas, 0));
    for(int i = 0; i < linhas; ++i) {
        for(int j = 0; j < colunas; ++j) {
            int index = i * colunas + j; 
            int tam_sprites = sprites.size();
            
            if (index >= tam_sprites) {
                cerr << "Índice fora dos limites: " << index << std::endl;
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
    Set_Music();
    
    this->linhas = num_linhas;
    this->colunas = num_colunas;

    Define_Dimensoes_Janela();
    Set_Janela();
    Centralizar_Janela();

    grid.resize(linhas, std::vector<int>(colunas, 0));

    set_Sprites();
    set_Image();
    run();

    return 0;
}
