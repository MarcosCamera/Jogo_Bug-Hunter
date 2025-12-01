#include "Formiga.hpp"
#include <cmath>
using namespace std;

namespace Entidades
{
    namespace Personagens
    {
        int Formiga::numeroFormigas = 0;

        Formiga::Formiga():Inimigo(sf::Vector2f(0.0f, 0.0f), NULL), raio(10.0f)
        {
           numeroFormigas++;

           setChao(true);
            impacto = 1;
            num_vidas = 10;
            velMovMax = 1;
            direcao = false;
            try 
            {
                
                setTexture("Textures/antEnemy.png", sf::Vector2f(1.0f, 1.0f));
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
                 cout<<"Formiga -> pFig NULL"<< endl;
            }
            catch (const std::exception& e) 
            {
                std::cerr << e.what() << std::endl;
            }
        }

        Formiga::Formiga(sf::Vector2f pos, Listas::ListaEntidades* p) :Inimigo(pos, p), raio(10.0f)
        {
            numeroFormigas++;

            setChao(true);
            impacto = 1;
            num_vidas = 10;
            velMovMax = 1;
            direcao = false;
            try 
            {
                
                setTexture("Textures/antEnemy.png", sf::Vector2f(1.0f, 1.0f));
                if (pFig) {
                   sf::FloatRect bounds = pFig->getLocalBounds();
					pFig->setOrigin(bounds.width / 2.f, bounds.height);

					float tileLargura = 32.0f; 
					float tileAltura = 32.0f;

					sf::Vector2f centroBaseTile(pos.x + tileLargura / 2.f, pos.y + tileAltura);
					pFig->setPosition(centroBaseTile);
               }
               else
                 cout<<"Formiga -> pFig NULL"<< endl;
            }
            catch (const std::exception& e) 
            {
                std::cerr << e.what() << std::endl;
            }
          
        }

        Formiga::~Formiga()
        {
           numeroFormigas--;
           if (pFig)
            {
                delete pFig;
                pFig = NULL;
            }
        }
        
        float Formiga::getRaio()
        {
            return raio;
        }
        
         void Formiga::setNumeroFormigas(int n)
        {
            numeroFormigas = n;
        }

        int Formiga::getNumeroFormigas()
        {
            return numeroFormigas;
        }

        void Formiga::seguir(Jogador* pJog) //no gerenciador de eventos...
        {

          if(pJog){
            
            if (pJog->getPos().x < getPos().x)
                direcao = false;
            else
                direcao = true;
          }
            
        }

        float Formiga::verificaAlcance(Jogador* pJog) //em gerenciador de eventos
        {
            
            if (pJog)
            {
                float x = pos.x - pJog->getPos().x;
                float y = pos.y - pJog->getPos().y;
                float alcance = sqrt(x * x + y * y);
                return alcance;
            }
            return 100.0;
        
        }

        void Formiga::danificar(Jogador* p)
        {
            if (timer >= 10)
            {
                p->perdeVida(impacto);
                timer = 0;
            }
        }


        void Formiga::mover() 
        {
          
        
            if (!chao)
            {
                if (direcao && vel.x < velMovMax)
                {
                    acel.x = velMovMax / 10;
                }
                else if (!direcao && vel.x > -velMovMax)
                {
                    acel.x = -velMovMax / 10;
                }
            }
            acelerar();
            atualizaVel();
            if (chao) 
            {
                vel.y = 0;          
                acel.y = 0;          
            }
            
    
            vel.x = vel.x * (nivel_maldade + 1);

            atualizaPos();
        }
        void Formiga::executar() //no gerenciador de eventos: executar(pJog1, pJog2);
        {
    
            if (timer <= 10)
                timer++;

            
            mover();                        
        }

       
    }
}
