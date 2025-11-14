#include "Jogo.hpp"

Jogo::Jogo():j1(new Entidades::Personagens::Jogador()),
    i1(new Entidades::Personagens::Formiga()),
    pGrafico(Gerenciadores::Gerenciador_Grafico::getInstancia())
{
    
   executar();
}

Jogo::~Jogo()
{
    if (j1) {
        delete j1;
        j1 = nullptr;
    }
    if (i1) {
        delete i1;
        i1 = nullptr;
    }
   
}

void Jogo::executar()
{
    
    
    while (pGrafico->abertaJanela())
    {
        
        sf::Event event;
        while (pGrafico->getWindow().pollEvent(event))
        {
        
            if (event.type == sf::Event::Closed)
                pGrafico->fecharJanela();
        }
        
        if(i1 && j1){
        j1->executar();
        i1->executar();
        }

        pGrafico->limparJanela();
        if(i1 && j1){
        pGrafico->desenharEnte(j1);
        pGrafico->desenharEnte(i1);
        }
        
        pGrafico->mostrar();
    }
}