#include "Interface_Login_Jogador1.hpp"
#include "Troca_Definicao_Entrada_Jogador.hpp"

using namespace std;

Interface_Login_Jogador1::Interface_Login_Jogador1()
    : caixa_de_texto1(15, sf::Color::White, false) { 
    Set_Values();
}

Interface_Login_Jogador1::~Interface_Login_Jogador1(){}

void Interface_Login_Jogador1::Set_Opcoes() {
    opcoes_de_escolha = {"Digitar apelido", "Play"};
}

void Interface_Login_Jogador1::Definir_Textos() {
    tamanho_fonte = {19, 17};

    for (size_t i = 0; i < opcoes_de_escolha.size(); ++i) {
        float pos_y = altura_texto + (i * espaco_vertical);
        coords.push_back(sf::Vector2f(largura_janela / 2, pos_y));
    }

    texto.resize(opcoes_de_escolha.size());

    for(size_t i{}; i < texto.size(); ++i) {
        texto[i].setFont(*fonte);
        texto[i].setString(opcoes_de_escolha[i]);
        texto[i].setCharacterSize(tamanho_fonte[i]);
        texto[i].setOutlineColor(sf::Color::Black);
        texto[i].setPosition(coords[i]);

        sf::FloatRect text_bounds = texto[i].getLocalBounds();
        float largura_texto = text_bounds.width;
        float altura_texto = text_bounds.height;

        texto[i].setOrigin(largura_texto / 2.0f, altura_texto / 2.0f);
        texto[i].setPosition(coords[i].x, coords[i].y);
    }
}

void Interface_Login_Jogador1::Set_Image() {
    try {
        if (!image->loadFromFile("./assets/Menu/Login.png")) 
            cerr << "Erro ao carregar imagem de fundo" << endl;

        background->setTexture(*image);
    } catch (const std::exception& e) {
        cerr << "Erro ao definir a imagem de fundo: " << e.what() << endl;
    }
} 

void Interface_Login_Jogador1::Definicoes_Espacamento_Janela() {
    espaco_vertical = 90.0f;
    largura_janela = 624.0f;
    altura_texto = 244.0f; 
}

void Interface_Login_Jogador1::Set_Values(){
    Set_Efeito_Sonoro_Selecao_Botao();
    Definir_Fonte();
    Set_Janela();
    Centralizar_Janela();
    Set_Image();
    Set_Opcoes();

    posicao = 0;
    pressed = seleção_ativa = false;
    
    Definicoes_Espacamento_Janela();

    coords.clear();

    Definir_Textos();
    Definir_Contorno_Inicial_Texto();

    float largura_caixa = 120.0f;
    float espaco_adicional_entre_caixa_apelido = 7.0f;

    float posicao_x_caixa_texto = (largura_janela - largura_caixa) / 2;
    float posicao_y_caixa_texto = coords[0].y + texto[0].getGlobalBounds().height + espaco_adicional_entre_caixa_apelido;

    caixa_de_texto1.Definir_Fonte(*fonte);
    caixa_de_texto1.Definir_Posição({posicao_x_caixa_texto, posicao_y_caixa_texto});
    caixa_de_texto1.Definir_Limite(true, 10);

    janela->setKeyRepeatEnabled(true);
    janela->setVerticalSyncEnabled(true);
}

void Interface_Login_Jogador1::Loop_Events(){
    sf::Event evento;
    int tam_vetor_texto = texto.size();

    while(janela->pollEvent(evento)) {
        if (evento.type == sf::Event::Closed) {
            janela->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
            som_selecao.play();
            if(posicao < tam_vetor_texto - 1){
                ++posicao;
                pressed = true;
                Definir_Contorno_Texto_Avancar(posicao);
                pressed = false;
                seleção_ativa = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
            som_selecao.play();
            if(posicao > 0){
                --posicao;
                pressed = true;
                Definir_Contorno_Texto_Voltar(posicao);
                pressed = false;
                seleção_ativa = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !seleção_ativa) {
            if (posicao == 0) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                    caixa_de_texto1.Definir_Selecao(true);
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    caixa_de_texto1.Definir_Selecao(false);
                }
            } else if (posicao == 1) {
                seleção_ativa = true;
                string nome_jogador = caixa_de_texto1.Obter_Texto_Entrada();
                if(registro_geral.find_by_name(nome_jogador) != NULL) {
                    Troca_Definicao_Entrada_Jogador troca_Definicao_Entrada_Jogador;
                    janela->close();
                    troca_Definicao_Entrada_Jogador.Troca_Definicao_Jogador();
                } else {
                    cerr << "Aviso: Jogador não existente, digite novamente" << endl;
                    Define_Aviso();
                    seleção_ativa = false;
                }
            } 
        }

        if (evento.type == sf::Event::TextEntered) {
            caixa_de_texto1.Processar_Entrada(evento);
        }
    }

    if (mostrar_aviso && clock_aviso.getElapsedTime().asSeconds() > 2) {
        mostrar_aviso = false;
    }
}

void Interface_Login_Jogador1::Define_Aviso() {
    try {
        aviso.setFont(*fonte); 
        aviso.setCharacterSize(15);
        aviso.setFillColor(sf::Color::Red);
        
        sf::FloatRect bounds_play = texto[1].getGlobalBounds();
        float pos_y_play = bounds_play.top + bounds_play.height;

        aviso.setString("Aviso: Apelido incorreto");
        aviso.setPosition(largura_janela / 2 - aviso.getGlobalBounds().width / 2, pos_y_play + 80);
        clock_aviso.restart();
        mostrar_aviso = true;
    } catch (const std::exception& e) {
        cerr << "Erro ao definir aviso: " << e.what() << endl;
    }
}

void Interface_Login_Jogador1::Draw_All() {
    try {
        this->janela->clear();
        this->janela->draw(*background);

        int tamanho_texto = texto.size();
        if (tamanho_texto) {
            for (const auto& text : texto) {
                janela->draw(text);
            }
        }
        caixa_de_texto1.Draw_To(*janela);

        if (mostrar_aviso) {
            janela->draw(aviso);
        }

        this->janela->display();
    } catch (const std::exception& e) {
        cerr << "Erro ao desenhar os elementos na janela: " << e.what() << endl;
    } catch (...) {
        cerr << "Erro desconhecido ao desenhar os elementos na janela" << endl;
    }
}