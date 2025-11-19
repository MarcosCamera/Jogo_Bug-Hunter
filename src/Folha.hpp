#pragma once
#include "Obstaculo.hpp"
#include "Personagem.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Folha : public Obstaculo
        {
        private:
            int altura;
            int alturaMax;
            int alturaMin;

        public:
            Folha();
            Folha(sf::Vector2f posicao);
            ~Folha();

            void obstaculizar(Personagens::Personagem* p);
            void crescer();
            void diminuir();
            bool delay();
            void executar();
        };
    }
}
