#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.hpp"
#include "Formiga.hpp"
//#include "ListaEntidades.hpp"  // TODO: Arquivo não existe ainda
//#include "Fase.hpp"  // TODO: Arquivo não existe ainda
#include "Gerenciador_Grafico.hpp"


class Jogo{
   private:
    Gerenciadores::Gerenciador_Grafico* pGrafico;
    Entidades::Personagens::Jogador* j1;
    Entidades::Personagens::Formiga* i1;
    

   public:
     Jogo();
     ~Jogo();
     void executar();
};