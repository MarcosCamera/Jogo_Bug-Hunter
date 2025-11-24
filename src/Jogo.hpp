#pragma once
#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.hpp"
#include "Gerenciador_Colisoes.hpp"

namespace Fases 
{ 
    class Fase;
}

class Jogo
{
private:
    Fases::Fase* pF1;
    Fases::Fase* pF2;
    Gerenciadores::Gerenciador_Grafico* pGrafico;
    Gerenciadores::Gerenciador_Colisoes pColisoes;
    Fases::Fase* pFaseAtual;

public:
    Jogo();
    ~Jogo();
    void executar();
};
