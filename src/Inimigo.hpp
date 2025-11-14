#pragma once
#include "Personagem.hpp"
#include "Jogador.hpp"



namespace Entidades
{
    namespace Personagens
    {
        class Formiga;
        class Grilo;
        class LouvaDeus;
        class Inimigo : public Personagem
        {
        protected:
            int nivel_maldade;

        public:
            Inimigo();
            virtual ~Inimigo();
            void salvarDataBuffer(); //usar
            virtual void danificar(Jogador* p) = 0;
            virtual void mover() = 0;
            virtual void salvar() = 0;
            virtual void executar() = 0;
        };
    }
}