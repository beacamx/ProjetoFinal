#include "Caixa_de_texto.hpp"

Caixa_de_texto::Caixa_de_texto() {}

Caixa_de_texto::Caixa_de_texto(int tamanho_caixa, sf::Color cor_caixa, bool sel) {
    caixa_de_texto.setCharacterSize(tamanho_caixa);
    caixa_de_texto.setFillColor(cor_caixa);
    selecionado = sel;
    if (sel) {
        caixa_de_texto.setString("_");
    } else {
        caixa_de_texto.setString("");
    }
}

void Caixa_de_texto::Logica_Entrada (int charTyped) {
    try {
        if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
            texto_de_entrada << static_cast<char>(charTyped);
        } else if (charTyped == DELETE_KEY) {
            if (texto_de_entrada.str().length() > 0) {
                Excluir_Ultimo_Caractere();
            }
        }
        caixa_de_texto.setString(texto_de_entrada.str() + "_");
    } catch (const exception& e) {
        cerr << "Erro na lógica de entrada da caixa de texto: " << e.what() << endl;
    }
}

void Caixa_de_texto::Excluir_Ultimo_Caractere() {
    try {
        string aux =  texto_de_entrada.str();
        if(!aux.empty()) {
            string new_aux = "";
            int tamanho_aux = aux.length();
            for (int i = 0; i < tamanho_aux - 1; i++) 
                new_aux += aux[i];
            texto_de_entrada.str("");
            texto_de_entrada << new_aux;
            caixa_de_texto.setString(texto_de_entrada.str());
        }
    } catch (const std::exception& e) {
        cerr << "Erro ao deletar o último caractere: " << e.what() << endl;
    }
}

void Caixa_de_texto::Definir_Fonte(sf::Font &font) {
    caixa_de_texto.setFont(font);
}

void Caixa_de_texto::Definir_Posicao(sf::Vector2f position) {
    caixa_de_texto.setPosition(position);
}

void Caixa_de_texto::Definir_Limite(bool com_limite, int lim) {
    tem_limite = com_limite;
    limite = lim - 1;
}

/*bool Caixa_de_texto::Caixa_Esta_Selecionada() const { 
    return caixa_selecionada; 
}*/

void Caixa_de_texto::Definir_Selecao(bool sel) {
    selecionado = sel;

    try {
        if (!sel) {
            string aux =  texto_de_entrada.str();
            string new_aux = "";
            int tamanho_aux = aux.length();
            for (int i = 0; i < tamanho_aux; i++) 
                new_aux += aux[i];

            caixa_de_texto.setString(new_aux);
        }
    } catch (const exception& e) {
        cerr << "Erro ao atualizar a string da caixa de texto: " << e.what() << endl;
    }
}

string Caixa_de_texto::Obter_Texto_Entrada() {
    return texto_de_entrada.str();
}

void Caixa_de_texto::Draw_To(sf::RenderWindow &janela) {
    try {
        janela.draw(caixa_de_texto);
    } catch (const exception& e) {
        cerr << "Erro ao desenhar a caixa de texto: " << e.what() << endl;
    }
}

void Caixa_de_texto::Processar_Entrada(sf::Event input) {
    try {
        int tamanho_texto_login = texto_de_entrada.str().length();
        if (selecionado) {
            int Char_Typed = input.text.unicode;
            if (Char_Typed < 128) {
                if (tem_limite) {
                    if (tamanho_texto_login <= limite) {
                        Logica_Entrada(Char_Typed);
                    } else if (tamanho_texto_login > limite && Char_Typed == DELETE_KEY) {
                        Excluir_Ultimo_Caractere();
                    }
                } else {
                    Logica_Entrada(Char_Typed);
                }
            }
        }
    } catch (const  exception& e) {
        cerr << "Erro ao processar entrada de texto: " << e.what() << endl;
    }
}

void Caixa_de_texto::Definir_Configuracoes_Caixa_de_Texto(sf::Font &font, sf::Vector2f position, bool com_limite, int lim) {
    Definir_Fonte(font);
    Definir_Posicao(position);
    Definir_Limite(com_limite, lim);
}