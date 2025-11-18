#include "LouvaDeus.hpp"

#include "Gerenciador_Grafico.hpp"
#include "Jogador.hpp"
using namespace std;

namespace Entidades
{
    namespace Personagens
    {
        LouvaDeus::LouvaDeus() :Inimigo(), forca(0), voo(-1)
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


        void LouvaDeus::danificar(Jogador* pJog)
        {
            pJog->perdeVida(impacto);
        }

        void LouvaDeus::atirar()
        {
            if (timer % 5 == 0)
            {
                disparar = true;
            }
        }


        void LouvaDeus::mover() //pode fazer sobrecarga para o caso em que nao houver jogador proximo e o caso em que estiver no alcance do raio?
        {
            vel.y = velMovMax * voo; //pode fazer normal = gravidade quando voo true e só atua vel. quando voo false só atua gravidade.
            atualizaPos();           //nesse caso, voo é bool.
        }

        void LouvaDeus::executar()
        {
            if (timer % 10)
            {
                voo *= -1;
                timer = 0;
            }
            timer++;
            
            mover();
            atirar();
        }
    }
}