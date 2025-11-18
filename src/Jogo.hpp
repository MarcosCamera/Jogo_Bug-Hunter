#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.hpp"
#include "Inim_Facil.hpp"
#include "ListaEntidades.hpp"
#include "Fase.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Formigueiro.hpp"
#include "Plataforma.hpp"

using namespace Gerenciadores;
using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;

class Jogo{
   private:
    Fases::Fase* pF1;
    Gerenciador_Grafico* pGrafico;
    Gerenciador_Colisoes pColisoes;
    Fases::Fase* pFaseAtual;
    
    

   public:
     Jogo();
     ~Jogo();
     void executar();
};
