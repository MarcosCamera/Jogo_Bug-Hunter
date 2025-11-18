#include "Parede.hpp"
#include <iostream>

using namespace std;

namespace Entidades
{
    
    Parede::Parede(sf::Vector2f posicao, sf::Vector2f dimensoes)
        : Entidade(posicao), altura(dimensoes.y) 
    {
        corpo.setSize(dimensoes);
        
        
        setVel(sf::Vector2f(0.0f, 0.0f)); 
    }

    Parede::~Parede()
    {
        
    }

    void Parede::executar()
    {
        
    }

    //implementar tratarColisoes??
}
