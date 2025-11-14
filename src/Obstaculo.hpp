#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entidade.hpp"
#include "Jogador.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Plataforma;
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

            virtual void obstaculizar(Entidade* pE) = 0; //pode ser entidade???
            virtual void executar() = 0;
            virtual void salvar() = 0;
            //virtual void setDano(bool dano) = 0; por que seria necessário?
            //virtual bool getDano() = 0;
        };
    }
}
