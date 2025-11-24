#pragma once
#include "Menu.hpp"

class MenuInicial : public Menu {
private:
    sf::Text seletores[2];
    sf::Text instrucoes;
	sf::Text nomeJogo;
    int nivel;
    int numJogadores;
    int fase;

public:
    MenuInicial();
    ~MenuInicial();
    int mostrar(sf::RenderWindow& window);
    int getNumJogadores() const;
    int getFase() const;
};
