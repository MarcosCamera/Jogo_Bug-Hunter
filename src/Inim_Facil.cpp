#include "Inim_Facil.hpp"
#include "Gerenciador_Grafico.hpp"
#include <iostream>

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
   if (!ground) {
        vel.y += gravidade * 0.1f;
    } else {
        vel.y = 0;
    }
    pFig->move(0.0f, vel.y);

    
    
    if (ground)
    {
        
        if (pFig->getPosition().x + pFig->getGlobalBounds().width >= tamanhoJanela.x || pFig->getPosition().x <= 0)
        {
            direcao = !direcao; // Inverte a direção
        }

        float velocidadeX = direcao ? 2.0f : -2.0f;
        pFig->move(velocidadeX, 0.0f);
    }
}


void Inim_Facil::executar()
{
    mover();
}
