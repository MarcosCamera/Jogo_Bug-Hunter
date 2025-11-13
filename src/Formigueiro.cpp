#include "Formigueiro.hpp"
#include "Jogador.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

namespace Entidades
{
    namespace Obstaculos
    {

        Formigueiro::Formigueiro() :Obstaculo(), largura() {}
        /*Formigueiro::Formigueiro(const std::string& caminhoSprite, sf::Vector2f posicao) :
        Obstaculo(caminhoSprite, posicao),
        largura(0)
        {
          if (pFig)
              pFig->setScale(0.05f,0.05f);
            else
              cout<<"Formigueiro::Formigueiro()-> pFig NULL"<<endl;
          setDano(false);

        }*/

        Formigueiro::~Formigueiro() {}

        void Formigueiro::executar() {}

        void Formigueiro::obstaculizar(Personagens::Jogador* p)
        {
            if (p && !getDano()) {
                Vector2f novaPos = p->getPos();
                FloatRect intersec;
                if (p->getFig()->getGlobalBounds().intersects(this->getFig()->getGlobalBounds(), intersec))
                {
                    if (intersec.width < intersec.height)
                    {

                        if (p->getFig()->getGlobalBounds().left < this->getFig()->getGlobalBounds().left)
                        {
                            novaPos.x -= intersec.width;
                        }
                        else
                        {
                            novaPos.x += intersec.width;
                        }
                    }
                    else
                    {
                        if (p->getFig()->getGlobalBounds().top < this->getFig()->getGlobalBounds().top)
                        {
                            novaPos.y -= intersec.height;
                        }
                        else
                        {
                            novaPos.y += intersec.height;
                        }
                    }

                    p->setPos(novaPos);
                }
            }


        }

        void Formigueiro::setLargura(float l)
        {
            largura = l;
        }

        float Formigueiro::getLargura()
        {
            return largura;
        }
    }
}