#pragma once
#include "Inimigo.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class LouvaDeus : public Inimigo
        {
        private:
            short int forca; //depende de nivel_maldade //velocidade de disparo
                             // aumenta dano e tamanho de projetil conforme diminui a vida
            bool voo;   //direcao do voo
        public:
            LouvaDeus();
            LouvaDeus(sf::Vector2f(posicao));
            ~LouvaDeus();

            void danificar(Jogador* pJog);
            void atirar();
            void mover();
            void atualizaMaldade();
            void executar();
        };
    }
}