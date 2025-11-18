#include "Gerenciador_Grafico.hpp"
#include "Ente.hpp"
#include <iostream>

using namespace std;

using namespace Gerenciadores;



Gerenciador_Grafico* Gerenciadores::Gerenciador_Grafico::instancia(NULL);



Gerenciador_Grafico::Gerenciador_Grafico():
window(new sf::RenderWindow(sf::VideoMode(800, 608), "Jogo"))
{
     
     fundo.scale(1.5f, 1.5f);
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
        window->draw(pE->getCorpo());
    }
    else
     cout<<"Gerenciador_Grafico::desenharEnte -> Ente*pE NULL"<<endl;
}


void Gerenciador_Grafico::limparJanela()
{
      window->clear(sf::Color::White);
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

void Gerenciadores::Gerenciador_Grafico::desenharCenario()
{

    if (window)
    {
        window->draw(fundo);
    }
    else
      cout<<"Gerenciador_Grafico::desenharCenario() -> window NULL"<<endl;
}

float Gerenciador_Grafico::getDeltaTime()
{
    
    return relogio.restart().asSeconds();
}
