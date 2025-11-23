#pragma once
#include "Personagem.hpp"
#include "Inimigo.hpp"
#include <cstdlib>
#include <ctime>
#include <list>

namespace Entidades
{
    namespace Personagens
    {
        class Jogador : public Personagem
        {
        protected:
            int pontos; 

        public:
            Jogador(sf::Vector2f posicao);
            ~Jogador();

            void danificarInim(Inimigo* pIn);
        
            void colidir(Inimigo* pIn);
            void controlar();
            void mover();
            void executar();
            void setPontos(int p);
            //json toJson();//salvamento

        };
    }
}
