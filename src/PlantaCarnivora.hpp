#pragma once
#include "Obstaculo.hpp"
#include "Personagem.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class PlantaCarnivora : public Obstaculo
        {
        private:
            short int danosidade;
            short int orientacao; // esquerda(-1), cima(0) (padrão), direita(1)

        public:
            PlantaCarnivora();
            PlantaCarnivora(sf::Vector2f posicao);
            ~PlantaCarnivora();

            void obstaculizar(Personagens::Personagem* p);
            void danificarPersonagem(Personagens::Personagem* p);
            void esbarrar(short int ori);
            void delay();
            void executar();
        };
    }
}
