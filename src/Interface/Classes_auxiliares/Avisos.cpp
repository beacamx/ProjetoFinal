void Avisos::Set_Aviso() {
    try {
        const sf::Font& fonte = texto.Get_Fonte();
        aviso.setFont(fonte); 
        aviso.setCharacterSize(18);
        aviso.setFillColor(sf::Color::Red);
    } catch (const exception& e) {
        cerr << "Erro ao definir aviso: " << e.what() << endl;
    }
}

void Avisos::Som_Aviso() {
    audio.Set_Efeito_Sonoro_Aviso();
}
