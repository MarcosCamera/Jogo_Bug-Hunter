#pragma once
#include "Personagem.hpp"
#include "Jogador.hpp"



namespace Entidades::Personagens{
    class Inimigo : public Personagem{
        protected:
            int nivel_maldade;

        public:
            Inimigo();
            virtual ~Inimigo();
            void salvarDataBuffer();
            virtual void danificar(Jogador* p) = 0;
            virtual void mover() = 0;
            virtual void salva() = 0;
            virtual void executar() = 0;
    };
}