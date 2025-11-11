#include "Gerenciador_Grafico.hpp"
#include "Ente.hpp"

using namespace Gerenciadores;


Gerenciador_Grafico* Gerenciadores::Gerenciador_Grafico::instancia(NULL);


Gerenciador_Grafico::Gerenciador_Grafico():
window(sf::RenderWindow(sf::VideoMode(800, 800), "BUG - HUNTER", sf::Style::Default))
{
    window.setFramerateLimit(60); //ver testes.cpp como limite de fps, etc.
}


Gerenciador_Grafico::~Gerenciador_Grafico()
{
     
}


static sf::RenderWindow Gerenciador_Grafico::getWindow()
{
    return window;
}


Gerenciador_Grafico* Gerenciadores::Gerenciador_Grafico::getInstancia()
{
    if(instancia == NULL)
    {
        instancia = new Gerenciador_Grafico();
    }
    return instancia;
}


void Gerenciador_Grafico::mostrar()
{
    window->display();
}


void Gerenciador_Grafico::limparJanela()
{
      window->clear(sf::Color::Black);
}


bool Gerenciador_Grafico::abertaJanela()
{
    return window->isOpen();
}


void Gerenciador_Grafico::fecharJanela()
{
    window->close();
}


void Gerenciador_Grafico::desenharEnte(Ente* pE)
{
    if (pE) 
    {
        if(pE->getFigura())
            window->draw(*(pE->pFig));
    }
}