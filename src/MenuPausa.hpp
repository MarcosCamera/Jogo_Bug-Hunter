#pragma once
#include "Menu.hpp"

class MenuPausa: public Menu {
private:
    bool pausado;
public:
    MenuPausa();
    ~MenuPausa();
    int mostrar(sf::RenderWindow& window);
    void setAtivo(const bool b=true);
};