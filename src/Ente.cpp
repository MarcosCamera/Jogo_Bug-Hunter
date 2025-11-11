#include "Ente.hpp"
#include "Gerenciador_Grafico.hpp"
using namespace std;

int Ente::cont_id(0);
Gerenciadores::Gerenciador_Grafico* Ente::pGG(Gerenciadores::Gerenciador_Grafico::getInstancia());

Ente::Ente() :id(cont_id++), pFig(new sf::Sprite()) //new deve ser aqui mesmo?
{
    std::string caminho = "Texturas/imagem" + std::to_string(id) + ".png";
    if (!text.loadFromFile(caminho))
        throw "nao abriu imagem";

    pFig->setTexture(text);
    pFig->setScale(0.03, 0.03); //tratar em gerenciador grafico
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