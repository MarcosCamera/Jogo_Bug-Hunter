#pragma once
#include "Obstaculo.hpp"
#include "Jogador.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Folha : public Obstaculo
        {
        protected:
            int altura;

        public:
            Folha();
            Folha(sf::Vector2f posicao);
            ~Folha();

            void obstaculizar(Personagens::Personagem* p);
            void executar();
        };
    }
}
