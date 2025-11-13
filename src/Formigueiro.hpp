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
        protected:
            float largura; //largura diz quantas formigas saem ao destruir

        public:
            Formigueiro();
            //Formigueiro(const std::string& caminhoSprite, sf::Vector2f posicao);
            ~Formigueiro();

            void setLargura(float l);
            float getLargura();
            void obstaculizar(Personagens::Jogador* p);
            void executar();
        };
    }
}