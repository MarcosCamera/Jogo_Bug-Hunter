#pragma once
#include "Jogador.hpp"
#include "Inimigo.hpp"
#include "ListaEntidades.hpp"
#include <SFML/Graphics.hpp>
class Fase{
   private:
      ListaEntidades* listaEntidades;
      Inimigo* i1;
      Jogador* j1;

      sf::RenderWindow* window;
      void inicializaElementos();
   public:
       Fase(Jogador* j,sf::RenderWindow* window);
       ~Fase();
       
       ListaEntidades* getListaEntidades(){return listaEntidades;}
       

};