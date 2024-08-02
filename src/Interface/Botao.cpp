#include "Botao.hpp"

Botao::Botao(float x, float y, float largura_botao, float altura_botao, 
    sf::Font* fonte, string texto, 
    sf::Color cor_inativa, sf::Color hover_color, sf::Color cor_ativa) {
    
    this->estado_botao = BOTAO_INATIVO;

    this->caixa.setSize(sf::Vector2f(largura_botao, altura_botao));
    this->caixa.setPosition(sf::Vector2f(x, y));

    this->fonte = fonte;

    this->texto.setFont(*this->fonte);
    this->texto.setString(texto);
    this->texto.setFillColor(sf::Color::White);
    this->texto.setCharacterSize(12);
    this->texto.setPosition(
        this->caixa.getPosition().x / 2.f - this->texto.getGlobalBounds().width / 2.f,
        this->caixa.getPosition().y / 2.f - this->texto.getGlobalBounds().height / 2.f
    );

    this->cor_inativa = cor_inativa;
    this->hover_color = hover_color;
    this->cor_ativa = cor_ativa;

    this->caixa.setFillColor(this->cor_inativa);
}

Botao::~Botao(){}

const bool Botao::isPressed() const {
    if(this->estado_botao == BOTAO_ATIVO)
        return true;
    return false;
}

void Botao::update(const sf::Vector2f posicao_mouse) {
    this->estado_botao = BOTAO_INATIVO;
    if (this->caixa.getGlobalBounds().contains(posicao_mouse)) {
        this->estado_botao = BOTAO_HOVER;

        if(this->posicao == 0){
            this->estado_botao = BOTAO_ATIVO;
        }
    }

    switch (this->estado_botao)
    {
    case BOTAO_INATIVO:
        this->caixa.setFillColor(this->cor_inativa);
        break;

    case BOTAO_HOVER:
        this->caixa.setFillColor(this->hover_color);
        break;

    case BOTAO_ATIVO:
        this->caixa.setFillColor(this->cor_ativa);
        break;
    
    default:
        this->caixa.setFillColor(sf::Color::Red);
        break;
    }
}

void Botao::render(sf::RenderTarget* target) {
    target->draw(this->caixa);
    target->draw(this->texto);
}