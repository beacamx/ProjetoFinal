#include "Interface/Interface_Reversi.hpp"

Interface_Reversi::Interface_Reversi(int num_linhas, int num_colunas) 
    : Interface_Jogo("Reversi"){
    this->largura_quadrado = 74;
    this->linhas = num_linhas;
    this->colunas = num_colunas;
    string apelido1 = Interface_Base::Get_Apelido_Jogador1();
    string apelido2 = Interface_Base::Get_Apelido_Jogador2();
    try {
        cadastro& registro_geral_ref = Interface_Base::Get_Registro_Geral();
        reversi = Reversi(registro_geral_ref, apelido1, apelido2, linhas, colunas);
        Set_Values();
    } catch (const std::exception& e) {
        cerr << "Erro ao criar Interface_Reversi: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

void Interface_Reversi::Logica() {
    // Calcula as posições possíveis para o jogador atual
    auto pos = sf::Mouse::getPosition(*janela);
    std::cout << "Posição do mouse: (" << pos.x << ", " << pos.y << ")" << std::endl;

    int linha = pos.y / largura_quadrado;
    int coluna = pos.x / largura_quadrado;

    cout << "Coordenadas calculadas: Linha " << linha << ", Coluna " << coluna << endl;


    
}


/*void Interface_Reversi::Set_Music() {
    if (!som_jogo.openFromFile("./assets/audio/4.wav")) {
        cerr << "Erro ao carregar música" << std::endl;
        exit(1);
    }

    som_jogo.setVolume(2);
    som_jogo.setLoop(true);
    som_jogo.play();
}*/

void Interface_Reversi::Set_Values(){
    //Set_Music();

    cout << "Criando Interface_Reversi..." << endl;

    Define_Dimensoes_Janela();
    Set_Janela();
    Centralizar_Janela();
    Set_Sprites();
    Set_Textura_Sem_Peca();
    Set_Textura_Peca1();
    Set_Textura_Peca2();
}

void Interface_Reversi::Set_Textura_Sem_Peca(){
    try {
        if (!textura_sem_peca.loadFromFile("./assets/Reversi/Sem_Peca.png")) {
            cerr << "Erro ao carregar textura 8x8" << endl;
            exit(1);
        }
    } catch (const exception& e) {
        cerr << "Erro ao definir a imagem de quando não há peça: " << e.what() << endl;
    }
}

void Interface_Reversi::Set_Textura_Peca1(){
    try {
        if (!textura_peca1.loadFromFile("./assets/Reversi/Peca_Preta.png")) {
            cerr << "Erro ao carregar a textura da peça 1" << endl;
            exit(1);
        }
    } catch (const exception& e) {
        cerr << "Erro ao definir a imagem da peça 1: " << e.what() << endl;
    }
}

void Interface_Reversi::Set_Textura_Peca2(){
    try {
        if (!textura_peca2.loadFromFile("./assets/Reversi/Peca_Branca.png")) {
            cerr << "Erro ao carregar a textura da peça 2" << endl;
            exit(1);
        }
    } catch (const exception& e) {
        cerr << "Erro ao definir a imagem da peça 2: " << e.what() << endl;
    }
}

void Interface_Reversi::Set_Sprites() {
    sprites.resize(linhas * colunas); // Redimensiona o vetor de sprites para ter um sprite para cada posição no tabuleiro.
    tabuleiro.resize(linhas, vector<int>(colunas, 0)); // Redimensiona a matriz grid para representar o estado do tabuleiro, inicializando todas as posições com 0 (indicando que estão vazias).

    tabuleiro = reversi.inicializarTabuleiro();
    reversi.imprimirTabuleiro();

    for(int i = 0; i < linhas; ++i) {
        for(int j = 0; j < colunas; ++j) {
            int valor_casa = tabuleiro[i][j];
            int indice = i * colunas + j;
            int tamanho_vetor_sprites = sprites.size();

            if (indice < 0 || indice >= tamanho_vetor_sprites) {
                cerr << "Índice fora dos limites: " << indice << endl;
                continue;
            }

            sf::Sprite& sprite = sprites[indice];

            if(valor_casa == 0) {
                sprite.setTexture(textura_sem_peca); 
            } else if (valor_casa == 1) {
                sprite.setTexture(textura_peca1); 
            } else if (valor_casa == 2) {
                sprite.setTexture(textura_peca2);
            } else {
                continue;
            }

            sprite.setTextureRect(sf::IntRect(0, 0, largura_quadrado, largura_quadrado));
            sprite.setPosition(j * largura_quadrado, i * largura_quadrado);
        }
    }
}
