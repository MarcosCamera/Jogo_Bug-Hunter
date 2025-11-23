#pragma once
#include "Entidade.hpp"
#include "Jogador.hpp"

namespace Entidades
{
    class Parede : public Entidade
    {
    protected:
        bool colidiu; //a textura muda se houver colisão qualquer.

    public:
        Parede(sf::Vector2f posicao, int id_tile);        
        ~Parede();

        void obstaculizar(Entidades::Entidade* p);
        void mover();
        void executar();
    };
}
