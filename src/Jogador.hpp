#pragma once
#include "Personagem.hpp"
#include "Inimigo.hpp"
#include <iostream>  //precisa desses includes que foram adicionados nas primitivas???
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
            int pontos; 

        public:
            Jogador(sf::Vector2f posicao);
            ~Jogador();

            void danificarInim(Inimigo* pIn);
            void colidir(Inimigo* pIn);

            void operator++();
            void controlar(char tecla);
            void mover();
            void executar();
        
            //json toJson();//salvamento

        };
    }
}
