#include "Folha.hpp"
#include <iostream>
using namespace std;

namespace Entidades
{
    namespace Obstaculos
    {
        Folha::Folha() :Obstaculo(), altura(0)
        {
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
                    if (intersec.width < intersec.height) //colisao horizontal
                    {
                        p->mudaDir(); //talvez nao seja necessario o if seguinte?

                        if (personagemBounds.left < obstaculoBounds.left)
                        {
                            novaPos.x -= intersec.width;
                        }
                        else
                        {
                            novaPos.x += intersec.width;
                        }
                    }
                    else //colisao vertical
                    {
                        p->setChao(true); //para o gerenciador de colisões
                        if (personagemBounds.top < obstaculoBounds.top)
                        {
                            novaPos.y -= intersec.height;
                        }
                        else
                        {
                            novaPos.y += intersec.height;
                        }
                    }

                    p->setPos(novaPos);
                }
            }
        }

        void Folha::executar() {}
    }
}