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
            int pontos;

        public:
            Jogador();
            ~Jogador();

            void danificarInim(Inimigo* pIn); 
            // fazer danificar estrutura, ou o danificar ser geral e usar sobrecarga ou cast?
            void colidir(Inimigo* pIn);
            void controlar();
            void mover();
            void salvar();
            void executar();
    };
}

//fazer classe jogador 1 e classe jogador 2 (ou aranha e escorpião)
//usar sprite de aranaha que levanta pernas dianteiras ao saltar.
//aranha 2 salto horizontal no botao atirar
//aranha 1 atira teia
//fase 2: aranha 1 voa, aranha 2 anda na parede