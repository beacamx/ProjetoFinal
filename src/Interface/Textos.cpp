#include "Textos.hpp"

Textos::Textos() : fonte(make_unique<sf::Font>()) {}

Textos::~Textos() {}

void Textos::Set_Fonte(const vector<size_t>& tamanhos) {
    this->tamanho_fonte = tamanhos;

    try {
        if (!fonte->loadFromFile("./assets/fontes/pixelmix.ttf")) {
            throw runtime_error("Erro ao carregar *fonte");
        }
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
        exit(1);
    }
}

const sf::Font& Textos::Get_Fonte() const {
    try {
        if (!fonte) {
            throw runtime_error("Fonte não foi carregada corretamente.");
        }
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
        exit(1);
    }

    return *fonte;
}

size_t Textos::Get_Tamanho_Vetor_Textos() const {
    return textos.size();
}



const vector<sf::Text>& Textos::Get_Vetor_Textos() const {
    return textos;
}

vector<sf::Text>& Textos::Get_Vetor_Textos() {
    return textos;
}

vector<sf::Vector2f>& Textos::Get_Coords() {
    return coords;
}

void Textos::Set_Textos_Sem_Entrada(const vector<const char*>& opcoes_de_escolha, float largura_janela, float altura_inferior_titulo, float espaco_vertical) {
    try {
        if (opcoes_de_escolha.size() != tamanho_fonte.size()) {
            throw runtime_error("O tamanho de opcoes_de_escolha e tamanho_fonte não coincidem");
        }

        coords.clear();

        for (size_t i = 0; i < opcoes_de_escolha.size(); ++i) {
            float pos_y = altura_inferior_titulo + (i * espaco_vertical);
            coords.push_back(sf::Vector2f(largura_janela / 2, pos_y));
        }

        textos.resize(opcoes_de_escolha.size());

        for(size_t i = 0; i < textos.size(); ++i) {
            textos[i].setFont(*fonte);
            textos[i].setString(opcoes_de_escolha[i]);
            textos[i].setCharacterSize(tamanho_fonte[i]);
            textos[i].setOutlineColor(sf::Color::Black);
            textos[i].setPosition(coords[i]);

            sf::FloatRect text_bounds = textos[i].getLocalBounds();
            float largura_texto = text_bounds.width;
            float altura_texto = text_bounds.height;

            textos[i].setOrigin(largura_texto / 2.0f, altura_texto / 2.0f);
            textos[i].setPosition(coords[i].x, coords[i].y);
        }
    } catch (const std::exception& e) {
        cerr << "Erro ao definir textos: " << e.what() << endl;
        exit(1);
    }
}

void Textos::Set_Textos_Com_Entrada(const vector<const char*>& opcoes_de_escolha, float largura_janela, float altura_inferior_titulo, float espaco_vertical, float espaco_vertical_botao_play, float altura_texto) {
    try {
        if (opcoes_de_escolha.size() != tamanho_fonte.size()) {
            throw runtime_error("O tamanho de `opcoes_de_escolha` e `tamanho_fonte` não coincidem.");
        }

        int indice = 0;
        coords.clear();

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

        textos.resize(opcoes_de_escolha.size());

        for (size_t i = 0; i < textos.size(); ++i) {
            textos[i].setFont(*fonte);
            textos[i].setString(opcoes_de_escolha[i]);
            textos[i].setCharacterSize(tamanho_fonte[i]);
            textos[i].setOutlineColor(sf::Color::Black);
            textos[i].setPosition(coords[i]);

            sf::FloatRect text_bounds = textos[i].getLocalBounds();
            float largura_texto = text_bounds.width;
            float altura_texto = text_bounds.height;

            textos[i].setOrigin(largura_texto / 2.0f, altura_texto / 2.0f);
            textos[i].setPosition(coords[i].x, coords[i].y);
        }
    } catch (const std::exception& e) {
        cerr << "Erro ao definir textos com entrada: " << e.what() << endl;
        exit(1);
    }
}

void Textos::Set_Contorno_Inicial_Texto() {
    try {
        textos[0].setOutlineThickness(0.6);
        textos[0].setOutlineColor(sf::Color(255,255,255));
    } catch (const std::exception& e) {
        cerr << "Erro ao definir contorno inicial: " << e.what() << endl;
    }
}

void Textos::Set_Contorno_Texto_Avancar(int posicao) {
    try {
        textos[posicao].setOutlineThickness(0.6);
        textos[posicao].setOutlineColor(sf::Color(255,255,255));
        textos[posicao - 1].setOutlineThickness(0);
    } catch (const std::exception& e) {
        cerr << "Erro ao avançar contorno: " << e.what() << endl;
    } 
}

void Textos::Set_Contorno_Texto_Voltar(int posicao) {
    try {
        textos[posicao].setOutlineThickness(0.6);
        textos[posicao].setOutlineColor(sf::Color(255,255,255));
        textos[posicao + 1].setOutlineThickness(0);
    } catch (const std::exception& e) {
        cerr << "Erro ao voltar contorno: " << e.what() << endl;
    }      
}