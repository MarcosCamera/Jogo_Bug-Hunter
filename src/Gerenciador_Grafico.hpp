#pragma once
#include <SFML/Graphics.hpp>

class Ente;

namespace Gerenciadores
{
    class Gerenciador_Grafico{
    private:
       static Gerenciador_Grafico* instancia;
       Gerenciador_Grafico();
       sf::RenderWindow * window;

    public:
      
       ~Gerenciador_Grafico();
       void desenharEnte(Ente* pE);
       void limparJanela();
       void mostrar();
       bool abertaJanela();
       void fecharJanela();
       sf::RenderWindow* getWindow();
       static Gerenciador_Grafico* getInstancia();
};
}