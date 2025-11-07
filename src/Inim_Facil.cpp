#include "Inim_Facil.hpp"
#include "Gerenciador_Grafico.hpp"

using namespace Entidades::Personagens;
using namespace std;

Inim_Facil::Inim_Facil():Inimigo(),raio(0){}

Inim_Facil::~Inim_Facil(){}


void Inim_Facil::verificaAlcance(*pJog)
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


void Inim_Facil::danificar(Jogador*pJog)
{
    pJog->num_vidas -= forca;
}


void Inim_Facil::mover() //pode fazer sobrecarga para o caso em que nao houver jogador proximo e o caso em que estiver no alcance do raio?
{
    if (chao)
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
        acel.y = gravidade;
    }

    vel += acel * (nivel_maldade + 1);
    pFig->move(vel);
}


void Inim_Facil::salva()
{
    //
}


void Inim_Facil::executar()
{
    mover();
}
