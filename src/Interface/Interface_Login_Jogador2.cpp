#include "Interface_Login_Jogador2.hpp"

Interface_Login_Jogador2::Interface_Login_Jogador2() : Interface_Login_Base() { 
    try {
        Set_Values();
    } catch (const std::exception& e) {
        cerr << "Erro ao inicializar Interface_Login_Jogador2: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

void Interface_Login_Jogador2::Loop_Events(){
    sf::Event evento;
    int tam_vetor_texto = textos.Get_Tamanho_Vetor_Textos();

    while(janela->pollEvent(evento)) {
        if (evento.type == sf::Event::Closed) {
            janela->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
            // audio.Play_Efeito_Sonoro_Selecao_Botao();
            if(posicao < tam_vetor_texto - 1){
                ++posicao;
                pressed = true;
                caixa_de_texto1.Definir_Selecao(false);
                textos.Set_Contorno_Texto_Avancar(posicao);
                pressed = false;
                seleção_ativa = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
            // audio.Play_Efeito_Sonoro_Selecao_Botao();
            if(posicao > 0){
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
                apelido_jogador2 = caixa_de_texto1.Obter_Texto_Entrada();
                cout << endl << apelido_jogador2 << endl;
                cadastro& registro_geral_ref = Interface_Base::Get_Registro_Geral();
                if(registro_geral_ref.find_by_nick(apelido_jogador2)) {
                    cout << "Tamanho vetor de jogadores:" << registro_geral.jogadores.size() << endl;
                    define_jogo = make_unique<Interface_Define_Jogo>();
                    janela->close();
                    define_jogo->Run();
                } else {
                    cerr << "Aviso: Jogador nao existente" << endl;
                    Set_Aviso();
                    //audio.Play_Efeito_Sonoro_Aviso();
                    seleção_ativa = false;
                }
            } 
        }

        if (evento.type == sf::Event::TextEntered) {
            caixa_de_texto1.Processar_Entrada(evento);
        }

        if (mostrar_aviso && clock_aviso.getElapsedTime().asSeconds() > 2) {
        mostrar_aviso = false;
    }
    }
}