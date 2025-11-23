#pragma once
#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Gerenciador_Grafico.hpp"
#include <cmath>

namespace Entidades
{
    namespace Personagens
    {
        class Formiga : public Inimigo
        {
        private:
            float raio; //se estiver no raio de alcance, ela segue
            static int numeroFormigas;

        public:
            Formiga(sf::Vector2f pos);
            ~Formiga();

            float getRaio();
            static void setNumeroFormigas(int n);
            static int getNumeroFormigas();
            void seguir(Jogador* pJ); //fazer formiga seguir jogadores a partir de algum gerenciador
            float verificaAlcance(Jogador* pJ);
            void danificar(Jogador* pJog);
            void mover();
            void executar();
        };
    }
}