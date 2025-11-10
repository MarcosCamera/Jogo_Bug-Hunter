#include "Ente.hpp"
#include "Gerenciador_Grafico.hpp"
using namespace std;

int Ente::cont_id(0); //ta certa a inicialização aqui? Assim?
Gerenciadores::Gerenciador_Grafico* Ente::pGG(Gerenciadores::Gerenciador_Grafico::getInstancia());

Ente::Ente():id(cont_id++), pFig(new sf::Sprite()), pTex(new sf::Texture()) //new deve ser aqui mesmo? tex tem new tambem?
{
    //inicializar pFig e pTex como null e tratar em gerenciador grafico? 
    if (!spiderTex.loadFromFile("Textures/spider.png"))
        throw "nao abriu imagem";
    pFig->setTexture(spiderTex);
    //pFig->setScale(0.03, 0.03); //tratar em gerenciador grafico
    
}

Ente::~Ente() //pode isso, sendo ela virtual??? nao devia acontecer em classe nao abstrata???
{
    /*
    if (pFig)
    {
        delete pFig;
        pFig = NULL;
    }
    */ //o delete fica nas classes herdadas
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