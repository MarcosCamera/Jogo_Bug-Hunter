#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.hpp"
#include "Grilo.hpp"
#include "Formiga.hpp"
#include "ListaEntidades.hpp"
#include "Fase.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Formigueiro.hpp"
#include "Folha.hpp"
#include "Gerenciador_Eventos.hpp"

#include "Fase_Primeira.hpp"
#include "Fase_Segunda.hpp"

using namespace Gerenciadores;
using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;

class Jogo{
   private:
    Fases::Fase* pFaseAtual;
    Fases::Fase_Primeira* pF1;
    //Fases::Fase_Segunda* pF2;
    
    Gerenciador_Grafico* pGrafico;
    Gerenciador_Eventos* pEventos;
    
    
   public:
     Jogo();
     ~Jogo();
     void executar();
};
