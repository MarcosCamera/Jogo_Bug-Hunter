#include "Entidade.hpp"
#include <iostream>
using namespace std;
//using namespace Entidades; incorreto?
namespace Entidades 
{
    Entidade::Entidade() :
        Ente(), pos(0, 0), vel(0, 0), acel(0, 0), gravidade(0.5), arrasto(0.5), velMovMax(1), direcao(true), chao(false), normal(0)
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

    bool Entidade::getChao()const
    {
        return chao;
    }

    void Entidade::mudaDir()
    {
        direcao = !direcao;
    }

    bool Entidade::getDir()const
    {
        return direcao;
    }

    sf::Vector2f Entidade::getPos()const
    {
        return pos;
    }

    void Entidade::setPos(sf::Vector2f novaPos)
    {
        pos = novaPos;
        pFig->setPosition(novaPos);
    }

    sf::Vector2f Entidade::getVel()const
    {
        return vel;
    }
    void Entidade::setVel(sf::Vector2f novaVel)
    {
        vel = novaVel;
    }

    void Entidade::acelerar() //incluir todas acelerações
    {
        /*
        if (chao)
            normal = -gravidade;
        else
            normal = 0;*/

        acel.y = (gravidade * !chao); // -(normal * chao) - (vel.y * arrasto); //arrasto como 0 para teste
                                                                               //na finalização, nao usa chao, 
        /*                                                                     //a gravidade e normal se anulam.
        if (vel.x > velMovMax)                                              
            acel.x += - vel.x * arrasto;
        //acel.x com resistencia
        */
    }

    void Entidade::atualizaVel() //ou apenas vel = vel + acel; ?
    {
        if ((vel.x > 0 && direcao) || (vel.x < 0 && !direcao))
        {
            vel.x = 0;
            acel.x = 0;
        }

        vel += acel;
        if (chao)
        {
            vel.y = 0;
        }
        /*
        if (vel.x < velMovMax)
        {
            if (vel.x + acel.x > velMovMax) 
            {
                vel.x = velMovMax;
                vel.y += acel.y;
            }
            else
                vel.x += acel.x;
        }
        */
    }
    void Entidade::atualizaPos()
    {
        pos += vel; //aqui verifica colisoes
        pFig->setPosition(pos);
    }
}