#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.hpp"
#include "Inimigo.hpp"
#include "ListaEntidades.hpp"
#include "Fase.hpp"


class Jogo{
   private:
    sf::RenderWindow window;
    Jogador *jogador1;
    ListaEntidades* LEs;
    Fase* fase1;
    

   public:
     Jogo();
     ~Jogo();

     void Executar();
};