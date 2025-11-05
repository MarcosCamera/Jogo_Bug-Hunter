#pragma once
#include "Inimigo.hpp"
#include "Jogador.hpp"

namespace Entidades::Personagens
{
    class Inim_Facil : public Inimigo
    {
        private:
          float raio;
          sf::Texture tex;
          bool direcao; // true = direita, false = esquerda
          bool ground;
          float gravidade;
          
        
        public:
          Inim_Facil();
          ~Inim_Facil();
          void executar();
          void danificar(Jogador* p);
          void mover();
    };
}