#pragma once
#include "Personagem.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <list>

namespace Entidades::Personagens{
    class Jogador : public Personagem{
        protected:
            int pontos;

        public:
            Jogador();
            ~Jogador();

            /*tipo?*/ colidir(Inimigo* pIn);
            void executar();
            void salvar();
            void mover();
    


    };
}