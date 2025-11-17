#include "Jogador.hpp"
#include "Gerenciador_Grafico.hpp"
#include <iostream>
using namespace std;

namespace Entidades
{
	namespace Personagens
	{
		Jogador::Jogador() :Personagem(), pontos(0)
		{
			pFig->setPosition(10, 300); //setar posiçao padrao na fase.
			impacto = 1;
			num_vidas = 10;
			velMovMax = 2;
		}
		//para jogador2, posiçao relativa ao jogador 1, ou ambos aparecem ao mesmo tempo.

	/* Posso fazer: (?)
	Jogador::Jogador():Personagem():Entidade(5, 10, ...), pontos {}
	*/


		Jogador::~Jogador()
		{
			if (pFig)
			{
				delete pFig;
				pFig = NULL;
			}
		}

		void Jogador::danificarInim(Inimigo* pIn)
		{
			pIn->perdeVida(impacto);
		}

		void Jogador::colidir(Inimigo* pIn)
		{
			/*
			float alturaJog = getFig()->getGlobalBounds().height;
			float alturaInim = pIn->getFig()->getGlobalBounds().height;
			
			if (pos.y + alturaJog < pIn->getPos().y + alturaInim)
			{
				danificarInim(pIn);
				vel.y = -vel.y; // * 0.9 relativo a perda de energia?
			}*/
			
			sf::FloatRect intersec;
			sf::FloatRect inimigoBounds = pIn->getFig()->getGlobalBounds();
			sf::FloatRect jogadorBounds = this->getFig()->getGlobalBounds();

			if (inimigoBounds.intersects(jogadorBounds, intersec))
			{
				sf::Vector2f novaPos = pIn->getPos();
				if (intersec.width < intersec.height) //colisao horizontal
				{
					pIn->mudaDir(); //talvez nao seja necessario o if seguinte?

					if (inimigoBounds.left < jogadorBounds.left) //inimigo esquerda
					{
						pIn->danificar(this);
						novaPos.x -= intersec.width;
					}
					else //inimigo direita
					{
						pIn->danificar(this);
						novaPos.x += intersec.width;
					}
				}
				else //colisao vertical
				{
					if (inimigoBounds.top < jogadorBounds.top) //inimigo em cima
					{
						pIn->danificar(this);
						novaPos.y -= intersec.height;
						pIn->setVel(sf::Vector2f(pIn->getVel().x, -pIn->getVel().y));
					}
					else //inimigo embaixo
					{
						danificarInim(pIn);
						novaPos.y += intersec.height;
						vel.y = -vel.y;
					}
				}

				pIn->setPos(novaPos);
			}

			if (pIn->getPos().x > getPos().x)
			{
				vel = (sf::Vector2f(-pIn->getImpacto(), -pIn->getImpacto()/2));
			}
			else
			{
				vel = (sf::Vector2f(-pIn->getImpacto(), pIn->getImpacto() / 2));
			}
		}


		void Jogador::salvar() {}//...


		void Jogador::controlar()
		{
			//int keyTimeMax = 1; // delay para mover novamente //faço como atributo(???)
			//posição mouse //para debugar
			/* sf::Vector2i posMouse = sf::Mouse::getPosition(*pGG->getWindow());
			setPos(static_cast<float>(posMouse.x), static_cast<float>(posMouse.y));*/


			//implementar para ao invés de aumentar a velocidade, o controle modificar a aceleração ate a velocidade limite.
			//velocidade = velocidade + aceleração;
			//posiçao = posiçao + velocidade; // talvez esse seja melhor para padronizar. Teria que fazer um setPosicao.
			//.move(velocidade); um dos dois.
			//implementar o mesmo para outras entidades.
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && vel.x > (-velMovMax) )
			{
				vel.x -= velMovMax;
				direcao = false;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && vel.x < velMovMax )
			{
				vel.x += velMovMax;
				direcao = true;
			}
			

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && chao )
			{
				vel.y -= 5 * velMovMax;
			}
			/*
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && vel.y < velMovMax)
				//&& timer >= keyTimeMax)
			{
				vel.y += velMovMax / 10; //na pratica so a gravidade acelera
				//timer = 0;
			}
			*/
			//timer++;
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				vel.x = 0;
			}

			//if(jog2) //para jogador 2
		}
			//é possivel implementar tambem sem haver uma velocidade maxima mas com a desaceleraçao naturalmente limitando


		void Jogador::mover()
		{
			acelerar();
			atualizaVel(); //antes ou depois das acelerações? Testar com ambas formas.
			controlar();
			atualizaPos();
		}


		void Jogador::executar()
		{
			mover();
		}
	}
}