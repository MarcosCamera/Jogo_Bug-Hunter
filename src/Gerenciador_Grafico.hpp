#pragma once
#include <SFML/Graphics.hpp>
#include "Entidade.hpp"


class Ente;

namespace Gerenciadores
{
    class Gerenciador_Grafico
    {
    private:
        static Gerenciador_Grafico* instancia;
        sf::RenderWindow window;

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
        void moverCamera(sf::Text* t, Entidades::Entidade* p1, Entidades::Entidade* p2);

        //criar executar para limpar, desenhar e mostrar. nesse caso, pE (Ente) é uma lista
    };
}

