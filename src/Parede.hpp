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
        Parede();
        ~Parede();

        void obstaculizar(Entidades::Entidade* p);
        void executar();
    };
}
