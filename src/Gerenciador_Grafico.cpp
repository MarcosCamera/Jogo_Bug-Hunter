#include "Gerenciador_Grafico.hpp"
#include "Ente.hpp"

using namespace Gerenciadores;



Gerenciador_Grafico* Gerenciadores::Gerenciador_Grafico::instancia(NULL);



Gerenciador_Grafico::Gerenciador_Grafico():
window(new sf::RenderWindow(sf::VideoMode(800.0f, 800.0f), "Jogo"))
{
    
}


Gerenciador_Grafico::~Gerenciador_Grafico()
{
     if(window)
     {
        delete(window);
        window = nullptr;
     }
}


void Gerenciador_Grafico::desenharEnte(::Ente* pE)
{
    if (pE) {
       if(pE->getFigura())
        window->draw(*pE->getFigura());
    }
}


void Gerenciador_Grafico::limparJanela()
{
      window->clear(sf::Color::Black);
}


void Gerenciador_Grafico::mostrar()
{
    window->display();
}


bool Gerenciador_Grafico::abertaJanela()
{
    return window->isOpen();
}


void Gerenciador_Grafico::fecharJanela()
{
    window->close();
}


sf::RenderWindow* Gerenciador_Grafico::getWindow()
{
    return window;
}
//estático
Gerenciador_Grafico* Gerenciadores::Gerenciador_Grafico::getInstancia()
{
    if(instancia == NULL)
    {
        instancia = new Gerenciador_Grafico();
    }
    return instancia;
}