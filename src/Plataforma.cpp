#include "Plataforma.hpp"
#include <iostream>
using namespace std;

namespace Entidades
{
    namespace Obstaculos
    {
        Plataforma::Plataforma() :Obstaculo(), altura()
        {
            pFig->setPosition(0, 500); //setar posiçao padrao na fase.
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

        void Plataforma::obstaculizar(Personagens::Personagem* p)
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

        void Plataforma::salvar() {}

        void Plataforma::executar() {}
    }
}
