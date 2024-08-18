#include "Avisos.hpp"

void Avisos::Set_Aviso() {
    try {
        const sf::Font& fonte = texto.Get_Fonte();
        aviso.setFont(fonte); 
        aviso.setCharacterSize(15);
        aviso.setFillColor(sf::Color::Red);
    } catch (const exception& e) {
        cerr << "Erro ao definir aviso: " << e.what() << endl;
    }
}

void Avisos::Get_Aviso_Com_Entrada(const string& mensagem_de_erro, float largura_janela, const vector<sf::Text>& textos) {
    try {
        sf::FloatRect bounds_play = textos[2].getGlobalBounds();
        float pos_y_play = bounds_play.top + bounds_play.height;
        aviso.setString(mensagem_de_erro);
        aviso.setPosition(largura_janela / 2 - aviso.getGlobalBounds().width / 2, pos_y_play + 80);
        Timer(3.0f);
        mostrar_aviso = true;
    } catch (const std::exception& e) {
        cerr << "Erro ao mostrar aviso do login/cadastro: " << e.what() << endl;
    }
}

void Avisos::Get_Aviso_Sem_Entrada(const string& mensagem_de_erro, float largura_janela, const vector<sf::Text>& textos) {
    try {
        sf::FloatRect bounds_play = textos[2].getGlobalBounds();
        float pos_y_play = bounds_play.top + bounds_play.height;
        aviso.setString(mensagem_de_erro);
        aviso.setPosition(largura_janela / 2 - aviso.getGlobalBounds().width / 2, pos_y_play + 80);
        Timer(3.0f);
        mostrar_aviso = true;
    } catch (const std::exception& e) {
        cerr << "Erro ao mostrar aviso: " << e.what() << endl;
    }
}


void Avisos::Timer(float tempo_exibicao) {
    try {
        timer.restart();
        while (timer.getElapsedTime().asSeconds() < tempo_exibicao) {}  
    } catch (const std::exception& e) {
        cerr << "Exceção capturada no Timer: " << e.what() << endl;
    } catch (...) {
        cerr << "Erro desconhecido no Timer." << endl;
    }
}

bool Avisos::Get_Mostrar_Aviso() const {
    return mostrar_aviso;
}

sf::Text Avisos::Get_Aviso() const {
    return aviso;
}