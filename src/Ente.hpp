#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.hpp"

class Entidade;
class Fase;
class Menu;

class Ente
{
    protected:
  
      static int  cont_id;
      int id;
      static Gerenciadores::Gerenciador_Grafico* pGG; //da acesso a todos os entes ao mesmo gerenciador grafico
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