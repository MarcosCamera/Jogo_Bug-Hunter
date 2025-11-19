#include "Folha.hpp"
#include <iostream>
using namespace std;

namespace Entidades
{
    namespace Obstaculos
    {
        Folha::Folha() :Obstaculo(), altura(0), alturaMax(3), alturaMin(1)
        {
            altura = pFig->getGlobalBounds().height;
            pFig->setPosition(0, 500); //setar posiçao padrao na fase.
        }

        
        Folha::Folha(sf::Vector2f posicao) :Obstaculo(), altura(0)
        {
            pFig->setPosition(posicao);
        }

        Folha::~Folha()
        {
            if (pFig)
            {
                delete pFig;
                pFig = NULL;
            }
        }

        void Folha::obstaculizar(Personagens::Personagem* p)
        {
            if (p) 
            {
                sf::FloatRect intersec;
                sf::FloatRect personagemBounds = p->getFig()->getGlobalBounds();
                sf::FloatRect obstaculoBounds = this->getFig()->getGlobalBounds();

                if (personagemBounds.intersects(obstaculoBounds, intersec))
                {
                    sf::Vector2f novaPos = p->getPos();
                    sf::Vector2f novaVel = p->getVel();

                    if (intersec.width < intersec.height)                   //colisao horizontal
                    {
                        if (personagemBounds.left < obstaculoBounds.left)   //personagem na esquerda
                        {
                            novaPos.x -= intersec.width;
                        }
                        else                                                //Personagem na direita
                        {
                            novaPos.x += intersec.width;
                        }

                        p->mudaDir();
                    }
                    else                                                    //colisao vertical
                    {
                        if (personagemBounds.top < obstaculoBounds.top)     //personagem em cima
                        {
                            novaPos.y -= intersec.height;

                            if (delay)
                            {
                                novaVel.y = - altura;
                                crescer();
                            }
                        }
                        else                                                //personagem embaixo
                        {
                            novaPos.y += intersec.height;

                            if(delay)
                            {
                                novaVel.y = altura;
                                diminuir();
                            }
                        }
                    }

                    p->setPos(novaPos);
                    p->setVel(novaVel);
                }
            }
        }

        void Folha::crescer()
        {
            if (altura < alturaMax)
            {
                altura++;
                pFig->setScale(1, altura);
            }
        }

        void Folha::diminuir()
        {
            if (altura > alturaMin)
            {
                altura--;
                pFig->setScale(1, altura);
            }
        }

        bool Folha::delay()
        {
            if (timer > 10)
            {
                timer = 0;
                return true;
            }
        }

        void Folha::executar() 
        {
            timer++;
        }
    }
}