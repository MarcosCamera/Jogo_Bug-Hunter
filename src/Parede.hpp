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
        Parede();
        Parede(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f), int id_tile = 0);
        ~Parede();

        void obstaculizar(Personagens::Personagem* p);
        void executar();
        const float getAltura();
        void mover();
    
    };
}
