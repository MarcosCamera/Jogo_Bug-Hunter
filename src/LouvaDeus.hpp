#pragma once
#include "Inimigo.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class LouvaDeus : public Inimigo
        {
        private:
            short int forca;    
            bool voo;   
        public:
            LouvaDeus();
            ~LouvaDeus();
            // LouvaDeus(sf::Vector2f(posicao));

            void danificar(Jogador* pJog);
            void atirar();
            void mover();
            void atualizaMaldade();
            void executar();
            
        };
    }
}
