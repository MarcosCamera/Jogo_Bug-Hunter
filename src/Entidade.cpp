#include "Entidade.hpp"
#include <iostream>
using namespace std;
using namespace Entidades;


Entidade::Entidade(sf::Vector2f posicao) :Ente(), vel(), acel(), gravidade(10), normal(10), chao(false), arrasto(1), velMovMax(10), direcao(true)
{
      sf::FloatRect bounds = corpo.getGlobalBounds();
      corpo.setPosition(posicao); 
       
    
}

Entidade::~Entidade()
{

}

void Entidade::setVel(sf::Vector2f velocidade)
{
   vel = velocidade;

}



sf::Vector2f Entidade::getVel() const
{
    return vel;
}

sf::Vector2f Entidade::getPos() const
{
    return this->corpo.getPosition();
}

 void Entidade::acelerar() //incluir todas acelerações
    {
        acel.y = (gravidade * !chao)  - (vel.y * arrasto);
        
        if (vel.x > velMovMax)
            acel.x = - vel.x * arrasto;
        //acel.x com resistencia
    }

    void Entidade::atualizaVel() //ou apenas vel = vel + acel; ?
    {
        if (vel.x < velMovMax)
        {
            if (vel.x + acel.x > velMovMax) {
                vel.x = velMovMax;
                vel.y += acel.y;
            }
            else
                vel += acel;
        }
    }
 void Entidade::setChao(bool c)
{
        chao = c;
}
