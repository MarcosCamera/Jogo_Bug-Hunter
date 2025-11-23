#include "Parede.hpp"
#include <iostream>

using namespace std;

namespace Entidades
{
    
   Parede::Parede(sf::Vector2f posicao, int id_tile) : Entidade(posicao), altura(32.0f)
	{
        try 
        {
            
                
            setTexture("Textures/chao.png", sf::Vector2f(1.0f, 1.0f));
            //text.setRepeated(true);
            
            if (pFig) {
                pFig->setOrigin(0.f, 0.f);
            } else {
                cout<<"Parede -> pFig NULL"<< endl;
            }

            }

            catch (const std::exception& e) 
            {
                std::cerr << e.what() << std::endl;
        }
	}

	Parede::~Parede()
	{
		
	}

    void Parede::obstaculizar(Personagens::Personagem* p)
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
                    }
                    else                                                //na direita
                    {
                        novaPos.x += intersec.width;
                    }
                    p->mudaDir(); //talvez nao seja necessario o if seguinte?

                }
                else                                                    //colisao vertical
                {
                    if (personagemBounds.top < obstaculoBounds.top)     //em cima
                    {
                        p->setChao(true); //para o gerenciador de colis�es
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
    
    const float Parede::getAltura() 
    {
       return altura;
    }
    void Parede::executar()
    {

    }
    
}
