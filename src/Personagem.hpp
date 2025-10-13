#define GRAVIDADE 10.0
#include <SFML/Graphics.hpp>
#include <iostream>

class Personagem{
    protected:
        sf::RectangleShape body;
        bool andar;
};