#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.hpp"
#include "Inim_Facil.hpp"
#include "ListaEntidades.hpp"
#include "Fase.hpp"
#include "Gerenciador_Grafico.hpp"


class Jogo{
   private:
    Gerenciadores::Gerenciador_Grafico* pGrafico;
    Entidades::Personagens::Jogador* j1;
    Entidades::Personagens::Inim_Facil* i1;
    

   public:
     Jogo();
     ~Jogo();
     void executar();
};