#include "Jogo.hpp"
#include <iostream>

Jogo::Jogo(): pFaseAtual(NULL), pF1(NULL), //pF2(NULL),
              pGrafico(Gerenciador_Grafico::getInstancia()),
              pEventos(NULL)
{
    Ente::setpGG(pGrafico);
}

Jogo::~Jogo()
{
    if (pF1) delete pF1;
    //if (pF2) delete pF2;
    if (pEventos) delete pEventos;
}

void Jogo::executar()
{
    Gerenciadores::Gerenciador_Colisoes& refGC = *Gerenciadores::Gerenciador_Colisoes::getInstancia();
    pF1 = new Fases::Fase_Primeira(pGrafico, refGC, "../src/mapa2.json");
    pFaseAtual = pF1;
    
    if (pFaseAtual) {
        pEventos = new Gerenciador_Eventos(pFaseAtual->getListaEntidades(), &refGC);
            
        if (pFaseAtual->getJogador()) {
            pEventos->setJogador(pFaseAtual->getJogador());
            
             Gerenciador_Colisoes* pGC = Gerenciador_Colisoes::getInstancia();
             pGC->setJogador(pFaseAtual->getJogador());
            

        }
    }
    

    // Loop principal simples
    while (pGrafico->abertaJanela())
    {

        sf::Event event;
        while (pGrafico->getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed) return;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) return;
        }
        
        pGrafico->limparJanela();
        if (pEventos) pEventos->executar();
        if (pFaseAtual) pFaseAtual->executar();
        refGC.executar();
        pGrafico->mostrar();
    }
    
    pGrafico->fecharJanela();
}
