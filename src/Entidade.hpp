#pragma once
#include <SFML/Graphics.hpp>
#include "Ente.hpp"
#include <fstream> 
#include "nlohmann/json.hpp" 


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
   
     bool remover;//marca para quando precisa remover 
         

    public:

      Entidade(sf::Vector2f posicao);
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

      bool getRemover() const { return remover; }
      void setRemover(bool r) { remover = r; }

    
      
  };
}

