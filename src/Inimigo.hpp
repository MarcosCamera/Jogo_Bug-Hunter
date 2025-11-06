#pragma once
#include "Personagem.hpp"
#include "Jogador.hpp"



namespace Entidades::Personagens{
    class Inimigo : public Personagem{
        protected:
            int nivel_maldade;
            bool alcanceJogador; //se estiver no raio de alcance, a velocidade altera
                                 //e deixa de ser aleatoria para seguir o jogador

        public:
            Inimigo();
            virtual ~Inimigo();
            void salvarDataBuffer();
            virtual void executar() = 0;
            virtual void mover() = 0;
            virtual void danificar(Jogador* p) = 0;
    };
}

//inimigo formiga tem nivel de maldade maior e portanto maior dano, se proximo ao formigueiro
//aumenta o nivel se nao houver formigas por perto (printar na tela: berserk mode)
