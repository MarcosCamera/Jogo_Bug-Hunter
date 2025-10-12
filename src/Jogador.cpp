#include "Jogador.hpp"

Jogador::Jogador(){}
Jogador::~Jogador(){}

void Jogador::move(){
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
    body.move(sf::Vector2f(0.1f, 0.f));}
}