void Audio::Set_Efeito_Sonoro_Selecao_Botao() {
    try {
        if (!buffer_selecao.loadFromFile("./assets/audio/c.wav")) {
            throw runtime_error("Erro ao carregar efeito sonoro de selecao");
        }
        som_selecao.setBuffer(buffer_selecao);
        som_selecao.setVolume(50);
    } catch (const runtime_error& e) {
        cerr << "Erro: " << e.what() << std::endl;
    } catch (const exception& e) {
        cerr << "Exceção capturada: " << e.what() << std::endl;
    }
}

void Audio::Set_Efeito_Sonoro_Aviso() [
    try {
        if (!buffer_avisos.loadFromFile("./assets/audio/erro.ogg")) {
            throw runtime_error("Erro ao carregar efeito sonoro de aviso");
        }
        som_aviso.setBuffer(buffer_avisos);
        som_aviso.setVolume(50);
    } catch (const runtime_error& e) {
        cerr << "Erro: " << e.what() << std::endl;
    } catch (const exception& e) {
        cerr << "Exceção capturada: " << e.what() << std::endl;
    }
]

void Audio::Set_Music(string nome_jogo) {
    try {
        if(nome_jogo == "Lig4") {
            if (!som_jogo.openFromFile("./assets/audio/3.wav")) {
                throw runtime_error("Erro ao carregar a música");
            }

            som_jogo.setVolume(2);
            som_jogo.setLoop(true);
            som_jogo.play();
        } else if(nome_jogo == "Reversi"){
            if (!som_jogo.openFromFile("./assets/audio/4.wav")) {
                throw runtime_error("Erro ao carregar a música");
            }

            som_jogo.setVolume(2);
            som_jogo.setLoop(true);
            som_jogo.play();
        }
    } catch (const runtime_error& e) {
        std::cerr << "Exceção: " << e.what() << std::endl;
    } catch (const exception& e) {
        std::cerr << "Exceção capturada: " << e.what() << std::endl;
    }
}