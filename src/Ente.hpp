#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.hpp"

/*namespace Gerenciadores
{
    class Gerenciador_Grafico;
}*/

class Entidade;
class Fase;
class Menu;

class Ente
{
    protected:
  
      static int  cont_id; //contar cada ente criado. deve estar antes de id?(ordem de inicialização na construtora)
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
      virtual void executar()=0;
};