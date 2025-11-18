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
        public:
            Obstaculo();
            //Obstaculo(const std::string& caminhoSprite, sf::Vector2f posicao);
            virtual ~Obstaculo();

            virtual void obstaculizar(Personagens::Personagem* pE) = 0; //pode ser entidade??? no UML ta como jogador!!!
            virtual void executar() = 0;
        };
    }
}
