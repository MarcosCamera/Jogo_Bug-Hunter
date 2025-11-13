#include "Obstaculo.hpp"
#include "Jogador.hpp"
#pragma once

namespace Entidades
{
    namespace Obstaculos
    {
        class Plataforma: public Obstaculo
        {
        protected:
            int altura;

        public:
            Plataforma();
            //Plataforma(const std::string& caminhoSprite, sf::Vector2f position);
            ~Plataforma();

            void obstaculizar(Personagens::Jogador* p);
            void salvar();
            void executar();
        };
    }
}
