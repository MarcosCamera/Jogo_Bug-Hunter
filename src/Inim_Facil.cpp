#include "Inim_Facil.hpp"
#include "Gerenciador_Grafico.hpp"

using namespace Entidades::Personagens;
using namespace std;

Inim_Facil::Inim_Facil():Inimigo(),raio(0){}

Inim_Facil::~Inim_Facil(){}


void Inim_Facil::danificar(Jogador*p)
{
   //...
}


void Inim_Facil::mover()
{
    if (chao)
    {
        if (/*colisao horizontal */ )
        {
            direcao = !direcao; // Inverte a direção //ser chamada no gerenciador de colisao
        }

        float velocidadeX = direcao ? 2.0f : -2.0f;
        pFig->move(velocidadeX, 0.0f);
    }
    pFig->move(vel);
}


void Inim_Facil::executar()
{
    mover();
}
