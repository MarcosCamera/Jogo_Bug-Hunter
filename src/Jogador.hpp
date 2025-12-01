#pragma once
#include "ListaEntidades.hpp"
#include "Personagem.hpp"
#include "Teia.hpp"
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
            float cooldownTiro;
            float tempoCooldown;
            bool tiro;

        public:
            Jogador();
            Jogador(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f), Listas::ListaEntidades* p = NULL);
            ~Jogador();

            void danificarInim(Inimigo* pIn);
            void colidir(Inimigo* pIn);

            void operator++();
            void controlar(char tecla);
            void mover();
            void executar();

            Entidades::Teia* atirarTeia();
            void setAtirar(bool t);
            bool getAtirar();
        };
    }
}
