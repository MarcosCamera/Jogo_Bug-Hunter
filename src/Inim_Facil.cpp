#include "Inim_Facil.hpp"
#include "Gerenciador_Grafico.hpp"
#include <iostream>

using namespace Entidades::Personagens;
using namespace std;

Inim_Facil::Inim_Facil():Inimigo(),
    raio(0),
    direcao(true),
    ground(false),
    gravidade(10.0f)
{
    
  if (!tex.loadFromFile("Textures/spider.png")) {
        cout<< "ERRO: Nao foi possivel carregar a textura da aranha!" << endl;
  }
  pFig->setTexture(tex);
  pFig->setScale(0.03f, 0.03f);
  setPos(100.0f, 100.0f);

}
Inim_Facil::~Inim_Facil(){}

void Inim_Facil:: executar()
{
   mover();
   desenhar();
}

void Inim_Facil::danificar(Jogador*p)
{
   
}


void Inim_Facil::mover()
{
   if (!ground) {
        vel.y += gravidade * 0.1f;
    } else {
        vel.y = 0;
    }
    pFig->move(0.0f, vel.y);

    sf::Vector2u tamanhoJanela = pGG->getWindow()->getSize();
    if (pFig->getPosition().y >= tamanhoJanela.y - pFig->getGlobalBounds().height)
    {
        ground = true;
        pFig->setPosition(pFig->getPosition().x, tamanhoJanela.y - pFig->getGlobalBounds().height);
    }
    
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