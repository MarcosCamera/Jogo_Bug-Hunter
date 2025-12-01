#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entidade.hpp"



namespace Listas { class ListaEntidades; }
namespace Entidades 
{
    namespace Personagens
    {
        class Inimigo;
        class Jogador;
        class Personagem : public Entidade
        {
        protected:
            int num_vidas;
            int impacto;
            int timer; 
            bool disparar;

            Listas::ListaEntidades* lista_projeteis;
            

        public:
            Personagem();
            Personagem(sf::Vector2f pos,Listas::ListaEntidades* p = NULL);
            virtual ~Personagem();
            void setVidas(int vidas);
            int getVidas()const;
            void perdeVida(int i); 
            
            int getImpacto()const;
            void setDisparo(bool d);
            bool getDisparo()const;


            virtual void mover() = 0;
            virtual void executar() = 0;
            

        };
    }
}
