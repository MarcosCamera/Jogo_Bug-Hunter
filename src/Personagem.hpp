#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entidade.hpp"

namespace Entidades::Personagens
{
    class Inimigo;
    class Jogador;
    class Personagem : public Entidade
    {
        protected:
            int num_vidas;
            int forca;

        public:
            Personagem();
            virtual ~Personagem();

            void salvarDataBuffer(); //pra que serve???

            virtual void mover() = 0;
            virtual void executar() = 0;
            virtual void salvar() = 0;
    };
}