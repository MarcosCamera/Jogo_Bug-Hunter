#include "Obstaculo.hpp"
#include "Jogador.hpp"
#pragma once

namespace Entidades::Obstaculos
{
    class Plataforma:public Obstaculo
    {
        protected:
           int altura;
            
         public:
          Plataforma();
          Plataforma(const std::string& caminhoSprite, sf::Vector2f position);
          ~Plataforma();

          void executar();
          void salvar();
          void obstaculizar(Personagens::Jogador* p);
    };
}
