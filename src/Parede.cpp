#include "Parede.hpp"

namespace Entidades
{
	Parede::Parede() : Entidade()
	{

	}

	Parede::~Parede()
	{
		if (pFig)
		{
			delete pFig;
			pFig = NULL;
		}
	}

    void Parede::obstaculizar(Personagens::Personagem* p)
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
}
