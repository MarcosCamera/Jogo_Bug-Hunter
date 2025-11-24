#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class Entidade;
class Fase;
class Menu;

namespace Gerenciadores{
class Gerenciador_Grafico;
}

class Ente
{
    protected:
  
      static int  cont_id; 
      int id;
      static Gerenciadores::Gerenciador_Grafico* pGG; 
      sf::Sprite* pFig; 
      sf::Texture text;


    public:
      Ente();
      virtual ~Ente();

      sf::Sprite* getFig();
      void setTexture(std::string caminho, sf::Vector2f scale);
      void desenhar();
      void static setpGG(Gerenciadores :: Gerenciador_Grafico* pG);
      static int getContId();
      virtual void executar()=0;
};
