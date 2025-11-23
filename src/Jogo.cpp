#include "Jogo.hpp"

using namespace std;


Jogo::Jogo():
    pGrafico(Gerenciadores::Gerenciador_Grafico::getInstancia()), 
    pColisoes(),      
    pF1(NULL),     
    pF2(NULL),
    pFaseAtual(NULL)
{
    Ente::setpGG(pGrafico);
    try {
        
        pF1 = new Fases::Fase_Primeira(pGrafico, pColisoes, "../mapa2.json"); //adaptavel
        pFaseAtual = pF1;
    }
    catch (const std::exception& e) {
        std::cerr << "ERRO CRITICO AO INICIAR JOGO: " << e.what() << std::endl;
        pFaseAtual = NULL;
    }
    

}

Jogo::~Jogo()
{
    
    if (pF1) {
        delete pF1;
        pF1 = NULL;
    }
    pFaseAtual = NULL;

}

void Jogo::executar()
{
            

    if (!pFaseAtual) 
    {
        std::cout << "Jogo::executar() -> nenhuma fase carregada" << std::endl;
        return;
    }

    while (pGrafico->abertaJanela())
    {
        
        sf::Event event;
        while (pGrafico->getWindow().pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pGrafico->fecharJanela();
        }
        
    
        pGrafico->limparJanela();
        
        pFaseAtual->executar(); 
    
        pColisoes.executar();
        
        pGrafico->mostrar();
    }
}
