#include "Interface_Login_Jogador1.hpp"
#include "Classes_auxiliares/Troca_Definicao_Entrada_Jogador.hpp"

Interface_Login_Jogador1::Interface_Login_Jogador1() : Interface_Login_Base() { 
    try {
        Set_Values();
    } catch (const std::exception& e) {
        cerr << "Erro ao inicializar Interface_Login_Jogador1: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

void Interface_Login_Jogador1::Loop_Events(){
    sf::Event evento;
    int tam_vetor_texto = textos.Get_Tamanho_Vetor_Textos();

    while(janela->pollEvent(evento)) {
        try {
            if (evento.type == sf::Event::Closed) {
                janela->close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) {
                if (posicao < tam_vetor_texto - 1) {
                    ++posicao;
                    pressed = true;
                    caixa_de_texto1.Definir_Selecao(false);
                    textos.Set_Contorno_Texto_Avancar(posicao);
                    pressed = false;
                    seleção_ativa = false;
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed) {
                if (posicao > 0) {
                    --posicao;
                    pressed = true;
                    caixa_de_texto1.Definir_Selecao(false);
                    textos.Set_Contorno_Texto_Voltar(posicao);
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
                string apelido = caixa_de_texto1.Obter_Texto_Entrada();
                Interface_Base::Set_Apelido_Jogador1(apelido);
                cadastro& registro_geral_ref = Interface_Base::Get_Registro_Geral();
                if(apelido.length() == 0) {
                    cerr << "Aviso: Digite um apelido" << endl;
                    aviso.setString("Aviso: Digite um apelido");
                    Set_Aviso();
                    seleção_ativa = false;
                } else if(registro_geral_ref.find_by_nick(apelido)) {
                    Troca_Definicao_Entrada_Jogador troca_Definicao_Entrada_Jogador;
                    janela->close();
                    troca_Definicao_Entrada_Jogador.Troca_Definicao_Jogador();
                } else {
                    cerr << "Aviso: Jogador nao existente" << endl;
                    aviso.setString("Aviso: Jogador nao existente");
                    Set_Aviso();
                    seleção_ativa = false;
                }
            } 
        }

            if (evento.type == sf::Event::TextEntered) {
                caixa_de_texto1.Processar_Entrada(evento);
            }
        } catch (const std::exception& e) {
            cerr << "Erro ao processar evento: " << e.what() << endl;
        } catch (...) {
            cerr << "Erro desconhecido ao processar evento." << endl;
        }
    }

    if (mostrar_aviso && clock_aviso.getElapsedTime().asSeconds() > 2) {
        mostrar_aviso = false;
    }
}
