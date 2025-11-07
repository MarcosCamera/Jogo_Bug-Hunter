#include "Plataforma.hpp"
#include <iostream>
using namespace std;

using namespace Entidades::Obstaculos;

Plataforma::Plataforma():Obstaculo(), altura(){}

Plataforma::Plataforma( const std::string& caminhoSprite, sf::Vector2f posicao):Obstaculo(caminhoSprite, posicao), altura(0)
{
    if (pFig)
      pFig->setScale(0.6f, 0.3f);
    else
      std::cout << "Plataforma::Plataforma()-> pFig NULL" << std::endl;
    setDano(false);
} 

Plataforma::~Plataforma(){}

void Plataforma::executar(){}

void Plataforma::obstaculizar(Personagens::Jogador* p)
{
   if(p){
      sf::FloatRect intersec; 
      sf::FloatRect jogadorBounds = p->getGlobalBounds();
      sf::FloatRect obstaculoBounds = this->getGlobalBounds();
      
   if(jogadorBounds.intersects(obstaculoBounds, intersec))
   {    
     sf::Vector2f novaPos = p->getPos();
     if (intersec.width < intersec.height)
     {
        
         if (jogadorBounds.left < obstaculoBounds.left)
         {
             novaPos.x -= intersec.width;
         }
         else
         {
             novaPos.x += intersec.width;
         }
     }
     else
     {
         if (jogadorBounds.top < obstaculoBounds.top)
         {
             novaPos.y -= intersec.height;
         }
         else
         {
             novaPos.y += intersec.height;
         }
     }
     
     p->setPos(novaPos);
    }
  }
}
