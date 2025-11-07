#pragma once
#include "Inimigo.hpp"
#include "Jogador.hpp"

namespace Entidades::Personagens
{
    class Inim_Facil : public Inimigo
    {
        private:
          float raio; //alcance do jogador para nivel de maldade.
                      //se estiver no raio de alcance, a velocidade altera
                      //e deixa de ser aleatoria para seguir o jogador
          //pCabeca //a cabeça será separada do corpo e terá movimento próprio, seguindo o jogador.
          
        public:
          Inim_Facil();
          ~Inim_Facil();

          void danificar(Jogador* p);
          void mover();
          void executar();
    };
}