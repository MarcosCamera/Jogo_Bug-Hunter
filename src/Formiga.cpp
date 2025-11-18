#include "Formiga.hpp"

using namespace std;

namespace Entidades
{
    namespace Personagens
    {
        Formiga::Formiga(sf::Vector2f pos) :Inimigo(), raio(0.5), pJog(NULL)
        {
            pFig->setPosition(pos);
            impacto = 1;
            num_vidas = 10;
            velMovMax = 1;
        }

        Formiga::Formiga(Jogador* pJ) :Inimigo(), raio(0.5), pJog(NULL)
        {
            pJog = pJ;
            pFig->setPosition(250, 300); //setar posiçao padrao na fase.
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

        void Formiga::setJogador(Jogador* pJ)
        {
            pJog = pJ;
        }

        void Formiga::seguir() //no gerenciador de eventos...
        {
            if (!pJog)
            {
                cout << "Jogador não encontrado" << endl;
                return;
            }

            if (nivel_maldade) //desnecessario agora? se entrar na função o nivel maldade ja é 1
            {
                if (pJog->getPos().x < getPos().x)
                    direcao = false;
                else
                    direcao = true;
            }
        }

        void Formiga::verificaAlcance(Jogador* pJ) //em gerenciador de eventos
        {
            if (!pJ)
            {
                cout << "Jogador não encontrado" << endl;
                return;
            }

            float x = pos.x - pJ->getPos().x;
            float y = pos.y - pJ->getPos().y;
            if (sqrt(x * x + y * y) <= raio && !nivel_maldade) //corrigir para o centro da sprite (ou nao)
            {
                operator++();
            }
            setJogador(pJ);
        }

        void Formiga::danificar(Jogador* pJog)
        {
            if (timer >= 10)
            {
                pJog->perdeVida(impacto);
                timer = 0;
            }
        }


        void Formiga::mover() //pode fazer sobrecarga para o caso em que nao houver jogador proximo e o caso em que estiver no alcance do raio?
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

        void Formiga::executar() //no gerenciador de eventos: executar(pJog1, pJog2);
        {
            if (timer <= 10) //timer para nao dar dano continuo
                timer++;
            seguir();
            //verificaAlcance(pJog1);
            //verificaAlcance(pJog2);
            mover();                        //solução: ponteiro de jogadores. A fase deve começar com ambos jogadores ou um só
        }
    }
}