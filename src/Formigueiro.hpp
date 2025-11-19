#pragma once

#include "Obstaculo.hpp"
#include "Jogador.hpp"

/* obstáculo imóvel e que não causa dano ao jogador*/
namespace Entidades
{
    namespace Obstaculos
    {
        class Formigueiro: public Obstaculo
        {
        private:
            float largura; //largura diz quantas formigas saem ao destruir

        public:
            Formigueiro(sf::Vector2f posicao, int l);
            Formigueiro(sf::Vector2f posicao);
            ~Formigueiro();

            void setLargura(float l);
            float getLargura()const;
            void obstaculizar(Personagens::Personagem* p);
            void vibrar();
            void executar();
        };
    }
}