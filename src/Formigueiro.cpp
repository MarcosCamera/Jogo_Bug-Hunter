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
        int Formigueiro::numeroFormigueiros = 0;

        Formigueiro::Formigueiro(sf::Vector2f posicao, int l) : Obstaculo(), largura(1), ativo(true)
        {
            largura = static_cast<float>(l);

            if (pFig)
            {
                pFig->setScale(static_cast<float>(largura), 1.f);
                pFig->setPosition(posicao);
            }
            else
                cout << "Formigueiro::Formigueiro()-> pFig NULL" << endl;
        }

        Formigueiro::Formigueiro(sf::Vector2f posicao): Obstaculo(), largura(1)
        {
            if (pFig)
            {
                pFig->setScale(static_cast<float>(largura), 1.f);
                pFig->setPosition(posicao);
            }
            else
                cout<<"Formigueiro::Formigueiro()-> pFig NULL"<<endl;
        }

        Formigueiro::~Formigueiro() 
        {
            if (pFig)
            {
                delete pFig;
                pFig = NULL;
            }
        }

        void Formigueiro::setNumeroFormigueiros(int n)
        {
            numeroFormigueiros = n;
        }

        int Formigueiro::getNumeroFormigueiros()
        {
            return numeroFormigueiros;
        }

        void Formigueiro::setLargura(float l)
        {
            largura = l;
        }

        float Formigueiro::getLargura()const
        {
            return largura;
        }

        bool Formigueiro::getAtividade()const
        {
            return ativo;
        }

        void Formigueiro::obstaculizar(Personagens::Personagem* p)
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
                            p->setChao(true); //para o gerenciador de colisões
                            novaPos.y -= intersec.height;
                            ativo = false;
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

        void Formigueiro::vibrar()
        {
            if (timer * largura >= 20)
            {
                pFig->move(1.f, 0.f);
                if (timer * largura >= 40)
                {
                    pFig->move(-1.f, 0.f);
                    timer = 0;
                }
            }
            timer++;
        }

        void Formigueiro::executar() 
        {
            vibrar();
        }
    }
}