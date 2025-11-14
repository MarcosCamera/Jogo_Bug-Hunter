#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entidade.hpp"

namespace Entidades 
{
    namespace Personagens
    {
        class Inimigo;
        class Jogador;
        class Personagem : public Entidade
        {
        protected:
            int num_vidas;
            int impacto;
            int timer; //para voltar a realizar alguma ação

        public:
            Personagem();
            virtual ~Personagem();

            void setVida(int f); //fazer como operator--
            int getVida()const;
            int getForca()const;

            virtual void mover() = 0;
            virtual void executar() = 0;
            virtual void salvar() = 0;
        };
    }
}