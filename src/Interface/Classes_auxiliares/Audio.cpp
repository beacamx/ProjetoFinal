#include "Audio.hpp"

void Audio::Set_Efeito_Sonoro_Selecao_Botao() {
    try {
        if (!buffer_selecao.loadFromFile("./assets/audio/c.wav")) {
            throw runtime_error("Erro ao carregar efeito sonoro de selecao");
        }
        som_selecao.setBuffer(buffer_selecao);
        som_selecao.setVolume(50);
    } catch (const runtime_error& e) {
        cerr << "Erro: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Exceção capturada: " << e.what() << endl;
    }
}

void Audio::Set_Music(const std::string& nome_jogo) {
    try {
        if(nome_jogo == "Lig4") {
            if (!som_jogo.openFromFile("./assets/audio/3.wav")) {
                throw runtime_error("Erro ao carregar a música");
            }
        } else if(nome_jogo == "Reversi"){
            if (!som_jogo.openFromFile("./assets/audio/4.wav")) {
                throw runtime_error("Erro ao carregar a música");
            }
        }
    } catch (const runtime_error& e) {
        cerr << "Exceção: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Exceção capturada: " << e.what() << endl;
    }
}

void Audio::Play_Efeito_Sonoro_Selecao_Botao() {
    try {
        som_selecao.play();
    } catch (const runtime_error& e) {
        cerr << "Erro: " << e.what() << std::endl;
    } catch (const exception& e) {
        cerr << "Exceção capturada: " << e.what() << endl;
    }
}

void Audio::Play_Music() {
    try {
        som_jogo.setVolume(2);
        som_jogo.setLoop(true);
        som_jogo.play();
    } catch (const runtime_error& e) {
        cerr << "Exceção: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Exceção capturada: " << e.what() << endl;
    }
}

void Audio::Stop_Music() {
    try {
        som_jogo.stop();
    } catch (const runtime_error& e) {
        cerr << "Exceção: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Exceção capturada: " << e.what() << endl;
    }
}
