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
            void setMaldade(int m);
            int getMaldade();
            void operator++();  //nivel_maldade++
            void operator--();  //nivel_maldade--

            virtual void danificar(Jogador* p) = 0;
            virtual void mover() = 0;
            virtual void executar() = 0;
        };
    }
}