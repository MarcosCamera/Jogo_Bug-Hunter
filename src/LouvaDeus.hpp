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
                             // nivel de maldade varia com o timer
                             // aumenta dano e tamanho de projetil conforme diminui a vida
        public:
            LouvaDeus();
            ~LouvaDeus();

            void danificar(Jogador* pJog);
            void mover();
            void salvar();
            void executar();
        };
    }
}