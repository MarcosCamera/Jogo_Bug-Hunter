#include "Entidade.hpp"
#include <iostream>
using namespace std;
using namespace Entidades;

Entidade::Entidade():Ente(), vel(), pos(), textura()
{

}

Entidade::Entidade(const std::string& caminhoSprite, sf::Vector2f posicao) :Ente(), vel(), pos(), textura()
{
    
     if (!textura.loadFromFile(caminhoSprite))
    {
        cout << "não foi possivel carregar a sprite: " << caminhoSprite << endl;
    }

    if (this->pFig) { 
        pFig->setTexture(textura);
        //pFig->setOrigin(textura.getSize().x / 2.f, textura.getSize().y / 2.f);
    }

    
    
    setPos(posicao);
}

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

sf::Vector2f Entidade::getVel() const
{
    return vel;
}

sf::Vector2f Entidade::getPos() const
{
    return pos;
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
