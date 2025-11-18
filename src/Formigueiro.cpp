#include "Formigueiro.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;


using namespace Entidades::Obstaculos;


Formigueiro::Formigueiro(sf::Vector2f posicao = sf::Vector2f(0.0f, 0.0f)):
Obstaculo(posicao),
largura(0)
{
    corpo.setSize(sf::Vector2f(32.0f, 32.0f));
    sf::FloatRect bounds = corpo.getGlobalBounds();
    corpo.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
    
    const int LARGURA_FRAME = 32;
    const int ALTURA_FRAME = 32;
    corpo.setTextureRect(sf::IntRect(
        0,             
        0,             
        LARGURA_FRAME, 
        ALTURA_FRAME   
    ));

    try 
    {
        setTexture("Textures/flames.png");
        //corpo.setFillColor(sf::Color::Green);

    }
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }
    setDano(false);


}

Formigueiro::~Formigueiro(){}

void Formigueiro::executar(){}

void Formigueiro::obstaculizar(Personagens::Personagem*p)
{
    if (p) {
                sf::FloatRect intersec;
                sf::FloatRect jogadorBounds = p->getCorpo().getGlobalBounds();
                sf::FloatRect obstaculoBounds = this->getCorpo().getGlobalBounds();

                if (jogadorBounds.intersects(obstaculoBounds, intersec))
                {
                    sf::Vector2f novaPos = p->getPos();
                    if (intersec.width < intersec.height)
                    {

                        if (jogadorBounds.left < obstaculoBounds.left)
                        {
                            novaPos.x -= intersec.width;
                        }
                        else
                        {
                            novaPos.x += intersec.width;
                        }
                    }
                    else
                    {
                        if (jogadorBounds.top < obstaculoBounds.top)
                        {
                            novaPos.y -= intersec.height;
                        }
                        else
                        {
                            novaPos.y += intersec.height;
                        }
                    }

                    p->getCorpo().setPosition(novaPos);
                }
    }

}

void Formigueiro::setLargura(float l)
{
    largura = l;
}

float Formigueiro::getLargura()
{
    return largura;
}
}
