#include "Folha.hpp"
#include <iostream>
using namespace std;

namespace Entidades
{
    namespace Obstaculos
    {
        Folha::Folha() :Obstaculo(), altura(0), alturaMax(3), alturaMin(1)
        {
            altura = static_cast<int>(pFig->getGlobalBounds().height);
            pFig->setPosition(0, 500);
    

            try 
            {
                setTexture("Textures/grass.png", sf::Vector2f(1.f, 1.f)); 
                if (pFig) {
                   sf::FloatRect bounds = pFig->getGlobalBounds();
                   pFig->setOrigin(bounds.width / 2.f, bounds.height / 2.f);
               }
               else
                 cout<<"Folha->pFigNULL"<<endl;
                
            }
            catch (const std::exception& e) 
            {
                std::cerr << e.what() << std::endl;
            }
         
            setDano(false);//aqui

        }

        
        Folha::Folha(sf::Vector2f posicao) :Obstaculo(), altura(0)
        {
            pFig->setPosition(posicao);
        }

        Folha::~Folha()
        {
           
        }

        void Folha::setAltura(int a)
        {
            altura = a;
        }

        int Folha::getAltura()
        {
            return altura;
        }
        
        void Folha::obstaculizar(Personagens::Personagem* p)
        {
            if (p) 
            {
                sf::FloatRect intersec;
                sf::FloatRect personagemBounds = p->getFig()->getGlobalBounds();
                sf::FloatRect obstaculoBounds = this->getFig()->getGlobalBounds();

                if (personagemBounds.intersects(obstaculoBounds, intersec))
                {
                    sf::Vector2f novaPos = p->getPos();
                    sf::Vector2f novaVel = p->getVel();

                    if (intersec.width < intersec.height)                   //colisao horizontal
                    {
                        if (personagemBounds.left < obstaculoBounds.left)   //personagem na esquerda
                        {
                            novaPos.x -= intersec.width;
                        }
                        else                                                //Personagem na direita
                        {
                            novaPos.x += intersec.width;
                        }

                        p->mudaDir();
                    }
                    else                                                    //colisao vertical
                    {
                        if (personagemBounds.top < obstaculoBounds.top)     //personagem em cima
                        {
                            novaPos.y -= intersec.height;

                            if (delay())
                            {
                                novaVel.y = static_cast<float>(-altura * 5);
                                crescer();
                            }
                        }
                        else                                                //personagem embaixo
                        {
                            novaPos.y += intersec.height;

                            if(delay())
                            {
                                novaVel.y = static_cast<float>(altura*5);
                                diminuir();
                            }
                        }
                    }

                    p->getFig()->setPosition(novaPos);
                    p->setVel(novaVel);
                }
            }
        }

        void Folha::crescer()
        {
            if (altura < alturaMax)
            {
                altura++;
                pFig->setScale(1, static_cast<float>(altura));
            }
        }

        void Folha::diminuir()
        {
            if (altura > alturaMin)
            {
                altura--;
                pFig->setScale(1, static_cast<float>(altura));
            }
        }

        bool Folha::delay()
        {
            
            if (timer > 10)
            {
                timer = 0;
                return true;
            }
            return false;
        }

        void Folha::mover() //trabalhar mais
        {
            acelerar();
            atualizaVel();
            atualizaPos();
        }

        void Folha::executar() 
        {
            timer++;
        }

       
        
    }
}
