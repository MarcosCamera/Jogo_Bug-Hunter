#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.hpp"

namespace Entidades{
class Entidade : public Ente{
   protected://classe totalmente abstrata usa protected, para poder acessar body
      sf::Vector2f vel;
      
    public:
    Entidade();
     virtual ~Entidade();
     virtual void executar() = 0;
     void setVel(const float x, const float y);//pode ser utilizado MRU
     void setPos(const float x, const float y);
     
};
}