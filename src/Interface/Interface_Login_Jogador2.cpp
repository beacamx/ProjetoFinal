#include "Interface_Login_Jogador2.hpp"

using namespace std;

Interface_Login_Jogador2::Interface_Login_Jogador2()
    : define_jogo(nullptr), caixa_de_texto1(15, sf::Color::White, false) { 
    try {
        Set_Values();
    } catch (const std::exception& e) {
        cerr << "Erro na inicialização da interface de login do Jogador 2: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

Interface_Login_Jogador2::~Interface_Login_Jogador2(){}

void Interface_Login_Jogador2::Set_Opcoes() {
    opcoes_de_escolha = {"Digitar apelido", "Play"};
}

void Interface_Login_Jogador2::Set_Image() {
    try {
        if (!image->loadFromFile("./assets/Menu/Login.png")) 
            cerr << "Erro ao carregar imagem de fundo" << endl;

        background->setTexture(*image);
    } catch (const std::exception& e) {
        cerr << "Erro ao definir a imagem de fundo: " << e.what() << endl;
    }
} 

void Interface_Login_Jogador2::Definicoes_Espacamento_Janela() {
    espaco_vertical = 90.0f;
    largura_janela = 624.0f;
    altura_texto = 244.0f; 
}

void Interface_Login_Jogador2::Set_Values(){
    Set_Efeito_Sonoro_Selecao_Botao();
    Set_Janela();
    Centralizar_Janela();
    Set_Image();
    Set_Opcoes();
    
    posicao = 0;
    pressed = seleção_ativa = false;
    
    Definicoes_Espacamento_Janela();

    tamanho_fonte = {19, 17};
    textos.Set_Fonte(tamanho_fonte);
    textos.Set_Textos_Com_Entrada(opcoes_de_escolha, largura_janela, altura_inferior_titulo, espaco_vertical, espaco_vertical_botao_play, altura_texto);

    coords.clear();

    Definir_Contorno_Inicial_Texto();

    float largura_caixa = 120.0f;
    float espaco_adicional_entre_caixa_apelido = 7.0f;

    const auto& textos_aux = textos.Get_Vetor_Textos();
    float posicao_x_caixa_texto = (largura_janela - largura_caixa) / 2;
    float posicao_y_caixa_texto = coords[0].y + textos_aux[0].getGlobalBounds().height + espaco_adicional_entre_caixa_apelido;

    auto& fonte = textos.Get_Fonte();
    caixa_de_texto1.Definir_Fonte(fonte);
    caixa_de_texto1.Definir_Posicao({posicao_x_caixa_texto, posicao_y_caixa_texto});
    caixa_de_texto1.Definir_Limite(true, 10);

    janela->setKeyRepeatEnabled(true);
}

void Interface_Login_Jogador2::Loop_Events(){
    sf::Event evento;
    int tam_vetor_texto = textos.Get_Tamanho_Vetor_Textos();

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
                    define_jogo = make_unique<Interface_Define_Jogo>();
                    janela->close();
                    define_jogo->Run_Menu();
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

void Interface_Login_Jogador2::Define_Aviso() {
    try {
        auto& fonte = textos.Get_Fonte();
        aviso.setFont(fonte);  
        aviso.setCharacterSize(15);
        aviso.setFillColor(sf::Color::Red);
        
        const auto& textos_aux = textos.Get_Vetor_Textos();
        sf::FloatRect bounds_play = textos_aux[1].getGlobalBounds();
        float pos_y_play = bounds_play.top + bounds_play.height;

        aviso.setString("Aviso: Jogador não existente, digite novamente");
        aviso.setPosition(largura_janela / 2 - aviso.getGlobalBounds().width / 2, pos_y_play + 80);
        clock_aviso.restart();
        mostrar_aviso = true;
    } catch (const std::exception& e) {
        cerr << "Erro ao definir aviso: " << e.what() << endl;
    }
}

void Interface_Login_Jogador2::Draw_All() {
    try {
        this->janela->clear();
        this->janela->draw(*background);

        size_t tamanho_texto = textos.Get_Tamanho_Vetor_Textos();
        if (tamanho_texto) {
            textos.Draw_Vetor_Textos(*janela);
        }

        if (mostrar_aviso) {
            janela->draw(aviso);
        }

        caixa_de_texto1.Draw_To(*janela);
        this->janela->display();
    } catch (const std::exception& e) {
        cerr << "Erro ao desenhar os elementos na janela: " << e.what() << endl;
    } catch (...) {
        cerr << "Erro desconhecido ao desenhar os elementos na janela" << endl;
    }
}