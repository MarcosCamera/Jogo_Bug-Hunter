#include "Ente.hpp"
#include "Gerenciador_Grafico.hpp"
#include <iostream>
using namespace std;

int Ente::cont_id(0);
Gerenciadores::Gerenciador_Grafico* Ente::pGG(Gerenciadores::Gerenciador_Grafico::getInstancia());

Ente::Ente():id(cont_id++), pFig(new sf::Sprite())
{
    
}

Ente::~Ente() //pode isso, sendo ela virtual??? nao devia acontecer em classe nao abstrata???
{
    if(pFig)
    {
        delete pFig;
        pFig = NULL;
    }

}

void Ente::desenhar()
{
    if(pGG)
      pGG->desenharEnte(this);
    else
       cout<<"pGG NULL"<<endl;
}


void  Ente::setpGG(Gerenciadores::Gerenciador_Grafico* pG)
{
    pGG = pG;
}

sf::Sprite* Ente::getFigura() 
{ 
    return pFig; 
}

/*void Ente::setCor(const sf:: Color &cor)
{
    if(pFig)
      pFig->setFillColor(cor);
    else
     cout<<"pFig NULL"<<endl;
}*/