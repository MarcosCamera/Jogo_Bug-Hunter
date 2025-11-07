#pragma once
#include <SFML/Graphics.hpp>

class Ente;

namespace Gerenciadores
{
    class Gerenciador_Grafico
    {
    private:
        static Gerenciador_Grafico* instancia;
        sf::RenderWindow* window;

    public:
        /*tratar textura de cada instancia aqui*/
        Gerenciador_Grafico();    
        ~Gerenciador_Grafico();
        void desenharEnte(Ente* pE);
        void limparJanela();
        void mostrar();
        bool abertaJanela();
        void fecharJanela();
        static sf::RenderWindow* getWindow();
        static Gerenciador_Grafico* getInstancia();
        //criar executar para limpar, desenhar e mostrar. nesse caso, pE (Ente) é uma lista
    };
}