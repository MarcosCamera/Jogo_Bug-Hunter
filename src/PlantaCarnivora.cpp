#include "PlantaCarnivora.hpp"

namespace Entidades 
{
	namespace Obstaculos
	{
		PlantaCarnivora::PlantaCarnivora() : Obstaculo(), danosidade(2), orientacao(0)
		{
			danoso = true;
		}

		PlantaCarnivora::PlantaCarnivora(sf::Vector2f posicao) : Obstaculo(), danosidade(2), orientacao(0)
		{
			danoso = true;

            if (pFig)
            {
                pFig->setPosition(posicao);
            }
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
                    sf::Vector2f novaPosPerson = p->getPos();
                    sf::Vector2f novaPosPlant = getPos();

                    if (intersec.width < intersec.height)                   //colisao horizontal
                    {
                        if (personagemBounds.left < obstaculoBounds.left)   //na esquerda
                        {
                            novaPosPlant.x += intersec.width;
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
                            novaPosPlant.x -= intersec.width;
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
                            novaPosPerson.y -= intersec.height;

                            if (!orientacao)
                            {
                                danificarPersonagem(p);
                            }
                        }
                        else                                                //embaixo
                        {
                            novaPosPerson.y += intersec.height;
                        }
                    }

                    p->setPos(novaPosPerson);
                    setPos(novaPosPlant);
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
           
            if (ori)  //rotacionar
            {
                sf::FloatRect bound = pFig->getLocalBounds();
                pFig->setOrigin(bound.left + bound.width * 0.5f, bound.top + bound.height * 0.5f);
                pFig->setRotation(90.f * ori);
                pFig->setOrigin(bound.left, bound.top);
            }
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

        void PlantaCarnivora::mover()
        {
            acelerar();
            atualizaVel();
            atualizaPos();
        }

        void PlantaCarnivora::executar()
        {
            delay();
        }
	}
}