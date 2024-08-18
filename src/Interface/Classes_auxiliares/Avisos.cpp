#include "Avisos.hpp"

void Avisos::Set_Aviso() {
    try {
        const sf::Font& fonte = texto.Get_Fonte();
        aviso.setFont(fonte); 
        aviso.setCharacterSize(15);
        aviso.setFillColor(sf::Color::Red);

        cerr << "Fonte definida corretamente." << endl;
    } catch (const exception& e) {
        cerr << "Erro ao definir aviso: " << e.what() << endl;
    }
}

void Avisos::Get_Aviso_Com_Entrada(const string& mensagem_de_erro, float largura_janela, const vector<sf::Text>& textos) {
    try {
        int indice = textos.size();
        if (indice == 0) {
            cerr << "Erro: Vetor de textos está vazio." << endl;
            return;
        }
        sf::FloatRect bounds_play = textos[indice - 1].getGlobalBounds();
        float pos_y_play = bounds_play.top + bounds_play.height;
        aviso.setString(mensagem_de_erro);
        aviso.setPosition(largura_janela / 2 - aviso.getGlobalBounds().width / 2, pos_y_play + 80);
        Set_Mostrar_Aviso(true);
        Start_Timer(tempo_exibicao);

        cerr << "Aviso: " << mensagem_de_erro << endl;
        cerr << "Posição do aviso: " << aviso.getPosition().x << ", " << aviso.getPosition().y << endl;
    } catch (const std::exception& e) {
        cerr << "Erro ao mostrar aviso do login/cadastro: " << e.what() << endl;
    }
}

void Avisos::Get_Aviso_Sem_Entrada(const string& mensagem_de_erro, float largura_janela, const vector<sf::Text>& textos) {
    try {
        Set_Mostrar_Aviso(true);
        sf::FloatRect bounds_play = textos[2].getGlobalBounds();
        float pos_y_play = bounds_play.top + bounds_play.height;
        aviso.setString(mensagem_de_erro);
        aviso.setPosition(largura_janela / 2 - aviso.getGlobalBounds().width / 2, pos_y_play + 80);
        mostrar_aviso = true;
        Start_Timer(tempo_exibicao);
    } catch (const std::exception& e) {
        cerr << "Erro ao mostrar aviso: " << e.what() << endl;
    }
}

void Avisos::Start_Timer(float tempo_exibicao) {
    try {
        timer.restart();  
        tempo_total = tempo_exibicao; 
    } catch (const std::exception& e) {
        cerr << "Exceção capturada no Timer: " << e.what() << endl;
    } catch (...) {
        cerr << "Erro desconhecido no Timer." << endl;
    }
}

bool Avisos::Is_Timer_Expired() const {
    return timer.getElapsedTime().asSeconds() >= tempo_total;
}

bool Avisos::Get_Mostrar_Aviso() const {
    return mostrar_aviso;
}

const sf::Text& Avisos::Get_Aviso () const {
    cerr << "Texto de aviso: " << aviso.getString().toAnsiString() << endl;
    return aviso;
}

void Avisos::Set_Mostrar_Aviso(bool mostrar) {
    mostrar_aviso = mostrar;
}