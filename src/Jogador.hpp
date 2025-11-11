#pragma once
#include "Personagem.hpp"
#include <iostream>  //precisa desses includes que foram adicionados nas primitivas???
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <list>

namespace Entidades::Personagens
{
    class Jogador : public Personagem
    {
        protected:
            int pontos; //falta usar pontuação e morrer

        public:
            Jogador();
            ~Jogador();

            void danificarInim(Inimigo* pIn); 
            // fazer danificar estrutura, ou o danificar ser geral e usar sobrecarga ou cast?
            // danificar estrutura pelo projétil
            void colidir(Inimigo* pIn);
            void controlar();
            void mover();
            void executar();
            void salvar();
    };
}