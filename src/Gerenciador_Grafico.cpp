#include "Gerenciador_Grafico.hpp"
#include "Ente.hpp"

using namespace Gerenciadores;
using namespace Entidades;
Gerenciador_Grafico* Gerenciadores::Gerenciador_Grafico::instancia(NULL);


Gerenciador_Grafico::Gerenciador_Grafico():
window(sf::VideoMode(800, 608), "BUG - HUNTER", sf::Style::Default)
{
    
    window.setFramerateLimit(60); //ver testes.cpp como limite de fps, etc.
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

void Gerenciador_Grafico::moverCamera(sf::Text* t, Entidades::Entidade* p1, Entidades::Entidade* p2)
{

    sf::View view = window.getView();

    float larguraJanela = view.getSize().x;//largura da janela(800.0f, 608.0f)
    float larguraCenario = 1120.0f;//largura do mapa
    float centroX;
    float minCentro = larguraJanela / 2.f;
    float maxCentro = larguraCenario - larguraJanela / 2.f;


    if (p2 && p1) {//se há dois jogadores
        centroX = (p1->getPos().x + p2->getPos().x) / 2.f;

    }
    else if (p1) {
        centroX = p1->getPos().x;
    }
    else {//p2
        centroX = p2->getPos().x;
    }
     

    if (centroX < minCentro)
        centroX = minCentro;
    if (centroX > maxCentro)
        centroX = maxCentro;
    
   // std::cout << "Posicao camX: " << p1->getPos().x << "Posicao camY: " << p1->getPos().y << "\n";

    view.setCenter(sf::Vector2f(centroX, 206.25f));
    window.setView(view);
   // if(t)
      //  t->setPosition(camera.getCenter()-Vector2f(LARGURA_TELA/2 - 20.f,ALTURA_TELA/2 - 10.f)); // move o texto para acompanhar a câmera	
}



