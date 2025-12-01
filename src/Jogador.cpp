#include "Jogador.hpp"
#include "Gerenciador_Grafico.hpp"
#include <iostream>
using namespace std;

namespace Entidades
{
	namespace Personagens
	{
        Jogador::Jogador():Personagem(sf::Vector2f(0.0f, 0.0f), NULL), pontos(0.0f),cooldownTiro(0.5f),tempoCooldown(0.0f), tiro(false)
		{
		try 
		
            {
                
                setTexture("Textures/spider2.png", sf::Vector2f(2.0f, 2.0f));
                if (pFig) {
					sf::FloatRect bounds = pFig->getLocalBounds();
					pFig->setOrigin(bounds.width / 2.f, bounds.height);

					sf::Vector2f posAtual = getPos();

					float tileLargura = 32.0f; 
					float tileAltura = 32.0f;
					sf::Vector2f centroBaseTile(posAtual.x + tileLargura / 2.f, posAtual.y + tileAltura);
					pFig->setPosition(centroBaseTile);
				
               }
               else
                 cout<<"Jogador -> pFig NULL"<< endl;
            }
            catch (const std::exception& e) 
            {
                std::cerr << e.what() << std::endl;
            }
		}

		Jogador::Jogador(sf::Vector2f pos, Listas::ListaEntidades* p ) : Personagem(pos, p), pontos(0), cooldownTiro(0.5f), tempoCooldown(0.0f)
        {
			try 
            {
                
                setTexture("Textures/spider2.png", sf::Vector2f(2.0f, 2.0f));
                if (pFig) {
					sf::FloatRect bounds = pFig->getLocalBounds();
					pFig->setOrigin(bounds.width / 2.f, bounds.height);

					float tileLargura = 32.0f; 
					float tileAltura = 32.0f;

					sf::Vector2f centroBaseTile(pos.x + tileLargura / 2.f, pos.y + tileAltura);
					pFig->setPosition(centroBaseTile);
               }
               else
                 cout<<"Jogador -> pFig NULL"<< endl;
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
            if (tecla == 'A' && vel.x > (-velMovMax))
			{
				vel.x -= velMovMax;
				direcao = false;
			}

			if (tecla == 'D' && vel.x < velMovMax )
			{
				
				vel.x += velMovMax;
				direcao = true;
			}
			

			if (tecla == 'W' && chao)
			{
				vel.y -= 5 * velMovMax;
			}
			
			if (tecla == 'Z')
			{
				vel.x = 0;
			}


		}
			
		Entidades::Teia* Jogador::atirarTeia() { 
			if (tempoCooldown <= 0.0f && getAtirar()) {
				 cout << "Criando nova teia..." << endl;
				 sf::Vector2f posicaoTeia;
				if (direcao) 
				{ 
					
					posicaoTeia = sf::Vector2f(pos.x + 25.0f, 384.0f + 8.0f);//ajeitar aqui...
				} 
				else 
				{ 
					posicaoTeia = sf::Vector2f(pos.x - 5.0f, 384.0f + 8.0f);//ajeitar aqui
				}
				Entidades::Teia* novaTeia = new Entidades::Teia(posicaoTeia); 
				float velHorizontal = 5.0f; 
				if (!direcao) { 
					velHorizontal = -velHorizontal;
				}
					
				novaTeia->setVel(sf::Vector2f(velHorizontal, 0.0f)); 
				tempoCooldown = cooldownTiro;
				setAtirar(false);
				return novaTeia; 
			}
			return NULL;
	   }
       
	   void Jogador:: setAtirar(bool t)
	   {
		 tiro = t;
	   }

	   bool Jogador::getAtirar()
	   {
		 return tiro;
	   }

		void Jogador::mover()
		{
		
            acelerar(); 
			
            atualizaVel(); 
			
            atualizaPos();
		
			 
        }



       
		void Jogador::executar()
		{
			
			
			mover();

					
		
		}
	}
}

