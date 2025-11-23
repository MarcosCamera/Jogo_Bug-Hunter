#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.hpp"
#include "Formiga.hpp"
#include "ListaEntidades.hpp"
#include "Fase.hpp"
#include "Fase_Primeira.hpp"
#include "Fase_Segunda.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Formigueiro.hpp"
#include "Folha.hpp"

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
