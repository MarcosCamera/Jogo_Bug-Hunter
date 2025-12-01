#pragma once
#include "Projetil.hpp"
#include "Entidade.hpp"

namespace Entidades {
    
        class Teia : public Projetil 
        {
        private:
            float tempoVida;
            float tempoAtual;
            bool atingiuInimigo;
            
        public:
            Teia();
            Teia(sf::Vector2f pos);
            ~Teia();
            
            void executar();
            void danificarPersonagem(Personagens::Personagem* pVitima);
            void mover(); 
            bool getAtingiuInimigo() const { return atingiuInimigo; }
        };
    
}