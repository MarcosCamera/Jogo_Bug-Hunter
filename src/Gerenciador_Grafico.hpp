#pragma once
#include <SFML/Graphics.hpp>

class Ente;

namespace Gerenciadores
{
    class Gerenciador_Grafico{
    private:
       sf::Sprite fundo;
       static Gerenciador_Grafico* instancia;
       Gerenciador_Grafico();
       sf::RenderWindow * window;
       sf::Clock relogio; 
   


    public:
      
       ~Gerenciador_Grafico();
       void desenharEnte(Ente* pE);
       void limparJanela();
       void mostrar();
       bool abertaJanela();
       void fecharJanela();
       sf::RenderWindow* getWindow();
       static Gerenciador_Grafico* getInstancia();
      void desenharCenario();
      float getDeltaTime(); 

};
}
