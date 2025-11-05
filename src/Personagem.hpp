#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entidade.hpp"

namespace Entidades::Personagens{
    class Personagem : public Entidade{
        protected:
            int num_vidas;
        public:
            Personagem();
            virtual ~Personagem();

            void salvarDataBuffer();

            virtual void executar() = 0;
            virtual void salvar() = 0;
            virtual void mover() = 0;
    };
}