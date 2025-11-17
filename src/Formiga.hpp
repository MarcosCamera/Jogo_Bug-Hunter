#pragma once
#include "Inimigo.hpp"

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
            Jogador* pJog1; //para que não seja necessário, gerenciador de eventos. Colocar a associação no UML

        public:
            Formiga(Jogador* pJ);
            ~Formiga();

            void seguir(Jogador* pJog);
            void verificaAlcance(Jogador* pJog);
            void danificar(Jogador* pJog);
            void mover();
            void salvar();
            void executar();
        };
    }
}