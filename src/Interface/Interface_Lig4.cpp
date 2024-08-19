#include "Interface_Lig4.hpp"
#include "Lig4.hpp"
#include "Interface_Base.hpp"

Interface_Lig4::Interface_Lig4(int num_linhas, int num_colunas) 
    : Interface_Jogo("Lig4") { 
    this->largura_quadrado = 78;
    this->linhas = num_linhas;
    this->colunas = num_colunas;
    string apelido1 = Interface_Base::Get_Apelido_Jogador1();
    string apelido2 = Interface_Base::Get_Apelido_Jogador2();
    try {
        cadastro& registro_geral_ref = Interface_Base::Get_Registro_Geral();
        lig4 = Lig4(registro_geral_ref, apelido1, apelido2, linhas, colunas);
        Set_Values();
    } catch (const std::exception& e) {
        cerr << "Erro ao criar Interface_Lig4: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

void Interface_Lig4::Logica() {
    sf::Vector2i posicao = sf::Mouse::getPosition(*janela);

    if(lig4.isJogoAtivo()) {
        int col = posicao.x / largura_quadrado;

    // Enviar a jogada para a lógica do jogo
        int linha = lig4.calcularLinhaDisponivel(col); // Função que retorna a linha disponível na coluna selecionada
        if (linha != -1) { // Verifica se a jogada é válida
            tabuleiro = lig4.fazerJogada(linha, col);
            if(!lig4.testarVitoria()) {
                lig4.trocarJogador();
            }
        }
    }
}


void Interface_Lig4::Set_Textura_Sem_Peca(){
    try {
        if (!textura_sem_peca.loadFromFile("./assets/Lig4/Sem_peca.png")) {
            throw std::runtime_error("Erro ao carregar textura de uma casa sem peça");
        }
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

void Interface_Lig4::Set_Textura_Peca1(){
    try {
        if (!textura_peca1.loadFromFile("./assets/Lig4/Peca_vermelha.png")) {
            throw std::runtime_error("Erro ao carregar textura de uma casa sem peça");
        }
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

void Interface_Lig4::Set_Textura_Peca2(){
    try {
        if (!textura_peca2.loadFromFile("./assets/Lig4/Peca_amarela.png")) {
            throw std::runtime_error("Erro ao carregar a textura da peça 2");
        }
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
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
    try {
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
                sprite.setTexture(textura_sem_peca);
                sprite.setTextureRect(sf::IntRect(0, 0, largura_quadrado, largura_quadrado)); // Definir a área da textura
                sprite.setPosition(j * largura_quadrado, i * largura_quadrado); // Definir a posição do sprite
            }
        }
    } catch (const std::exception& e) {
        cerr << "Erro ao configurar sprites: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

void Interface_Lig4::Set_Values(){
    //Set_Music();
    try {
        cout << "Criando Interface_Lig4..." << endl;

        Define_Dimensoes_Janela();
        Set_Janela();
        Set_Sprites();
        Set_Textura_Sem_Peca();
        Set_Textura_Peca1();
        Set_Textura_Peca2();
    } catch (const std::exception& e) {
        cerr << "Erro ao configurar valores da Interface_Lig4: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}
