#include "Jogador.hpp"
#include "Gerenciador_Grafico.hpp"
#include <iostream>
using namespace std;

namespace Entidades
{
	namespace Personagens
	{
		Jogador::Jogador(sf::Vector2f posicao) : Personagem(), pontos(0)
        {
        
            impacto = 1;
            num_vidas = 10;
			try 
            {
                
                setTexture("Textures/spider2.png", sf::Vector2f(2.0f, 2.0f));
                if (pFig) {
                   sf::FloatRect bounds = pFig->getGlobalBounds();
                   pFig->setOrigin(bounds.width / 2.f, bounds.height / 2.f);
               }
               else
                 cout<<"Jogador -> pFig NULL"<< endl;
            }
            catch (const std::exception& e) 
            {
                std::cerr << e.what() << std::endl;
            }
            
            setVidas(10);
        }


		Jogador::~Jogador()
		{
			
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
        if (intersec.width < intersec.height)
        {
            pIn->mudaDir();

            if (inimigoBounds.left < jogadorBounds.left)
            {
                pIn->danificar(this);
                novaPos.x -= intersec.width;
                vel = (sf::Vector2f(static_cast<float>(-pIn->getImpacto()), static_cast<float>(-pIn->getImpacto() / 2)));
            }
            else
            {
                pIn->danificar(this);
                novaPos.x += intersec.width;
                vel = (sf::Vector2f(static_cast<float>(pIn->getImpacto()), static_cast<float>(-pIn->getImpacto() / 2)));
            }
        }
        else
        {
            if (inimigoBounds.top < jogadorBounds.top)
            {
                pIn->danificar(this);
                novaPos.y -= intersec.height;
                pIn->setVel(sf::Vector2f(pIn->getVel().x, -pIn->getVel().y));
            }
            else
            {
                danificarInim(pIn);
                
                sf::Vector2f currentPos = getPos();
                currentPos.y -= intersec.height;
                pFig->setPosition(currentPos);
                
                vel.y = -vel.y;
            }
        }

        pIn->setPos(novaPos);
    }
}

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
				vel.y -= 10 * velMovMax;
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
			controlar();   
            acelerar();   
            atualizaVel(); 
            atualizaPos();
        }

        void Jogador::setPontos(int p)
        {
            pontos = p;
        }

      
		void Jogador::executar()
		{
			mover();
		}
	}
}

