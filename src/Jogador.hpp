#pragma once
#include "Personagem.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <list>

namespace Entidades::Personagens{
class Jogador : public Personagem{
    protected:
       int pontos;
       sf::Texture tex;

    public:
     Jogador();
     ~Jogador();

    void executar();
    void mover();
    


};
}