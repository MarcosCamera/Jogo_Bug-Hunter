#pragma once
#include "Personagem.hpp"
#include "Inimigo.hpp"
#include <iostream>  
#include <SFML/Graphics.hpp>
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
            int pontos; //falta usar pontuação e morrer

        public:
            Jogador();
            Jogador(sf::Vector2f posicao);
            ~Jogador();

            void danificarInim(Inimigo* pIn);
            void colidir(Inimigo* pIn);
            void operator++(); //pontuação++
            void controlar(char tecla);
            void mover();
            void executar();
        };
    }
}