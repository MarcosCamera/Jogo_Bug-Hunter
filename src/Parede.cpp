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
                if (intersec.width < intersec.height)                   //colisao horizontal
                {
                    if (personagemBounds.left < obstaculoBounds.left)   //na esquerda
                    {
                        novaPos.x -= intersec.width;
                    }
                    else                                                //na direita
                    {
                        novaPos.x += intersec.width;
                    }
                    p->mudaDir(); //talvez nao seja necessario o if seguinte?

                }
                else                                                    //colisao vertical
                {
                    if (personagemBounds.top < obstaculoBounds.top)     //em cima
                    {
                        p->setChao(true); //para o gerenciador de colisões
                        novaPos.y -= intersec.height;
                    }
                    else                                                //embaixo
                    {
                        novaPos.y += intersec.height;
                    }
                }

                p->setPos(novaPos);
            }
        }
    }

    void Parede::executar()
    {

    }
}
