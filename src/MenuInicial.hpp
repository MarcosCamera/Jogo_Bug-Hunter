#pragma once
#include "Menu.hpp"

class MenuInicial : public Menu {
private:
    sf::Text seletores[2];
    sf::Text instrucoes;
	sf::Text nomeJogo;
    int etapa;
    int nJogadores;
    int fase;

public:
    MenuInicial();
    ~MenuInicial();
    int mostrar(sf::RenderWindow& window);
    int getNJogadores() const;
    int getFase() const;
};