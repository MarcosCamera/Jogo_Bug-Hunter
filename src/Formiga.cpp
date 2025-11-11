#include "Formiga.hpp"
#include "Gerenciador_Grafico.hpp"

using namespace Entidades::Personagens;
using namespace std;

Formiga::Formiga():Inimigo(),raio(0)
{
    pFig->setPosition(250, 300); //setar posiçao padrao na fase.
    forca = 1;
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


void Formiga::verificaAlcance(*pJog)
{
    if (!pJog)
    {
        cout << "Jogador não encontrado" << endl;
        return;
    }

    float x = pos.x - pJog->pos.x;
    float y = pos.y - pJog->pos.y;
    if (sqrt(x * x + y * y) <= raio && !nivel_maldade)
    {
        nivel_maldade++;
    }
}


void Formiga::danificar(Jogador*pJog)
{
    pJog->num_vidas -= forca;
}


void Formiga::mover() //pode fazer sobrecarga para o caso em que nao houver jogador proximo e o caso em que estiver no alcance do raio?
{
    if (chao)
    {
        if (!nivel_maldade)
        {
            if (direcao && vel < velMovMax)
            {
                acel.x = velMovMax / 4;
            }
            else if (!direcao && vel > -velMovMax)
            {
                acel.x = -velMovMax / 4;
            }
        }
        else
        {
            //direção do jogador //gerenciador eventos
        }
    }
    else
    {
        acel.y = gravidade;
    }

    vel += acel * (nivel_maldade + 1);
    pFig->move(vel);
}


void Formiga::salva()
{
    //
}


void Formiga::executar()
{
    verificaAlcance(*pJog);
    mover();
}
