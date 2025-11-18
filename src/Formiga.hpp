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
            float raio; //alcance do jogador para nivel de maldade. TRATAR EM COLISOES (???) ou em eventos...
                        //se estiver no raio de alcance, a velocidade altera
                        //e deixa de ser aleatoria para seguir o jogador
                        //pCabeca //a cabeça será separada do corpo e terá movimento próprio, seguindo o jogador.
                        //float velFuria; //será? 
            //Jogador* pJog //conhece jogador
            Jogador* pJog; //para que não seja necessário, gerenciador de eventos. Colocar a associação no UML

        public:
            Formiga(sf::Vector2f pos);
            Formiga(Jogador* pJog);
            ~Formiga();

            void setJogador(Jogador* pJ);
            void seguir(); //fazer formiga seguir jogadores a partir de algum gerenciador
            void verificaAlcance(Jogador* pJ);
            void danificar(Jogador* pJog);
            void mover();
            void executar();
        };
    }
}