#pragma once

#include "Obstaculo.hpp"
#include "Jogador.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Formigueiro: public Obstaculo
        {
        private:
            float largura; 
            bool ativo;
            static int numeroFormigueiros;

        public:
            Formigueiro(sf::Vector2f posicao);//aqui eu mudei
            Formigueiro();//aqui eu mudei
            ~Formigueiro();

            static void setNumeroFormigueiros(int n);
            static int getNumeroFormigueiros();
            void setLargura(float l);
            float getLargura()const;
            bool getAtividade()const;
            void obstaculizar(Personagens::Personagem* p);
            void vibrar();
            void mover();
            void executar();
        };
    }
}
