#include "PlantaCarnivora.hpp"

namespace Entidades 
{
	namespace Obstaculos
	{
		PlantaCarnivora::PlantaCarnivora() : Obstaculo(), danosidade(2), orientacao(0)
		{
			danoso = true;
		}

		PlantaCarnivora::PlantaCarnivora(sf::Vector2f posicao) : Obstaculo(), danosidade(2)
		{
			danoso = true;
		}

		PlantaCarnivora::~PlantaCarnivora()
		{
			if (pFig)
			{
				delete pFig;
				pFig = NULL;
			}
		}

		void PlantaCarnivora::obstaculizar(Personagens::Personagem* p)
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
                            if (orientacao == -1)
                            {
                                danificarPersonagem(p);
                            }
                            else 
                            {
                                esbarrar(1);
                            }
                        }
                        else                                                //na direita
                        {
                            novaPos.x += intersec.width;
                            if (orientacao == 1)
                            {
                                danificarPersonagem(p);
                            }
                            else
                            {
                                esbarrar(1);
                            }
                        }

                        p->mudaDir();
                    }
                    else                                                    //colisao vertical
                    {
                        if (personagemBounds.top < obstaculoBounds.top)     //em cima
                        {
                            p->setChao(true); //para o gerenciador de colisões
                            novaPos.y -= intersec.height;

                            if (!orientacao)
                            {
                                danificarPersonagem(p);
                            }
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

        void PlantaCarnivora::danificarPersonagem(Personagens::Personagem* p)
        {
            if (danoso)
            {
                p->perdeVida(danosidade);
                danoso = false;
            }

        }

        void PlantaCarnivora::esbarrar(short int ori)
        {
            orientacao = ori;
            //girar!!!!
        }

        void PlantaCarnivora::delay()
        {
            if (!danoso && timer >= 10)
            {
                danoso = true;
                timer = 0;
            }

            if (timer < 10)
            {
                timer++;
            }
        }

        void PlantaCarnivora::executar()
        {
            delay();
        }
	}
}