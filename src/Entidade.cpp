#include "Entidade.hpp"
using namespace Entidades;

Entidade::Entidade():Ente(), vel(0.0f, 0.0f)
{

}

Entidade::~Entidade()
{

}

void Entidade::setVel(const float x, const float y)
{
   vel.x = x;
   vel.y = y;
}

void Entidade::setPos(const float x, const float y)
{
   if (pFig) {
      pFig->setPosition(x, y);
   }
}