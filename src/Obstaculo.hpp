#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entidade.hpp"
#include "Jogador.hpp"

namespace Entidades::Obstaculos
{
  class Obstaculo : public Entidade{
     protected:
        bool danoso;
     public:
       Obstaculo();
       Obstaculo(const std::string& caminhoSprite, sf::Vector2f posicao);
       virtual ~Obstaculo();
       
       virtual void obstaculizar(Personagens::Jogador* p) = 0;
       virtual void executar()= 0;
       virtual void setDano(bool dano)=0;
       virtual bool getDano() = 0;

  };
