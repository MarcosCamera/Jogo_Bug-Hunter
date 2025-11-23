#pragma once
#include "Entidade.hpp"
#include "Jogador.hpp"

namespace Entidades
{
    class Parede : public Entidade
    {
    protected:
     const float altura;

    public:
        Parede(sf::Vector2f posicao, int id_tile);
        ~Parede();

        void obstaculizar(Personagens::Personagem* p);
        void executar();
        const float getAltura();
        //json toJson();
    };
}
