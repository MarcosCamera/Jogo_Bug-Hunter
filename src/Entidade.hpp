#pragma once
#include <SFML/Graphics.hpp>
#include "Ente.hpp"



namespace Entidades{
class Entidade : public Ente{
   protected:
  sf::Vector2f pos;
  sf::Vector2f vel;
  sf::Vector2f acel;
  const float gravidade;
  float normal;
  const float arrasto;
  float velMovMax; 
  bool direcao; 
  bool chao; 
      

    public:

      Entidade(sf::Vector2f posicao);//sobrecarga construtora
      virtual ~Entidade();

      virtual void executar() = 0;
      virtual void mover() = 0;

      void setVel(sf::Vector2f velocidade);
      void setPos(sf::Vector2f novapos);
      sf::Vector2f getVel() const;
      sf::Vector2f getPos() const;

      void acelerar(); 
      void atualizaVel();
      void atualizaPos();

       void setChao(bool c);
       bool getChao() const;

      void mudaDir(); 
      bool getDir() const;
      void setDir(bool d);

    
      
  };
}
