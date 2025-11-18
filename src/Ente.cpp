#include "Ente.hpp"
#include "Gerenciador_Grafico.hpp"
#include <iostream>
using namespace std;

int Ente::cont_id(0);
Gerenciadores::Gerenciador_Grafico* Ente::pGG(Gerenciadores::Gerenciador_Grafico::getInstancia());

Ente::Ente():id(cont_id++), corpo((sf::Vector2f(200.f, 200.f)))

{

}

Ente::~Ente()
{
   

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

sf::RectangleShape& Ente::getCorpo() 
{ 
    return corpo; 
}


// Em Ente.cpp
void Ente::setTexture(string caminho)
{   if (!text.loadFromFile(caminho))
        throw std::runtime_error("erro ao carregar imagem: " + caminho); 
    else
       corpo.setTexture(&text);

 
}
