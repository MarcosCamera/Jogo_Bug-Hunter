#pragma once
#include "Inimigo.hpp"
#include "SFML/Graphics.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class Grilo : public Inimigo
        {
        private:
            int tamanhoSalto; //depende de nivel_maldade
            //nivel_maldade aumenta se danificar jogador  
        public:
            Grilo();
            Grilo(sf::Vector2f posicao);
            ~Grilo();

            void danificar(Jogador* pJog);
            void mover();
            void executar();
        };
    }
}