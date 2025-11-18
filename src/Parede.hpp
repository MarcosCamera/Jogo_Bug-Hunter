#pragma once
#include "Entidade.hpp"
#include "Jogador.hpp"

namespace Entidades
{
    class Parede : public Entidade
    {
    protected:
        //atributo?

    public:
        Parede();
        ~Parede();

        void obstaculizar(Personagens::Personagem* p);
        void executar();
    };
}
