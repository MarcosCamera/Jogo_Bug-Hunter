#pragma once
#include <SFML/Graphics.hpp>

class Ente;

namespace Gerenciadores
{
    class Gerenciador_Grafico
    {
    private:
        static Gerenciador_Grafico* instancia;
        sf::RenderWindow window;
        //lista de texturas para cada entidade?

    public:
        Gerenciador_Grafico();    
        ~Gerenciador_Grafico();
        sf::RenderWindow& getWindow();
        static Gerenciador_Grafico* getInstancia();
        void mostrar();
        void limparJanela();
        bool abertaJanela();
        void fecharJanela();
        void desenharEnte(Ente* pE);
    };
}

