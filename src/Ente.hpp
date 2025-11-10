#pragma once
#include <SFML/Graphics.hpp>

namespace Gerenciadores{
class Gerenciador_Grafico;
}


class Ente
{
    protected:
  
      static int  cont_id; //contar cada ente criado. deve estar antes de id?(ordem de inicialização na construtora)
      int id;
      static Gerenciadores :: Gerenciador_Grafico* pGG; //da acesso a todas os entes ao mesmo gerenciador grafico
      sf::Sprite* pFig; 
      sf::Texture* pTex; //textura aqui? //ou crio tex em gerenciador grafico e trato pFig?

    public:
      Ente();
      virtual ~Ente();
      virtual void executar()=0;
      void desenhar();

      void static setpGG(Gerenciadores :: Gerenciador_Grafico* pG);
};