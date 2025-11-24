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
			num_vidas = 50;
			velMovMax = 2;
		}
		Jogador::Jogador(sf::Vector2f posicao) : Personagem(), pontos(0)
		{
			pFig->setPosition(posicao); //setar posiçao padrao na fase.
			impacto = 1;
			num_vidas = 10;
			velMovMax = 2;

			try
			{

				setTexture("Textures/spider2.png", sf::Vector2f(2.0f, 2.0f));
				if (pFig) {
					sf::FloatRect bounds = pFig->getGlobalBounds();
					pFig->setOrigin(bounds.width / 2.f, bounds.height / 2.f);
				}
				else
					cout << "Jogador -> pFig NULL" << endl;
			}
			catch (const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}


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
						vel = (sf::Vector2f(static_cast<float>(-pIn->getImpacto()), static_cast<float>(-pIn->getImpacto() / 2)));
					}
					else //inimigo direita
					{
						pIn->danificar(this);
						novaPos.x += intersec.width;
						vel = (sf::Vector2f(static_cast<float>(pIn->getImpacto()), static_cast<float>(-pIn->getImpacto() / 2)));
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
						pos.y -= intersec.height; //só aqui o jogador que ajusta sprite
						vel.y = -vel.y;
					}
				}

				pIn->setPos(novaPos);
			}
		}

		void Jogador::operator++()
		{
			pontos++;
		}

		void Jogador::controlar(char tecla)
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
			if (tecla == 'A' && vel.x > (-velMovMax))
			{
				vel.x -= velMovMax;
				direcao = false;
			}

			if (tecla == 'D' && vel.x < velMovMax)
			{
				vel.x += velMovMax;
				direcao = true;
			}
			

			if (tecla == 'W' && chao)
			{
				vel.y -= 5 * velMovMax;
			}

			if (tecla == 'S')
			{
				disparar = true;
			}
			
			if (tecla == 'Z')
			{
				vel.x = 0;
			}
		}

		void Jogador::mover()
		{
			acelerar();
			atualizaVel(); //antes ou depois das acelerações? Testar com ambas formas.
			atualizaPos();
		}


		void Jogador::executar()
		{
			mover();
		}
	}
}