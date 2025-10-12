#pragma once

#include <SFML/Graphics.hpp>


class Entidade{
   protected://classe totalmente abstrata usa protected, para poder acessar body
      sf :: RectangleShape body;
      sf::RenderWindow *window;
    public:
      Entidade():body(sf::Vector2f(100.f, 100.f)){}
      ~Entidade(){}
      void setWindow(sf::RenderWindow* window) {this->window = window;}
      void draw(){window->draw(body);}
      
};