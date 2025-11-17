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
			velMovMax = 1;
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
			float alturaJog = getFig()->getGlobalBounds().height;

			if (pos.y + 0.9 * alturaJog < pIn->getPos().y) //para o caso de o jogador passar pelo inimigo
				//ao invés de 0.9, o que poderia ser?
			{
				danificarInim(pIn);
				vel.y = -0.9f * vel.y; // 0.9 relativo a perda de energia. Pode se tornar atributo?
			}
			else
			{
				pIn->danificar(this); //ta certo???
			}
		}


		void Jogador::salvar() {}//...


		void Jogador::controlar()
		{
			int keyTimeMax = 1; // delay para mover novamente //faço como atributo(???)
			//posição mouse //para debugar
			/* sf::Vector2i posMouse = sf::Mouse::getPosition(*pGG->getWindow());
			setPos(static_cast<float>(posMouse.x), static_cast<float>(posMouse.y));*/


			//implementar para ao invés de aumentar a velocidade, o controle modificar a aceleração ate a velocidade limite.
			//velocidade = velocidade + aceleração;
			//posiçao = posiçao + velocidade; // talvez esse seja melhor para padronizar. Teria que fazer um setPosicao.
			//.move(velocidade); um dos dois.
			//implementar o mesmo para outras entidades.
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && vel.x > (-velMovMax) )
				//&& timer >= keyTimeMax)
			{
				vel.x -= velMovMax / 10; //há uma aceleração
				//timer = 0;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && vel.x < velMovMax )
				//&& timer >= keyTimeMax)
			{
				vel.x += velMovMax / 10;
				//timer = 0;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && chao )
				//&& timer >= keyTimeMax)
			{
				vel.y -= 2*velMovMax; //fazer como velocidade de pulo depois
				//timer = 0;
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
		}
		//é possivel implementar tambem sem haver uma velocidade maxima mas com a desaceleraçao naturalmente limitando


		void Jogador::mover()
		{

			acelerar();
			controlar();
			atualizaVel(); //antes ou depois das acelerações? Testar com ambas formas.
			atualizaPos();
		}


		void Jogador::executar()
		{
			mover();
		}
	}
}