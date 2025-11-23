#include "Formiga.hpp"

using namespace std;

namespace Entidades
{
    namespace Personagens
    {
        int Formiga::numeroFormigas = 0;

        Formiga::Formiga(sf::Vector2f pos) :Inimigo(), raio(30)
        {
            pFig->setPosition(pos);
            impacto = 1;
            num_vidas = 10;
            velMovMax = 1;
        }

        Formiga::~Formiga()
        {
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

        void Formiga::seguir(Jogador* pJ) //no gerenciador de eventos
        {
            if (pJ)
            {
                if (pJ->getPos().x < getPos().x)
                    direcao = false;
                else
                    direcao = true;
            }

        }

        float Formiga::verificaAlcance(Jogador* pJ) //em gerenciador de eventos
        {
            if (pJ)
            {
                float x = pos.x - pJ->getPos().x;
                float y = pos.y - pJ->getPos().y;
                float alcance = sqrt(x * x + y * y);
                return alcance;
            }
            return 100.0;
        }

        void Formiga::danificar(Jogador* pJog)
        {
            if (timer >= 10)
            {
                pJog->perdeVida(impacto);
                timer = 0;
            }
        }


        void Formiga::mover() //atualizar. consertar.
        {
            if (chao)
            {
                if (direcao && vel.x < velMovMax)
                {
                    acel.x = velMovMax / 10;
                }
                else if (!direcao && vel.x > -velMovMax)
                {
                    acel.x = -velMovMax / 10;
                }
                    //direção do jogador //gerenciador eventos
                //vel.y = 0;
            }

            acelerar();
            atualizaVel();
            // qual ordem de inicialização de velocidades?
            vel.x += acel.x * (nivel_maldade + 1);
            vel.y += acel.y * (nivel_maldade + 1);

            atualizaPos();
        }

        void Formiga::executar()
        {
            if (timer <= 10) //timer para nao dar dano continuo
                timer++;

            mover();
        }
    }
}