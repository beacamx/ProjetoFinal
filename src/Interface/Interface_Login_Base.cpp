#include "Interface_Login_Base.hpp"

Interface_Login_Base::Interface_Login_Base() : Interface_Menu(), caixa_de_texto1(15, sf::Color::White, false) { 
    try {
        Set_Values();
        cout << "Tamanho vetor de jogadores:" << registro_geral.jogadores.size() << endl;
    } catch (const std::exception& e) {
        cerr << "Erro ao inicializar Interface_Login_Jogador1: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

void Interface_Login_Base::Set_Opcoes() {
    opcoes_de_escolha = {"Digitar apelido", "Play"};
}

void Interface_Login_Base::Set_Image() {
     try {
        if (!image->loadFromFile("./assets/Menu/Login.png")) {
            throw runtime_error("Erro ao carregar imagem de fundo. Verifique o caminho do arquivo.");
        }
        background->setTexture(*image);
    } catch (const std::runtime_error& e) {
        cerr << "Erro ao definir a imagem de fundo: " << e.what() << endl;
    } catch (const std::exception& e) {
        cerr << "Erro desconhecido ao definir a imagem de fundo: " << e.what() << endl;
    }
} 

void Interface_Login_Base::Definicoes_Espacamento_Janela() {
    espaco_vertical = 90.0f;
    largura_janela = 624.0f;
    altura_texto = 244.0f; 
}

void Interface_Login_Base::Set_Values(){
    Set_Janela();
    Set_Image();
    Set_Opcoes();
    Definicoes_Espacamento_Janela();

    tamanho_fonte = {19, 17};
    textos.Set_Fonte(tamanho_fonte);
    textos.Set_Textos_Com_Entrada(opcoes_de_escolha, largura_janela, altura_inferior_titulo, espaco_vertical, espaco_vertical_botao_play, altura_texto);
    textos.Set_Contorno_Inicial_Texto();

    posicao = 0;
    pressed = seleção_ativa = false;

    float largura_caixa = 120.0f;
    float espaco_adicional_entre_caixa_apelido = 7.0f;

    coords_copia = textos.Get_Coords();
    const auto& textos_aux = textos.Get_Vetor_Textos();
    float posicao_x_caixa_texto = (largura_janela - largura_caixa) / 2;
    float posicao_y_caixa_texto = coords_copia[0].y + textos_aux[0].getGlobalBounds().height + espaco_adicional_entre_caixa_apelido;
    
    auto& fonte = textos.Get_Fonte();
    caixa_de_texto1.Definir_Fonte(fonte);
    caixa_de_texto1.Definir_Posicao({posicao_x_caixa_texto, posicao_y_caixa_texto});
    caixa_de_texto1.Definir_Limite(true, 10);

    janela->setKeyRepeatEnabled(true);
}

void Interface_Login_Base::Atualizar_Janela() {
    try {
        this->janela->clear();
        this->janela->draw(*background);

        auto& textos_aux = textos.Get_Vetor_Textos();
        for (const auto& text : textos_aux) {
            janela->draw(text);
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

void Interface_Login_Base::Set_Aviso() {
    try {
        const sf::Font& fonte = textos.Get_Fonte();
        aviso.setFont(fonte); 
        aviso.setCharacterSize(15);
        aviso.setFillColor(sf::Color::Red);
        
        clock_aviso.restart();
        const auto& textos_aux = textos.Get_Vetor_Textos();
        sf::FloatRect bounds_play = textos_aux[1].getGlobalBounds();
        float pos_y_play = bounds_play.top + bounds_play.height;
        aviso.setPosition(largura_janela / 2 - aviso.getGlobalBounds().width / 2, pos_y_play + 80);
        mostrar_aviso = true;
    } catch (const std::exception& e) {
        cerr << "Erro ao definir aviso: " << e.what() << endl;
    }
}