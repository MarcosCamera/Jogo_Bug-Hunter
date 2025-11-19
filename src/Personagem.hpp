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
            int timer; //para voltar a realizar alguma ação. //fazer static e função estatica em algum lugar
            bool disparar;

        public:
            Personagem();
            virtual ~Personagem();

            //quicar ~bounce
            //empurrao ~knockback

            void perdeVida(int i); //fazer como operator-- ?
            int getVida()const;
            int getImpacto()const;
            void setDisparo(bool d);
            bool getDisparo()const;

            virtual void mover() = 0;
            virtual void executar() = 0;
        };
    }
}