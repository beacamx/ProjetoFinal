#include "Interface_Cadastro_Jogador1.hpp"
#include "Troca_Definicao_Entrada_Jogador.hpp"

using namespace std;

Interface_Cadastro_Jogador1::Interface_Cadastro_Jogador1()
    : define_jogo(nullptr), caixa_de_texto1(15, sf::Color::White, false), caixa_de_texto2(15, sf::Color::White, false) {
    Set_Values();
}

Interface_Cadastro_Jogador1::~Interface_Cadastro_Jogador1(){}

void Interface_Cadastro_Jogador1::Set_Opcoes() {
    opcoes_de_escolha = {"Digitar apelido", "Digitar nome", "Play"};
}

void Interface_Cadastro_Jogador1::Set_Textos() {
    tamanho_fonte = {19, 19, 17};
    int indice = 0;

    for (size_t i = 0; i < opcoes_de_escolha.size(); ++i) {
        if(indice == 2) {
            float pos_y = altura_texto + (i * espaco_vertical_botao_play);
            coords.push_back(sf::Vector2f(largura_janela / 2, pos_y));
            break;
        }
        float pos_y = altura_texto + (i * espaco_vertical);
        coords.push_back(sf::Vector2f(largura_janela / 2, pos_y));
        ++indice;
    }

    texto.resize(opcoes_de_escolha.size());

    for(size_t i{}; i < texto.size(); ++i) {
        texto[i].setFont(*font);
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

void Interface_Cadastro_Jogador1::Set_Image() {
    if (!image->loadFromFile("./assets/Menu/Cadastro.png")) 
        cerr << "Erro ao carregar imagem de fundo" << endl;

    background->setTexture(*image);
} 

void Interface_Cadastro_Jogador1::Definicoes_Espacamento_Janela() {
    espaco_vertical = 77.0f;
    espaco_vertical_botao_play = 83.0f;
    largura_janela = 624.0f;
    altura_texto = 206.0f; 
}

void Interface_Cadastro_Jogador1::Set_Values(){
    Set_Efeito_Sonoro_Selecao_Botao();
    Set_Font();
    Set_Janela();
    Centralizar_Janela();
    Set_Image();
    Set_Opcoes();

    posicao = 0;
    pressed = theselect = false;
    
    Definicoes_Espacamento_Janela();

    coords.clear();

    Set_Textos();
    Set_Contorno_Inicial();

    float largura_caixa = 120.0f;
    float espaco_adicional_entre_caixa_apelido = 7.0f;

    float posicao_x_caixa_texto = (largura_janela - largura_caixa) / 2;
    float posicao_y_caixa_texto1 = coords[0].y + texto[0].getGlobalBounds().height + espaco_adicional_entre_caixa_apelido;
    float posicao_y_caixa_texto2 = posicao_y_caixa_texto1 + 79.0f;

    caixa_de_texto1.Set_Font(*font);
    caixa_de_texto1.Set_Position({posicao_x_caixa_texto, posicao_y_caixa_texto1});
    caixa_de_texto1.Set_Limit(true, 10);

    caixa_de_texto2.Set_Font(*font);
    caixa_de_texto2.Set_Position({posicao_x_caixa_texto, posicao_y_caixa_texto2});
    caixa_de_texto2.Set_Limit(true, 10);

    janela->setKeyRepeatEnabled(true);
}

void Interface_Cadastro_Jogador1::Loop_Events(){
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
                Set_Contorno_Avancar(posicao);
                pressed = false;
                theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
            som_selecao.play();
            if(posicao > 0){
                --posicao;
                pressed = true;
                Set_Contorno_Voltar(posicao);
                pressed = false;
                theselect = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
            if (posicao == 0) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                    caixa_de_texto1.Set_Selected(true);
                    caixa_de_texto2.Set_Selected(false);
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    caixa_de_texto1.Set_Selected(false);
                    caixa_de_texto2.Set_Selected(false);
                }
            } else if (posicao == 1) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                    caixa_de_texto1.Set_Selected(false);
                    caixa_de_texto2.Set_Selected(true);
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    caixa_de_texto1.Set_Selected(false);
                    caixa_de_texto2.Set_Selected(false);
                }
            } else if (posicao == 2) {
                theselect = true;
                Troca_Definicao_Entrada_Jogador troca_Definicao_Entrada_Jogador;
                if (troca_Definicao_Entrada_Jogador.numero_jogador == 1) {
                    janela->close();
                    troca_Definicao_Entrada_Jogador.Troca_Definicao_Jogador();
                } else if (troca_Definicao_Entrada_Jogador.numero_jogador == 2) {
                    janela->close();
                    string nome_jogador = caixa_de_texto1.Get_Text();
                    try {
                        registro_geral.cadastrar(new jogador(nome_jogador));

                        define_jogo = make_unique<Interface_Define_Jogo>();
                        define_jogo->Run_Menu();
                    } catch(const runtime_error& e){ 
                        cerr << "Erro ao cadastrar o jogador: " << e.what() << endl;
                        throw;
                    }
                } else {

                }
            } else {
                    cerr << "Erro ao definir jogador" << endl;
            }
        }

        if (evento.type == sf::Event::TextEntered) {
            caixa_de_texto1.Typed_On(evento);
            caixa_de_texto2.Typed_On(evento);
        }
    }
}

void Interface_Cadastro_Jogador1::Draw_All() {
    this->janela->clear();
    this->janela->draw(*background);
    int tamanho_texto = texto.size();
    if(tamanho_texto) {
        for (const auto& text : texto) {
            janela->draw(text);
        }
    }
    caixa_de_texto1.Draw_To(*janela);
    caixa_de_texto2.Draw_To(*janela);
    this->janela->display();
}