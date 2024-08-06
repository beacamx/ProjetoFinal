#include "Interface_Jogo.hpp"

using namespace std;

Interface_Jogo::Interface_Jogo(const string& nome_do_jogo)
    : nome_do_jogo(nome_do_jogo), janela(make_unique<sf::RenderWindow>()) {
    evento = make_shared<sf::Event>();
}

void Interface_Jogo::Atualizar_Janela_Jogo() {
    janela->clear(sf::Color::Black); // Limpa a janela com a cor preta
    
    for(const auto& sprite : sprites) {
        janela->draw(sprite); // Desenha o sprite na janela
    }

    // Desenha os sprites das peças no tabuleiro, dependendo do valor da cas (1 ou 2)
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
            if (valor_casa == 1) {
                sprite.setTexture(textura_peca1); 
            } else if (valor_casa == 2) {
                sprite.setTexture(textura_peca2);
            } else {
                continue;
            }

            sprite.setPosition(j * largura_quadrado, i * largura_quadrado);
            janela->draw(sprite); // Desenha o sprite na janela
        }
    }

    janela->display();
}

void Interface_Jogo::Eventos_Jogo() {
    static bool mousePressed = false; // Controle para verificar se o botão do mouse foi pressionado

    while (janela->pollEvent(*evento)) {
        if (evento->type == sf::Event::Closed) {
            janela->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            janela->close();
        }

        if (evento->type == sf::Event::MouseButtonPressed) {
            if (evento->mouseButton.button == sf::Mouse::Left && !mousePressed) {
                mousePressed = true;

                // Obtém a posição do mouse na janela do jogo e a converte para coordenadas de células do tabuleiro (x e y), dividindo a posição do mouse pela largura das casas (largura_quadrado)
                sf::Vector2i posicao = sf::Mouse::getPosition(*janela);
                this->x = posicao.x / largura_quadrado;
                this->y = posicao.y / largura_quadrado;

                //if (x >= 0 && x < colunas && y >= 0 && y < linhas) { // para testar se cada sprite está sendo lido corretamente
                //    cout << "Você clicou no número: " << tabuleiro[x][y] << endl;
                //}
            }
        }

        // Define mousePressed como false quando o botão do mouse é solto
        if (evento->type == sf::Event::MouseButtonReleased) {
            if (evento->mouseButton.button == sf::Mouse::Left) {
                mousePressed = false;
            }
        }
    }
}

void Interface_Jogo::Set_Janela() {
    cout << "Definindo dimensões da janela: " << largura_janela << "x" << altura_janela << endl;
    janela->create(sf::VideoMode(largura_janela, altura_janela), nome_do_jogo, sf::Style::Titlebar | sf::Style::Close);
    if (!janela->isOpen()) {
        cerr << "Erro ao criar a janela" << endl;
        exit(1);
    }
    janela->setFramerateLimit(60);
}

void Interface_Jogo::Define_Dimensoes_Janela() {
    this->largura_janela = colunas * largura_quadrado;
    this->altura_janela = linhas * largura_quadrado;
}

void Interface_Jogo::Centralizar_Janela() {
    sf::Vector2i janela_centralizada(
        (sf::VideoMode::getDesktopMode().width - this->largura_janela) / 2, 
        (sf::VideoMode::getDesktopMode().height - this->altura_janela) / 2
    );
    janela->setPosition(janela_centralizada);
}

void Interface_Jogo::Run_Interface_Jogo(){
    cout << "Iniciando a execução do jogo..." << endl;
    while (janela->isOpen()) {
        this->Eventos_Jogo();
        // this->logic();
        this->Atualizar_Janela_Jogo();
    }
}
