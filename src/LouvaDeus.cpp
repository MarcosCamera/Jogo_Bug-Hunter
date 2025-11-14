#include "louvaDeus.hpp"

#include "Gerenciador_Grafico.hpp"
#include "Jogador.hpp"
using namespace std;

namespace Entidades
{
    namespace Personagens
    {
        LouvaDeus::LouvaDeus() :Inimigo(), forca(0)
        {
            pFig->setPosition(250, 300); //setar posiçao padrao na fase.
            impacto = 1;
            num_vidas = 10;
        }

        LouvaDeus::~LouvaDeus()
        {
            if (pFig)
            {
                delete pFig;
                pFig = NULL;
            }
        }


        void LouvaDeus::verificaAlcance(Jogador* pJog) //em gerenciador de eventos
        {
            if (!pJog)
            {
                cout << "Jogador não encontrado" << endl;
                return;
            }

            float x = pos.x - pJog->getPos().x;
            float y = pos.y - pJog->getPos().y;
            if (sqrt(x * x + y * y) <= raio && !nivel_maldade)
            {
                operator++;
            }
        }

        void LouvaDeus::seguir(Jogador* pJog) //no gerenciador de eventos...
        {
            if (nivel_maldade)
            {
                if (pJog->getPos().x < getPos().x)
                    direcao = false;
                else
                    direcao = true;
            }
        }


        void LouvaDeus::danificar(Jogador* pJog)
        {
            pJog->setVida(impacto);
        }


        void LouvaDeus::mover() //pode fazer sobrecarga para o caso em que nao houver jogador proximo e o caso em que estiver no alcance do raio?
        {
            if (chao)
            {
                normal = -gravidade;

                if (direcao && vel.x < velMovMax)
                {
                    acel.x = velMovMax / 4;
                }
                else if (!direcao && vel.x > -velMovMax)
                {
                    acel.x = -velMovMax / 4;
                }
                //direção do jogador //gerenciador eventos
            //vel.y = 0;
            }
            else
            {
                normal = 0;
            }
            acelerar();
            atualizaVel();
            // qual ordem de inicialização de velocidades?
            vel.x += acel.x * (nivel_maldade + 1);
            vel.y += acel.y * (nivel_maldade + 1);


            pFig->move(vel);
        }


        void LouvaDeus::salvar()
        {
            //
        }


        void LouvaDeus::executar()
        {
            //seguir() tambem
            //verificaAlcance(Jogador *pJog); nao funciona porque nao passa por parametro na funçao
            mover();                        //solução: ponteiro de jogadores. A fase deve começar com ambos jogadores ou um só
        }
    }
}