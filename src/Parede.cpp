#include "Parede.hpp"

namespace Entidades
{
    Parede::Parede(sf::Vector2f posicao, int id_tile) : Entidade(),colidiu(false)
    {
        chao = true;
        setPos(posicao);

        try
        {
            setTexture("Textures/chao.png", sf::Vector2f(1.0f, 1.0f));
            //text.setRepeated(true);

            if (pFig) {
                pFig->setOrigin(0.f, 0.f);
            }
            else {
                std::cout << "Parede -> pFig NULL" << std::endl;
            }
        }

        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
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
                    if (entidadeBounds.left < paredeBounds.left)        //na esquerda
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
                    if (entidadeBounds.top < paredeBounds.top)          //em cima
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

    void Parede::mover()
    {
        acelerar();
        atualizaVel();
        atualizaPos();
    }

    void Parede::executar()
    {

    }
}
