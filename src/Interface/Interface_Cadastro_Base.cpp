#include "Interface_Cadastro_Base.hpp"

using namespace std;

Interface_Cadastro_Base::Interface_Cadastro_Base()
    : Interface_Menu(), caixa_de_texto1(15, sf::Color::White, false), caixa_de_texto2(15, sf::Color::White, false) {
    Set_Values();
    cout << "Tamanho vetor de jogadores:" << registro_geral.jogadores.size() << endl;
}

void Interface_Cadastro_Base::Set_Values(){
    try {
        Set_Janela();
        Centralizar_Janela();
        Set_Image();
        Set_Opcoes();
        Definicoes_Espacamento_Janela();

        posicao = 0;
        pressed = seleção_ativa = false;

        tamanho_fonte = {19, 19, 17};
        textos.Set_Fonte(tamanho_fonte);
        textos.Set_Textos_Com_Entrada(opcoes_de_escolha, largura_janela, altura_inferior_titulo, espaco_vertical, 
            espaco_vertical_botao_play, altura_texto);
        textos.Set_Contorno_Inicial_Texto();

        float largura_caixa = 120.0f;
        float espaco_adicional_entre_caixa_apelido = 7.0f;

        coords_copia = textos.Get_Coords();
        const auto& textos_aux = textos.Get_Vetor_Textos();
        float posicao_x_caixa_texto = (largura_janela - largura_caixa) / 2;
        float posicao_y_caixa_texto1 = coords_copia[0].y + textos_aux[0].getGlobalBounds().height + espaco_adicional_entre_caixa_apelido;
        float posicao_y_caixa_texto2 = posicao_y_caixa_texto1 + 79.0f;

        auto& fonte = textos.Get_Fonte();
        caixa_de_texto1.Definir_Configuracoes_Caixa_de_Texto(fonte, {posicao_x_caixa_texto, posicao_y_caixa_texto1}, true, 10);
        caixa_de_texto2.Definir_Configuracoes_Caixa_de_Texto(fonte, {posicao_x_caixa_texto, posicao_y_caixa_texto2}, true, 10);

        janela->setKeyRepeatEnabled(true);
        janela->setVerticalSyncEnabled(true);
    } catch (const runtime_error& e) {
        cerr << "Erro ao configurar valores da interface: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Erro inesperado ao configurar valores: " << e.what() << endl;
    }
}

void Interface_Cadastro_Base::Set_Opcoes() {
    opcoes_de_escolha = {"Digitar apelido", "Digitar nome", "Play"};
}

void Interface_Cadastro_Base::Set_Image() {
    if (!image->loadFromFile("./assets/Menu/Cadastro.png")) 
        cerr << "Erro ao carregar imagem de fundo" << endl;

    background->setTexture(*image);
}

void Interface_Cadastro_Base::Definicoes_Espacamento_Janela() {
    espaco_vertical = 77.0f;
    espaco_vertical_botao_play = 83.0f;
    largura_janela = 624.0f;
    altura_texto = 206.0f; 
}

void Interface_Cadastro_Base::Set_Aviso() {
    try {
        const sf::Font& fonte = textos.Get_Fonte();
        aviso.setFont(fonte); 
        aviso.setCharacterSize(15);
        aviso.setFillColor(sf::Color::Red);
        
        const auto& textos_aux = textos.Get_Vetor_Textos();
        sf::FloatRect bounds_play = textos_aux[2].getGlobalBounds();
        float pos_y_play = bounds_play.top + bounds_play.height;

        aviso.setPosition(largura_janela / 2 - aviso.getGlobalBounds().width / 2, pos_y_play + 80);
        clock_aviso.restart();
        mostrar_aviso = true;
    } catch (const std::exception& e) {
        cerr << "Erro ao definir aviso: " << e.what() << endl;
    }
}

void Interface_Cadastro_Base::Atualizar_Janela() {
    try {
        this->janela->clear();
        this->janela->draw(*background);

        size_t tamanho_texto = textos.Get_Tamanho_Vetor_Textos();

        auto& textos_aux = textos.Get_Vetor_Textos();
        for (const auto& text : textos_aux) {
            janela->draw(text);
        }

        if (mostrar_aviso) {
            janela->draw(aviso);
        }
        
        caixa_de_texto1.Draw_To(*janela);
        caixa_de_texto2.Draw_To(*janela);
        janela->display();
    } catch (const std::exception& e) {
        cerr << "Erro ao desenhar os elementos na janela: " << e.what() << endl;
    } catch (...) {
        cerr << "Erro desconhecido ao desenhar os elementos na janela" << endl;
    }
}
