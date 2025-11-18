#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.hpp"

namespace Entidades{
class Entidade : public Ente{
   protected:
      bool chao;
      sf::Vector2f vel;
       sf::Vector2f acel;
       bool direcao;
      const float gravidade;
      const float velMovMax;
      const float arrasto;
      float normal;
      

    public:

      Entidade(sf::Vector2f posicao);
      virtual ~Entidade();

      virtual void executar() = 0;
      void setVel(sf::Vector2f velocidade);
      

      sf::Vector2f getVel() const;
      sf::Vector2f getPos() const;
      void acelerar(); 
      void atualizaVel();

       void setChao(bool c);
      
  };
}
