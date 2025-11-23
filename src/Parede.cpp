#include "Parede.hpp"

namespace Entidades
{
	Parede::Parede() : Entidade(), colidiu(false)
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

    void Parede::obstaculizar(Entidades::Entidade* p)
    {
        if (p)
        {
            sf::FloatRect intersec;
            sf::FloatRect entidadeBounds = p->getFig()->getGlobalBounds();
            sf::FloatRect paredeBounds = this->getFig()->getGlobalBounds();

            if (entidadeBounds.intersects(paredeBounds, intersec))
            {
                colidiu = true;

                sf::Vector2f novaPos = p->getPos();
                if (intersec.width < intersec.height)                   //colisao horizontal
                {
                    if (entidadeBounds.left < paredeBounds.left)   //na esquerda
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
                    if (entidadeBounds.top < paredeBounds.top)     //em cima
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
