#include "Interface_Cadastro_Jogador1.hpp"
#include "Classes_auxiliares/Troca_Definicao_Entrada_Jogador.hpp"

using namespace std;

Interface_Cadastro_Jogador1::Interface_Cadastro_Jogador1() : Interface_Cadastro_Base() {
    try {
        Set_Values();
    } catch (const std::exception& e) {
        cerr << "Erro ao inicializar Interface_Cadastro_Jogador1: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

void Interface_Cadastro_Jogador1::Loop_Events() {
    sf::Event evento;
    int tam_vetor_texto = textos.Get_Tamanho_Vetor_Textos();

    try {
        while(janela->pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                janela->close();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) {
                // audio.Play_Efeito_Sonoro_Selecao_Botao();
                if(posicao < tam_vetor_texto - 1) {
                    ++posicao;
                    pressed = true;
                    textos.Set_Contorno_Texto_Avancar(posicao);
                    caixa_de_texto1.Definir_Selecao(false);
                    caixa_de_texto2.Definir_Selecao(false);
                    pressed = false;
                    seleção_ativa = false;
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed) {
                // audio.Play_Efeito_Sonoro_Selecao_Botao();
                if(posicao > 0) {
                    --posicao;
                    pressed = true;
                    textos.Set_Contorno_Texto_Voltar(posicao);
                    caixa_de_texto1.Definir_Selecao(false);
                    caixa_de_texto2.Definir_Selecao(false);
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
                    Troca_Definicao_Entrada_Jogador troca_Definicao_Entrada_Jogador;
                    nome_jogador1 = caixa_de_texto2.Obter_Texto_Entrada();
                    string apelido = caixa_de_texto1.Obter_Texto_Entrada();
                    Interface_Base::Set_Apelido_Jogador1(apelido);
                    cadastro& registro_geral_ref = Interface_Base::Get_Registro_Geral();
                    try {
                        if((!(registro_geral_ref.find_by_nick(apelido))) && (nome_jogador1.length() > 0) && (apelido.length() > 0)) { 
                            registro_geral_ref.cadastrar(new Jogador(nome_jogador1, apelido));
                            cout << "Tamanho vetor de jogadores:" << registro_geral_ref.jogadores.size() << endl;
                            janela->close();
                            troca_Definicao_Entrada_Jogador.Troca_Definicao_Jogador();
                        } else if ((!registro_geral_ref.find_by_nick(apelido)) && (nome_jogador1.length() == 0)  && (apelido.length() > 0)){
                            cerr << "Aviso: Digite seu nome";
                            cout << endl;
                            aviso.setString("Aviso: Digite seu nome");
                            Set_Aviso();
                            //audio.Play_Efeito_Sonoro_Aviso();
                            seleção_ativa = false;
                        } else if((apelido.length() == 0) && (nome_jogador1.length() > 0)) {
                            cerr << "Aviso: Digite seu apelido";
                            cout << endl;
                            aviso.setString("Aviso: Digite seu apelido");
                            Set_Aviso();
                            //audio.Play_Efeito_Sonoro_Aviso();
                            seleção_ativa = false;
                        } else if((apelido.length() == 0) && (nome_jogador1.length() == 0)) {
                            cerr << "Aviso: Digite seu nome e apelido";
                            cout << endl;
                            aviso.setString("Aviso: Digite seu nome e apelido");
                            Set_Aviso();
                            seleção_ativa = false;
                        } else {
                            cerr << "Aviso: Jogador já existente";
                            cout << endl;
                            aviso.setString("Aviso: Jogador ja existente");
                            Set_Aviso();
                            //audio.Play_Efeito_Sonoro_Aviso();
                            seleção_ativa = false;
                        }
                    } catch (const runtime_error& e) {
                        cerr << "Erro ao cadastrar o Jogador: " << e.what() << endl;
                    }        
                }
            }

            if (evento.type == sf::Event::TextEntered) {
                try {
                    caixa_de_texto1.Processar_Entrada(evento);
                    caixa_de_texto2.Processar_Entrada(evento);
                } catch (const exception& e) {
                    cerr << "Erro ao processar entrada de texto: " << e.what() << endl;
                }
            }
        }
    } catch (const exception& e) {
        cerr << "Erro durante o loop de eventos: " << e.what() << endl;
    }  catch (...) {
        cerr << "Erro desconhecido no loop de eventos" << endl;
    }

    if (mostrar_aviso && clock_aviso.getElapsedTime().asSeconds() > 2) {
        mostrar_aviso = false;
    }
}

