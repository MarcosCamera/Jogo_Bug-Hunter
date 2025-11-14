#include "Formiga.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Jogador.hpp" // Certifique-se de incluir o cabeçalho completo de Jogador
using namespace std;

namespace Entidades
{
    namespace Personagens
    {
        Formiga::Formiga() :Inimigo(), raio(0)
        {
            pFig->setPosition(250, 300); //setar posiçao padrao na fase.
            impacto = 1;
            num_vidas = 10;
        }

        Formiga::~Formiga()
        {
            if (pFig)
            {
                delete pFig;
                pFig = NULL;
            }
        }

        void Formiga::seguir(Jogador* pJog) //no gerenciador de eventos...
        {
            if (nivel_maldade)
            {
                if (pJog->getPos().x < getPos().x)
                    direcao = false;
                else
                    direcao = true;
            }
        }

        void Formiga::verificaAlcance(Jogador* pJog) //em gerenciador de eventos
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
            seguir(pJog);
        }

        void Formiga::danificar(Jogador* pJog)
        {
            pJog->setVida(impacto);
        }


        void Formiga::mover() //pode fazer sobrecarga para o caso em que nao houver jogador proximo e o caso em que estiver no alcance do raio?
        {
            if (chao)
            {
                normal = - gravidade;

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


        void Formiga::salvar()
        {
            //
        }


        void Formiga::executar() //no gerenciador de eventos: executar(pJog1, pJog2);
        {
            verificaAlcance(pJog1);
            //verificaAlcance(pJog2);
            mover();                        //solução: ponteiro de jogadores. A fase deve começar com ambos jogadores ou um só
        }
    }
}