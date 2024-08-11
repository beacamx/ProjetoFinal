#include "Interface_Cadastro_Jogador2.hpp"

using namespace std;

Interface_Cadastro_Jogador2::Interface_Cadastro_Jogador2()
    : define_jogo(nullptr), caixa_de_texto1(15, sf::Color::White, false), caixa_de_texto2(15, sf::Color::White, false) {
    Set_Values();
}

Interface_Cadastro_Jogador2::~Interface_Cadastro_Jogador2(){}

void Interface_Cadastro_Jogador2::Set_Opcoes() {
    opcoes_de_escolha = {"Digitar apelido", "Digitar nome", "Play"};
}

void Interface_Cadastro_Jogador2::Definir_Textos() {
    try {
        tamanho_fonte = {19, 19, 17};
        int indice = 0;

        for (size_t i = 0; i < opcoes_de_escolha.size(); ++i) {
            if (indice == 2) {
                float pos_y = altura_texto + (i * espaco_vertical_botao_play);
                coords.push_back(sf::Vector2f(largura_janela / 2, pos_y));
                break;
            }
            float pos_y = altura_texto + (i * espaco_vertical);
            coords.push_back(sf::Vector2f(largura_janela / 2, pos_y));
            ++indice;
        }

        texto.resize(opcoes_de_escolha.size());

        for (size_t i{}; i < texto.size(); ++i) {
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
    } catch (const std::exception& e) {
        cerr << "Erro ao definir textos: " << e.what() << endl;
    }
}

void Interface_Cadastro_Jogador2::Set_Image() {
    try {
        if (!image->loadFromFile("./assets/Menu/Cadastro.png")) {
            cerr << "Erro ao carregar imagem de fundo" << endl;
        } else {
            background->setTexture(*image);
        }
    } catch (const std::exception& e) {
        cerr << "Erro ao definir a imagem de fundo: " << e.what() << endl;
    }
} 

void Interface_Cadastro_Jogador2::Definicoes_Espacamento_Janela() {
    espaco_vertical = 77.0f;
    espaco_vertical_botao_play = 83.0f;
    largura_janela = 624.0f;
    altura_texto = 206.0f; 
}

void Interface_Cadastro_Jogador2::Set_Values(){
    try {
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
        float posicao_y_caixa_texto1 = coords[0].y + texto[0].getGlobalBounds().height + espaco_adicional_entre_caixa_apelido;
        float posicao_y_caixa_texto2 = posicao_y_caixa_texto1 + 79.0f;

        caixa_de_texto1.Definir_Configuracoes_Caixa_de_Texto(*fonte, {posicao_x_caixa_texto, posicao_y_caixa_texto1}, true, 10);
        caixa_de_texto2.Definir_Configuracoes_Caixa_de_Texto(*fonte, {posicao_x_caixa_texto, posicao_y_caixa_texto2}, true, 10);

        janela->setKeyRepeatEnabled(true);
        janela->setVerticalSyncEnabled(true);
    } catch (const std::exception& e) {
        cerr << "Erro ao definir valores: " << e.what() << endl;
    }
}

void Interface_Cadastro_Jogador2::Loop_Events(){
    sf::Event evento;
    int tam_vetor_texto = texto.size();

    try{
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
                        caixa_de_texto2.Definir_Selecao(false);
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                        caixa_de_texto1.Definir_Selecao(false);
                        caixa_de_texto2.Definir_Selecao(false);
                    }
                } else if (posicao == 1) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                        caixa_de_texto1.Definir_Selecao(false);
                        caixa_de_texto2.Definir_Selecao(true);
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                        caixa_de_texto1.Definir_Selecao(false);
                        caixa_de_texto2.Definir_Selecao(false);
                    }
                } else if (posicao == 2) {
                    seleção_ativa = true;
                    string nome_jogador = caixa_de_texto1.Obter_Texto_Entrada();
                    string apelido_jogador = caixa_de_texto2.Obter_Texto_Entrada();
                    try {
                        if(registro_geral.find(nome_jogador) == NULL && apelido_jogador.length() > 0) { 
                            registro_geral.cadastrar(new jogador(nome_jogador, apelido_jogador, 0, 0, 0, 0));
                            registro_geral.save();
                            define_jogo = make_unique<Interface_Define_Jogo>();
                            janela->close();
                            define_jogo->Run_Menu();
                        } else if (registro_geral.find(nome_jogador) == NULL && apelido_jogador.length() == 0){
                            cerr << "Aviso: Digite seu nome";
                            aviso.setString("Aviso: Digite seu nome");
                            Define_Aviso();
                            seleção_ativa = false;
                        } else {
                            cerr << "Aviso: Jogador já existente";
                            aviso.setString("Aviso: Jogador já existente");
                            Define_Aviso();
                            seleção_ativa = false;
                        }
                    } catch (const runtime_error& e) {
                        cerr << "Erro ao cadastrar o jogador: " << e.what() << endl;
                    }
                }
            }

            if (evento.type == sf::Event::TextEntered) {
                caixa_de_texto1.Processar_Entrada(evento);
                caixa_de_texto2.Processar_Entrada(evento);
            }
        }
    } catch (const std::exception& e) {
        cerr << "Erro ao processar eventos: " << e.what() << endl;
    }

    if (mostrar_aviso && clock_aviso.getElapsedTime().asSeconds() > 2) {
        mostrar_aviso = false;
    }
}

void Interface_Cadastro_Jogador2::Define_Aviso() {
    try {
        aviso.setFont(*fonte); 
        aviso.setCharacterSize(15);
        aviso.setFillColor(sf::Color::Red);
        
        sf::FloatRect bounds_play = texto[2].getGlobalBounds();
        float pos_y_play = bounds_play.top + bounds_play.height;

        aviso.setPosition(largura_janela / 2 - aviso.getGlobalBounds().width / 2, pos_y_play + 80);
        clock_aviso.restart();
        mostrar_aviso = true;
    } catch (const std::exception& e) {
        cerr << "Erro ao definir aviso: " << e.what() << endl;
    }
}

void Interface_Cadastro_Jogador2::Draw_All() {
    try {
        this->janela->clear();
        this->janela->draw(*background);

        int tamanho_texto = texto.size();
        if (tamanho_texto) {
            for (const auto& text : texto) {
                janela->draw(text);
            }
        }
        
        if (mostrar_aviso) {
            janela->draw(aviso);
        }

        caixa_de_texto1.Draw_To(*janela);
        caixa_de_texto2.Draw_To(*janela);
        this->janela->display();
    } catch (const std::exception& e) {
        cerr << "Erro ao desenhar os elementos na janela: " << e.what() << endl;
    } catch (...) {
        cerr << "Erro desconhecido ao desenhar os elementos na janela" << endl;
    }
}