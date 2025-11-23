#pragma once
#include "Inimigo.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class LouvaDeus : public Inimigo
        {
        private:
            short int forca; //depende de nivel_maldade
                             // aumenta dano e tamanho de projetil conforme diminui a vida
            short int voo;   //direcao do voo
        public:
            LouvaDeus();
            ~LouvaDeus();

            void danificar(Jogador* pJog);
            void atirar();
            void mover();
            void executar();
        };
    }
}