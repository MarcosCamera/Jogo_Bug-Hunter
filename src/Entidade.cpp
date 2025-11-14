#include "Entidade.hpp"
#include <iostream>
using namespace std;
//using namespace Entidades; incorreto?
namespace Entidades 
{
    Entidade::Entidade() :
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

    void Entidade::setChao(bool c)
    {
        chao = c;
    }

    bool Entidade::getChao()
    {
        return chao;
    }

    sf::Vector2f Entidade::getPos()const
    {
        return pos;
    }

    void Entidade::setPos(sf::Vector2f novaPos)
    {
        pos = novaPos;
    }

    void Entidade::acelerar() //incluir todas acelerações
    {
        acel.y = (gravidade * !chao) - (normal * chao) - (vel.y * arrasto);
        
        if (vel.x > velMovMax)
            acel.x = - vel.x * arrasto;
        //acel.x com resistencia
    }

    void Entidade::atualizaVel() //ou apenas vel = vel + acel; ?
    {
        if (vel.x < velMovMax)
        {
            if (vel.x + acel.x > velMovMax) {
                vel.x = velMovMax;
                vel.y += acel.y;
            }
            else
                vel += acel;
        }
    }
}