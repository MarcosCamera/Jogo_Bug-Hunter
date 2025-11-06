#pragma once
#include <SFML/Graphics.hpp>

namespace Gerenciadores{
class Gerenciador_Grafico;
}


class Ente
{
    protected:
      int id;
      static Gerenciadores :: Gerenciador_Grafico* pGG;//da acesso a todas os entes ao mesmo gerenciador grafico
      static int  cont_id;//contar cada ente criado
      sf::Sprite* pFig; 
    public:
      Ente();
      virtual ~Ente();
      virtual void executar()=0;
      void desenhar();

      void static setpGG(Gerenciadores :: Gerenciador_Grafico* pG);
      sf::Sprite* getFigura();
      //void setCor(const sf::Color &cor);
      

};