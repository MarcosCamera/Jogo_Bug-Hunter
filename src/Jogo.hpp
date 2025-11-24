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

#include "Menu.hpp"
#include "MenuPausa.hpp" 
#include "MenuInicial.hpp"

#include "Fase_Primeira.hpp"
#include "Fase_Segunda.hpp"

using namespace Gerenciadores;
using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;

class Jogo{
   private:
    Fases::Fase* pFaseAtual;
    Fases::Fase_Primeira* pF1;
    Fases::Fase_Segunda* pF2;
    
    Gerenciador_Grafico* pGrafico;
    Gerenciador_Eventos* pEventos;
    Gerenciador_Colisoes pColisoes;
    

    MenuInicial menuInicial;
    MenuPausa menuPausa;
    int estadoDoJogo; //(0==menu, 1==jogo, 2==sair)
    
    

   public:
     Jogo();
     ~Jogo();
     void executar();
};
