#include "Obstaculo.hpp"
#include "Jogador.hpp"
#pragma once
/* obstáculo imóvel e que não causa dano ao jogador*/
namespace Entidades::Obstaculos
{
    class Formigueiro:public Obstaculo
    {
         protected:
            float largura;
            
         public:
          Formigueiro(sf::Vector2f posicao);
          ~Formigueiro();
          
           void executar();
           void obstaculizar(Personagens::Personagem* p);
           void setLargura(float l);
           float getLargura();
    };
}
