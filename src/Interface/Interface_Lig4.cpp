#include "Interface_Lig4.hpp"

Interface_Lig4::~Interface_Lig4() {
    //som_jogo.stop();
}

void Interface_Lig4::Logica() {
    sf::Vector2i posicao = sf::Mouse::getPosition(*janela);
    int col = posicao.x / largura_quadrado;

    // Enviar a jogada para a lógica do jogo
    //int linha = lig4.calcularLinhaDisponivel(col); // Função que retorna a linha disponível na coluna selecionada
    //if (linha != -1) { // Verifica se a jogada é válida
    //    lig4.fazerJogada(linha, col);
    //}

    // Testa se houve vitória após a jogada
    //lig4.testarVitoria();
}


void Interface_Lig4::Set_Textura_Sem_Peca(){
    if (!textura.loadFromFile("./assets/Lig4/Sem_peca.png")) {
        cerr << "Erro ao carregar textura de uma casa sem peça" << endl;
        exit(1);
    }
}

void Interface_Lig4::Set_Textura_Peca1(){
    if (!textura_peca1.loadFromFile("./assets/Lig4/Peca_vermelha.png")) {
        cerr << "Erro ao carregar a textura da peça 1" << endl;
        exit(1);
    }
}

void Interface_Lig4::Set_Textura_Peca2(){
    if (!textura_peca2.loadFromFile("./assets/Lig4/Peca_amarela.png")) {
        cerr << "Erro ao carregar a textura da peça 2" << endl;
        exit(1);
    }
}

/*void Interface_Lig4::Set_Music() {
    if (!som_jogo.openFromFile("./assets/audio/3.wav")) {
        cerr << "Erro ao carregar música" << std::endl;
        exit(1);
    }

    som_jogo.setVolume(2);
    som_jogo.setLoop(true);
    som_jogo.play();
}*/

void Interface_Lig4::Set_Sprites() {
    sprites.resize(linhas * colunas); // Redimensiona o vetor de sprites para ter um sprite para cada posição no tabuleiro.
    tabuleiro.resize(linhas, vector<int>(colunas, 0)); // Redimensiona a matriz grid para representar o estado do tabuleiro, inicializando todas as posições com 0 (indicando que estão vazias).
        
    for(int i = 0; i < linhas; ++i) {
        for(int j = 0; j < colunas; ++j) {
            int indice = i * colunas + j; 
            int tamanho_vetor_sprites = sprites.size();

            cout << "i: " << i << ", j: " << j << ", indice: " << indice << endl;

            if (indice >= tamanho_vetor_sprites) {
                cerr << "Índice fora dos limites: " << indice << endl;
                continue;
            }

            sf::Sprite& sprite = sprites[indice];
            sprite.setTexture(textura);
            sprite.setTextureRect(sf::IntRect(0, 0, largura_quadrado, largura_quadrado)); // Definir a área da textura
            sprite.setPosition(j * largura_quadrado, i * largura_quadrado); // Definir a posição do sprite
        }
    }
}

int Interface_Lig4::Start_Game_Interface(int num_linhas, int num_colunas){
    //Set_Music();
    
    // Define o número de linhas e colunas do tabuleiro.
    this->linhas = num_linhas;
    this->colunas = num_colunas;

    cout << "Criando Interface_Lig4..." << endl;

    Define_Dimensoes_Janela();
    Set_Janela();

    tabuleiro.resize(linhas, std::vector<int>(colunas, 0));

    Set_Sprites();
    Set_Textura_Sem_Peca();
    Set_Textura_Peca1();
    Set_Textura_Peca2();
    Run();

    return 0;
}
