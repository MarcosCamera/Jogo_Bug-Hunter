#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.hpp"

namespace Entidades{
class Entidade : public Ente{
   protected:
      sf::Vector2f vel;
      sf::Vector2f pos;
      sf::Texture textura;

    public:
      Entidade();
      Entidade(const std::string& caminhoSprite, sf::Vector2f posicao);//sobrecarga construtora
      virtual ~Entidade();

      virtual void executar() = 0;
      void setVel(sf::Vector2f velocidade);
      void setPos(sf::Vector2f posicao);

      sf::Vector2f getVel() const;
      sf::Vector2f getPos() const;
      void colidirParede();
  };
}