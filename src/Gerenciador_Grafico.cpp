#include "Gerenciador_Grafico.hpp"
#include "Ente.hpp"

using namespace Gerenciadores;
using namespace Entidades;
using namespace sf;
Gerenciador_Grafico* Gerenciadores::Gerenciador_Grafico::instancia(NULL);


Gerenciador_Grafico::Gerenciador_Grafico():
window(sf::VideoMode(800, 512), "BUG - HUNTER", sf::Style::Default)
{
    
    window.setFramerateLimit(60); //ver testes.cpp como limite de fps, etc.
    camera.setSize(window.getSize().x, window.getSize().y);
    camera.setCenter(camera.getSize().x / 2, camera.getSize().y / 2);
    window.setView(camera);
}


Gerenciador_Grafico::~Gerenciador_Grafico()
{
     
}


sf::RenderWindow& Gerenciadores::Gerenciador_Grafico::getWindow()
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
    window.display();
}


void Gerenciador_Grafico::limparJanela()
{
      window.clear(sf::Color::Black);
}


bool Gerenciador_Grafico::abertaJanela()
{
    return window.isOpen();
}


void Gerenciador_Grafico::fecharJanela()
{
    window.close();
}


void Gerenciador_Grafico::desenharEnte(Ente* pE)
{
    if (pE) 
    {
        if(pE->getFig())
            window.draw(*(pE->getFig()));
    }
}

void Gerenciadores::Gerenciador_Grafico::moverCamera(Entidades::Entidade* p1, Entidades::Entidade* p2)
{
        float larguraJanela = camera.getSize().x;
		float larguraCenario = 32000.0f;

		float centroX = 0;
		if (p2 && p1) {
			centroX = (p1->getFig()->getPosition().x+ p2->getFig()->getPosition().x) / 2.f;
		}
		else if (p1) {
			centroX = p1->getFig()->getPosition().x;		}
		else {//p2
			centroX = p2->getFig()->getPosition().x;
		}

		float minCentro = larguraJanela / 2.f;
		float maxCentro = larguraCenario - larguraJanela / 2.f;

		if (centroX < minCentro)
			centroX = minCentro;
		if (centroX > maxCentro)
			centroX = maxCentro;

		camera.setCenter(Vector2f(centroX, 512.0f/ 2.f));
		window.setView(camera);
}



