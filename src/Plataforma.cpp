#include "Plataforma.hpp"
#include <iostream>
using namespace std;

namespace Entidades
{
    namespace Obstaculos
    {
        Plataforma::Plataforma() :Obstaculo(), altura()
        {
            pFig->setPosition(0, 500); //setar posi�ao padrao na fase.
        }

        /*Plataforma::Plataforma(const std::string& caminhoSprite, sf::Vector2f posicao) :Obstaculo(caminhoSprite, posicao), altura(0)
        {
            if (pFig)
              pFig->setScale(0.6f, 0.3f);
            else
              std::cout << "Plataforma::Plataforma()-> pFig NULL" << std::endl;
            setDano(false);
        } */

        Plataforma::~Plataforma()
        {
            if (pFig)
            {
                delete pFig;
                pFig = NULL;
            }
        }

        void Plataforma::executar() {}

        void Plataforma::salvar() {}

        void Plataforma::obstaculizar(Personagens::Personagem* p)
        {
            if (p) {
                sf::FloatRect intersec;
                sf::FloatRect personagemBounds = p->getFig()->getGlobalBounds();
                sf::FloatRect obstaculoBounds = this->getFig()->getGlobalBounds();

                if (personagemBounds.intersects(obstaculoBounds, intersec))
                {
                    sf::Vector2f novaPos = p->getPos();
                    if (intersec.width < intersec.height)
                    {

                        if (personagemBounds.left < obstaculoBounds.left)
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
                        if (personagemBounds.top < obstaculoBounds.top)
                        {
                            novaPos.y -= intersec.height;
                            p->setChao(true); // Se colidiu pela parte de cima, est� no ch�o
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
    }
}