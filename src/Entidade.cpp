#include "Entidade.hpp"
#include <iostream>
using namespace std;
using namespace Entidades;

Entidade::Entidade():
Ente(), pos(0, 0), vel(0, 0), acel(0, 0), gravidade(10), arrasto(1), velMovMax(10), direcao(true), chao(false)
{

}

/*Entidade::Entidade(const std::string& caminhoSprite, sf::Vector2f posicao) :
Ente(), pos(0,0), vel(0,0), acel(0,0), gravidade(10), arrasto(), direcao(true), chao(false)
{
    
     if (!textura.loadFromFile(caminhoSprite))
    {
        cout << "não foi possivel carregar a sprite: " << caminhoSprite << endl;
    }

    if (pFig)
    { 
        pFig->setTexture(textura);
    }
    
    setPos(posicao);
}*/

Entidade::~Entidade()
{
}

void Entidade::setVel(sf::Vector2f velocidade)
{
   vel = velocidade;
}

void Entidade::setPos(sf::Vector2f posicao)
{
   pos = posicao;

   if (pFig) {
      pFig->setPosition(pos);
   }
   else
    cout<<"Entidade::setPos(posicao) -> pFig NULO"<<endl;
}

void Entidade::colidirParede()
{
    sf::Vector2f posFinal = getPos();
    sf::FloatRect bounds = getGlobalBounds(); 

    const float LARGURA_JANELA = 800.0f;
    const float ALTURA_JANELA = 800.0f;
    
    if (bounds.left < 0.0f)
    {
        posFinal.x -= bounds.left; 
    }
    else if (bounds.left + bounds.width > LARGURA_JANELA)
    {
        posFinal.x = LARGURA_JANELA - bounds.width; 
    }
    

    if (bounds.top < 0.0f)
    {
        posFinal.y -= bounds.top;
    }
    else if (bounds.top + bounds.height > ALTURA_JANELA)
    {
        posFinal.y = ALTURA_JANELA - bounds.height;
    }
    setPos(posFinal);
}


void Entidade::acelerar() //incluir todas acelerações
{
        acel.y = (gravidade * !chao) - vel * arrasto; // -vel * vel * arrasto * area //ou apenas largura * largura 
                                      //talvez use so atributo arrasto como um numero conveniente para desacelerar
        if(vel > velMovMax)
            acel.x = - vel * arrasto;
            //acel.x com resistencia e nao com um numero aleatório
}

void Entidade::atualizaVel()
{
    if (vel < velMovMax)
    {
        if (vel + acel > velMovMax)
            vel = velMovMax;
        else
            vel += acel;
    }
}