#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entidade.hpp"
#include "Jogador.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Folha;
        class PlantaCarnivora;
        class Formigueiro;

        class Obstaculo : public Entidade 
        {
        protected:
            bool danoso;
            int timer;

        public:
            Obstaculo();
            virtual ~Obstaculo();

            virtual void obstaculizar(Personagens::Personagem* pE) = 0;
            virtual void executar() = 0;
        };
    }
}
