#include "LouvaDeus.hpp"

#include "Gerenciador_Grafico.hpp"
#include "Jogador.hpp"
using namespace std;

namespace Entidades
{
    namespace Personagens
    {
        LouvaDeus::LouvaDeus() :Inimigo(), forca(5), voo(false)
        {
            pFig->setPosition(250, 300); //setar posiçao padrao na fase.
            impacto = 1;
            num_vidas = 10;
            velMovMax = 3;
        }

        LouvaDeus::LouvaDeus(sf::Vector2f(posicao)) :Inimigo(), forca(5), voo(false)
        {
            pFig->setPosition(posicao); //setar posiçao padrao na fase.
            impacto = 1;
            num_vidas = 10;
            velMovMax = 3;
        }
        LouvaDeus::~LouvaDeus()
        {
            if (pFig)
            {
                delete pFig;
                pFig = NULL;
            }
        }


        void LouvaDeus::danificar(Jogador* pJog)
        {
            pJog->perdeVida(impacto);
        }

        void LouvaDeus::atirar()
        {
            if (timer % (5 - nivel_maldade) == 0)
            {
                disparar = true;
            }
        }


        void LouvaDeus::mover()
        {
            acelerar();
            acel.y += forca * voo;
            atualizaVel();
            atualizaPos();
        }

        void LouvaDeus::atualizaMaldade()
        {
            if (!nivel_maldade && num_vidas < 5)
            {
                operator++();
            }
            else if (nivel_maldade < 2 && num_vidas < 2)
            {
                operator++();
            }
        }

        void LouvaDeus::executar()
        {
            if (timer >= 10)
            {
                voo = !voo;
                timer = 0;
            }
            timer++;
            
            atualizaMaldade();
            mover();
            atirar();
        }
    }
}